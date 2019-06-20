
//read two sales item object with Same ISBN and produces their sum

#include <iostream>
#include "Sales_item.h"

int main() {
  Sales_item item1, item2;
  std::cin >> item1 >> item2;
  std::cout << item1 + item2 << std::endl;

  return 0;
}