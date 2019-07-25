/* Copyright 2016 The MathWorks, Inc. */
#ifndef SL_FEATURE_SLF_FEATURE_DEF_HPP_
#define SL_FEATURE_SLF_FEATURE_DEF_HPP_

/* -----------------------------------------------------------------------------
 * SlFeature infrastructure description:
 * -----------------------------------------------------------------------------
 * The SlFeature infrastructure is a replacement for the MATLAB feature
 * infrastructure at the Simulink platform level. The primary motivation
 * for this replacement was performance. We desire constant-time lookup
 * of feature values both in internal source code and in M-code to 
 * avoid performance problems during the introduction of a feature.
 *
 * Additional requirements satisfied by this infrastructure include:
 *
 * - Minimal recompilation when a new feature in introduced and used
 * - Ensure features are transient in that they get cleaned up once the
 *   capability they are isolating is truly ON in the product. This
 *   is ensured by requiring that each feature be registerd with a 
 *   trackable geck that promises a time-frame for when this feature 
 *   will be removed for source code.
 * - Prevent uses of feature as a lazy-man approach to adding a new 
 *   built-in to Simulink. Note that a new slInternal infrastructure
 *   was added to address this use-case
 *
 *  
 * Steps to registering and using SlFeatures:
 * ==========================================
 * For full details on functions and macros referenced in the following steps,
 * please scroll down to their abstracts in this file.
 *
 *    1. Pre-work for registering/using SlFeature:
 *       -----------------------------------------
 *       To register or use features defined using the new SlFeature
 *       infrastructure, you need to 'sl_feature/slf_feature_def.hpp' to its MODULE_DEPENDENCIES
 *    
 *    2. Registering a new feature:
 *       --------------------------
 *       o You can do register the feature in any file in your module
 *       o Add '#include sl_feature/slf_feature_def.hpp' at the top of the file that registers a 
 *        new feature.
 *       o Use the macro 'SLF_RegisterFeature(..., scope)' to register
 *         a new feature. 
 *         The value you should use for 'scope' is as follows:
 *         scope can be one of:
 *                SLF_IN_MODULE      : When registering a feature to be used
 *                                     inside a single module
 *                SLF_EXPORTED       : When registering a feature to be in
 *                                     more than one module (exported)
 *
 *
 *    3. Querying a feature in internal C++ source code:
 *       -----------------------------------------------
 *       Querying a feature value in C++ source code is guaranteed to 
 *       be constant time complexity. 
 * 
 *       o To query the value of a feature in a C++ file:
 *         - Add '#include sl_feature/slf_feature_def.hpp' at the top of the file that
 *           is going to query the feature
 *
 *         - Use the macro 'SLF_UseFeature(fName,scope) to declare
 *           that you are going to use the feature in a file. The rationale
 *           behind this additional line is two-fold: (a) every programmer
 *           should know what symbols they are choosing to include in a file
 *           following the STL/GNU include paramdigm, and (b) this line ensures
 *           only files that register and use a given feature are compiled.
 *           The value you should use for 'scope' is as follows:
 *                SLF_IN_MODULE  : When using a non-exported feature
 *                SLF_EXPORTED   : When using an exported feature inside
 *                                 the module in which it is registered
 *                SLF_IMPORTED   : When using an exported feature inside
 *                                 a module different from the one in which
 *                                 it is registered
 * 
 *         - Use the macro 'slGetFeatureValue(FNAME)' to query the actual
 *           feature value in your source code.
 *
 *    4. CAVEATS to querying feature value in source code:
 *       -------------------------------------------------
 *       - DO NOT query feature state in static initialization. 
 *         Behavior may be unpredictable.
 *         This same restriction applied even to the old infrastructure
 *         and has not been relaxed in SlFeature.
 *
 *    5. Querying a feature in M code:
 *       -----------------------------
 *       The query of a feature name from M is 'average constant time'.
 *       Yet, you should avoid using repeated queries in tight loops
 *       to avoid performance problems. 
 *            
 *       - You should use the M-command 'SlFeature' to query both
 *         features registered using the old infrastructure and the 
 *         ones registered in the new infrastructure.
 *       - For features registered using the old infrastructure, 
 *         you can use SlFeature only with old features in the Simulink
 *         module. E.g. SlFeature will not work with the non-Simulink
 *         feature 'JavaFigures'.
 *
 *    6. Deprecated uses of old feature infrastructure:
 *       ----------------------------------------------
 *       - You cannot register features which are pseudo-builtins any more
 *         like you may have done with the old SlFeature infrastructure
 *         (e.g. sldebug). You need to migrate these to a new 'hidden' Simulink 
 *         builtin called 'slInternal'. Please see the file 
 *         'src/simulink/sl_cmds/sl_internal.cpp' for how to add
 *         new options to 'slInternal'.
 * -----------------------------------------------------------------------------
 */

