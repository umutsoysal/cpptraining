// Compile and execute the bookstore program presented in this section

#include <iostream>
#include "Sales_item.h"

int main() {
  Sales_item total;  // create an instance
  if (std::cin >> total) { //read the first item and enter loop
    Sales_item trans;  // create a second item 
    while (std::cin >> trans) { // read the second item 
      if (total.isbn() == trans.isbn())  // if they are equal enter two 
        total += trans;  
      else {
        std::cout << total << std::endl; // print the total 
        total = trans;
      }
    }
    std::cout << total << std::endl;
  } else {
    std::cerr << "No data!" << std::endl;
    return -1;
  }
  return 0;
}