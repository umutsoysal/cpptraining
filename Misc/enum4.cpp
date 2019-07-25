

#include <iostream>

struct MyFlags{
    enum Value{
        EVEN                           = 0x01,
        ODD                            = 0x02,
        ANOTHER_FLAG                   = 0x04,
        YET_ANOTHER_FLAG               = 0x08,
        SOMETHING_ELSE                 = 0x10,
        SOMETHING_COMPLETELY_DIFFERENT = 0x20
    };
};

int CreateNum(MyFlags::Value flags){
    if (flags & MyFlags::EVEN){
        // do something...
    }
}

int  main(){
    CreateNum((MyFlags::Value)(MyFlags::EVEN | MyFlags::ODD));
    return 0;
}
