#include <iostream>
#include "hash_ptr.h"

int main() {

  int *x = new int{5};

  hash_ptr<int> p{x};

  std::cout << "Hash pointer points to: " << *p << std::endl;
  std::cout << "Result of valid() = " << p.valid() << std::endl;
  std::cout << "Changing data from " << *p << " to 6." << std::endl;
  *p = 6;
  std::cout << "Result of valid() is now: " << p.valid() << std::endl;
  
}
