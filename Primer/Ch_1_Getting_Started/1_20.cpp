
// Uses Sales_item.h class and reads a number of 


#include <iostream>
#include "Sales_item.h"

int main() {
  Sales_item item;
  while (std::cin >> item)  // read ISBN, number of copies sold, and sales price
    std::cout << item << std::endl; //write number of copies sold, total revenue, average price

  return 0;
}