
#ifndef DUMMY_FEATURE_DEF_HPP_
#define DUMMY_FEATURE_DEF_HPP_

#include <iostream>


class dummyFeature final{

  public:
    const char* featName;
    int featGeck;
  private:
    const char *fName;
    int fGeckNum;
    
};


#define Dummy_UseFeature(fName)\
    dummyFeature *DFEAT_##fName;                \
    std::cout<<DFEAT_##fName<<std::endl;        \
    



#define Dummy_RegisterFeature(fName , fGeck )\
    static dummyFeature DFEAT_##fName##_var(#fName,fGeck);\
    dummyFeature *DFEAT_##fName=&DFEAT_##fName##_var


#endif 
