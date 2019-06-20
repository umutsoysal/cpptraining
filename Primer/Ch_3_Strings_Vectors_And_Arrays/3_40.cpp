
// Strcpy and strcat

#include <iostream>
#include <cstring> // Old C library

int main() {
  char s1[] = "Hello";
  char s2[] = "World";
  char s3[11];
  strcpy(s3, s1); // Copy s1 to S3; 
  strcat(s3, s2); // Add s2 to S3
  std::cout << s3 << std::endl;

  return 0;
}
