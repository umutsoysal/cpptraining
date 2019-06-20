// 3 different version to print elements of an multidimensional array

#include <iostream>



int main() {
    
  constexpr size_t c_row = 3;
  constexpr size_t c_col = 4;
  int ia[c_row][c_col] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11}
  };

  // Using range for, best method
  for (auto  &row : ia) {
    for (auto &col : row)
      std::cout << col << '\t';
    std::cout << std::endl;
  }



  // 2nd method, standard subscripting like a matrix
  for (size_t i = 0; i != c_row; ++i) {
    for (size_t j = 0; j != c_col; ++j)
      std::cout << ia[i][j] << '\t';
    std::cout << std::endl;
  }

  //Using pointers, more complicated
  for (int (*pr)[c_col] = ia; pr != ia + c_row; ++pr) {
    for (int *pc = *pr; pc != *pr + c_col; ++pc)
      std::cout << *pc << '\t';
    std::cout << std::endl;
  }

  return 0;
}