/*
 * Definition of class for declaring and using SlFeature
 */
#include <iostream>
#include "sl_feature_spec.hpp"
#include "fl/diag/terminate.hpp"
#include "matrix/matrix_fwd.hpp"
#include "services/state/feature.hpp"

 /* Typedef for callback of a feature */
typedef void(*SlFeaturePostSetCallback)(int);

/* Class: SlFeature =======================================================
 * Abstract:
 *   Class that helps register new SlFeatures in source code. Do not use
 *   directly. Call 'SL_REG_SlFeature'.
 */
class SlFeature final {
  public:
    SL_FEATURE_EXPORT_FCN SlFeature(const char* featName,
              const char               *featDesc,
              const char               *featOwnerFile,
              const char               *featOwner,
              int                      featGeck,
              int                      featVal,
              SlFeaturePostSetCallback featCB);
    SL_FEATURE_EXPORT_FCN ~SlFeature();

    /* Declaration of friends */
    friend class SlFeatureTable;
    friend class SlFeatureMatlGateway;
    friend void  SL_FEATURE_EXPORT_FCN SlFeatureGateway(int     nlhs,
                                                        mxArray *plhs[],
                                                        int     nrhs,
                                                        mxArray *prhs[]);
    friend int  slGetFeatureValueFcn(const SlFeature *fEnt);
    friend void slSetFeatureValueFcn(SlFeature *fEnt,int       fVal);

  private:
    // Feature name
    const char *fName;

    // Feature description
    const char *fDesc;
    
    // Feature owner file name
    const char *fOwnerFile;

    // Feature owner
    const char *fOwner;

    // Feature geck number
    int        fGeckNum;

    // Feature value
    int        fVal;

    // Feature default value
    int fDefaultVal;
    
    // Feature post-set callback
    SlFeaturePostSetCallback fCB;

    // Stats
    mutable int fNAccessFromC;
    mutable int fNGetsFromM;
    mutable int fNSetsFromM;

    // Get feature value for internal code
    int getFeatValFromC() const {
        fNAccessFromC++;
        return(fVal);
    }

    // Get feature value for M
    int getFeatValFromM() const {
        fNGetsFromM++;
        return(fVal);
    }

    // Set feature value (runs post-set callback)
    void setFeatValFromM(int newVal) {
        fNSetsFromM++;
        fVal = newVal;
        if (fCB != NULL) {
            (*fCB)(newVal);
        }
    }

    // Set feature value from C (runs post-set callback)
    void setFeatValFromC(int newVal) {
        fVal = newVal;
        if (fCB) {
            (*fCB)(newVal);
        }
    }
};

/* Function: slGetFeatureValueFcn ==============================================
 * Abstract:
 *   Function that provides fast access to a feature value from a feature.
 *   Do not call directly. Use macro 'slGetFeatureValue'.
 */
inline int slGetFeatureValueFcn(const SlFeature *fEnt)
{
    FL_DIAG_ASSERT_MSG(fEnt != NULL,
                "Accessing value of invalid feature. Are you "
                "accessing the value from static initialization code? "
                "Feature values cannot be deteministically accessed "
                "in this manner.");
    return(fEnt->getFeatValFromC());
}

/* Function: slSetFeatureValueFcn ==============================================
 * Abstract:
 *   Function that provides fast access to set a feature value from a feature.
 *   Do not call directly. Use macro 'slSetFeatureValue'.
 */
inline void slSetFeatureValueFcn(SlFeature *fEnt,
                                 int       fVal) 
{
    return(fEnt->setFeatValFromC(fVal));
}

// Feature scope definitions to be used in conjunction with
// registration and usage
#define SLF_IN_MODULE extern
#define SLF_EXPORTED  extern DLL_EXPORT_SYM
#define SLF_IMPORTED  IMPORT_VAR

