// This script takes grades as inputs and cluster them to 11 classes 11th class is for the students who take 100 points. Inputs should be between 0 and 100

#include <iostream>
#include <vector>

int main() {
  std::vector<unsigned> scores(11, 0);
  unsigned grade;
  while (std::cin >> grade)
    ++*(scores.begin() + grade / 10);
  for (const auto & elem : scores)
    std::cout << elem << ' ';
  std::cout << std::endl;

  return 0;
}
