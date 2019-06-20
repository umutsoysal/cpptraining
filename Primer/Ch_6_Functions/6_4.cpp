// A function which keeps a static value for future callings.

#include <iostream>

int foo() {
  static int cnt = 0;
  return ++cnt;
}

int main(){

    std::cout<<"The first calling of the function " << foo()<<std::endl;
    std::cout<<"The second calling of the function " << foo()<<std::endl;
 
    return 0;
}
