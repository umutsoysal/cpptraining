
// Function flags usage example

#include <iostream>
#include <vector>


using namespace std;

#define IS_BIT_SET(uword32, bit) ((uword32 & bit) != 0)

struct MyFlags{
    enum Value{
        EVEN                           =0x01,
        ODD                            = 0x02,
        ANOTHER_FLAG                   = 0x04,
        YET_ANOTHER_FLAG               = 0x08,
        SOMETHING_ELSE                 = 0x10,
        SOMETHING_COMPLETELY_DIFFERENT = 0x20
    };
};

int CreateNum(int flags){
    if (flags &MyFlags::EVEN){
            //do something...
        cout<<"Flag is even"<<endl;
    }
    if (flags &MyFlags::ODD){
            //do something...
        cout<<"Flag is odd"<<endl;
    }
    if (flags &MyFlags::ANOTHER_FLAG){
            //do something...
        cout<<"Flag is another flag"<<endl;
    }
    if (flags &MyFlags::SOMETHING_ELSE){
            //do something...
        cout<<"Flag is something else"<<endl;
    }
    
    return 1;
}

int main(){

    cout<<"Flags example"<<endl;

    int answer;

    answer|=(MyFlags::EVEN| MyFlags::ODD);
    
    CreateNum(MyFlags::EVEN | MyFlags:: ODD);

    CreateNum(MyFlags::EVEN & MyFlags:: SOMETHING_ELSE);

    if (IS_BIT_SET(answer, MyFlags:: ANOTHER_FLAG)){
            cout<<"Bit is set!"<<endl;
    }else
    {
        cout<<"Bit is not set"<<endl;
    }

   
    return 0;
}

        
