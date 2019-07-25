#include <iostream>

using namespace  std;

enum week{ Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

int main()
{

    week today;
    today= Wednesday;
    cout<<"Day " << today+7;
    return 0;
}