/* Macro for registering an SlFeature:
 * -----------------------------------------------------------------------------
 * Usage: 
 *     SLF_RegisterFeature(fName, fDesc, fOwner, fGeck, fVal, fCB, slfScope)
 * Fields:
 *     fName       : Name of feature (Do NOT put quotes around name)
 *     fDesc       : Description of feature (const char *)
 *     fOwner      : Gecko component that owns feature (const char *)
 *     fGeck       : Geck number that promises to deprecate feature in the
 *                   future (int)
 *     fVal        : Default value of feature (int)
 *     fCB         : Feature callback (function pointer)
 *     slfScope can be one of:
 *                SLF_IN_MODULE  : When registering a feature to be used
 *                                 inside a single module
 *                SLF_EXPORTED   : When registering a feature to be in
 *                                 more than one module (exported)
 * Example:
 *     SLF_RegisterFeature(GenericPropagation,
 *                     "Variable size signal support: "
 *                     "Activates propagation of variable size attribute "
 *                     "for signals and is used to dynamically change "
 *                     "signal sizes during simulation.", 
 *                     "Simulink Engine [Signal Dimensions]",
 *                     345678, 1, NULL, extern)
 * Note:
 *     Manually include 'sl_feature/slf_feature_def.hpp' at the top of the file in which you 
 *     declare the feature
 */
#define SLF_RegisterFeature(fName, fDesc, fOwner, fGeck, fVal, fCB, slfScope)   \
    static SlFeature SLFEAT_ ## fName ## _var(#fName, fDesc, __FILE__, fOwner,  \
                                              fGeck, fVal, fCB);                \
    slfScope SlFeature *SLFEAT_ ## fName;                                       \
    SlFeature *SLFEAT_##fName = &SLFEAT_ ## fName ## _var



/* Macro for using an SlFeature in your CPP file:
 * -----------------------------------------------------------------------------
 * Usage: 
 *     SLF_UseFeature(fName,slfScope)
 * Fields:
 *     fName                 : Name of feature (Do NOT put quotes around name)
 *     slfScope can be one of:
 *                SLF_IN_MODULE  : When using a non-exported feature
 *                SLF_EXPORTED   : When using an exported feature inside
 *                                 the module in which it is registered
 *                SLF_IMPORTED   : When using an exported feature inside
 *                                 a module different from the one in which
 *                                 it is registered
 * Example:
 *     SLF_UseFeature(GenericPropagation, extern)
 *
 * Note:
 *     Manually include 'sl_feature/slf_feature_def.hpp' at the top of the file in which you 
 *     use the feature
 */
#define SLF_UseFeature(fName,slfScope)  \
    slfScope SlFeature *SLFEAT_ ## fName;       \
    std::cout<<"TEST USEFEATURE"<<std::endl;


/* Macro for querying the value of a feature in CPP code:
 * -----------------------------------------------------------------------------
 * Usage:
 *     slGetFeatureValue(fName)
 * Fields:
 *     fName : Name of feature (Do NOT put quotes around name)
 *
 * Example:
 *     int a = slGetFeatureValue(GenericPropagation);
 *
 * Note:  
 *    This macro should never be utilized in static initialization because the
 *    underlying feature may as yet not have been created. Features are created
 *    during static initialization.
 */
#define slGetFeatureValue(fName) slGetFeatureValueFcn(SLFEAT_ ## fName)

/* Macro for setting a feature value from C-code
 * -----------------------------------------------------------------------------
 * Usage:
 *     slSetFeatureValue(fName, fVal)
 * Fields:
 *     fName : Name of feature (Do NOT put quotes around name)
 *     fVal  : Feature val
 * 
 * Note: 
 *     This macro should be rarely used. One valid use-case is within a unit 
 *     test
 */
#define slSetFeatureValue(fName,fVal) \
    slSetFeatureValueFcn(SLFEAT_ ## fName, fVal)

SL_FEATURE_EXPORT_FCN void SlFeatureGateway(int     nlhs,
                                            mxArray *plhs[],
                                            int     nrhs,
                                            mxArray *prhs[]);

SL_FEATURE_EXPORT_FCN void slfMatlFeature(int     nlhs,
                                          mxArray *plhs[],
                                          int     nrhs,
                                          mxArray *prhs[]);

// Function: slfReleaseSlFeatureMatlGateway =====================================
// Abstract:
//   Release memory pertaining to the feature table on Simulink exit.
//
SL_FEATURE_EXPORT_FCN void slfReleaseSlFeatureMatlGateway();

// Function: slfRegServicesFeature ==============================================
// Abstract:
//   Track a feature registered with 'services'
//
SL_FEATURE_EXPORT_FCN void slfRegServicesFeature_DoNotUseAnymore
                            (
                             const char       *name,
                             int              value,
                             FeatureCallback  callback,
                             FeatureBuiltin   builtin
                             );

#endif // SL_FEATURE_SLF_FEATURE_DEF_HPP_

/* [EOF] SlFeature.h */

