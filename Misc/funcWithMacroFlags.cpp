
// Function flags usage example

#include <iostream>
#include <vector>


using namespace std;

#define IS_BIT_SET(uword32, bit) ((uword32 & bit) != 0)


#define        EVEN                            0x01
#define        ODD                             0x02
#define        ANOTHER_FLAG                    0x04
#define        YET_ANOTHER_FLAG                0x08
#define        SOMETHING_ELSE                  0x10
#define        SOMETHING_COMPLETELY_DIFFERENT  0x20

int CreateNum(int flags){
    if (flags & EVEN){
            //do something...
        cout<<"Flag is even"<<endl;
    }
    if (flags & ODD){
            //do something...
        cout<<"Flag is odd"<<endl;
    }
    if (flags &ANOTHER_FLAG){
            //do something...
        cout<<"Flag is another flag"<<endl;
    }
    if (flags & SOMETHING_ELSE){
            //do something...
        cout<<"Flag is something else"<<endl;
    }
    
    return 1;
}

int main(){

    cout<<"Flags example"<<endl;

    int answer;

    answer|=(EVEN| ODD);
    
    CreateNum(EVEN | ODD);

    CreateNum(EVEN & SOMETHING_ELSE);

    if (IS_BIT_SET(answer, ANOTHER_FLAG)){
            cout<<"Bit is set!"<<endl;
    }else
    {
        cout<<"Bit is not set"<<endl;
    }
 
    return 0;
}

        
