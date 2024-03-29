// Rewrite of the E6_10 with using references instead of pointers

#include <iostream>

void swapInt(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  swapInt(a, b);
  std::cout << a << " " << b << std::endl;

  return 0;
}
