#include <iostream>
#include "hash_ptr.h"

int main() {

  int *x = new int{5};

  hash_ptr<int> p{x};

  std::cout << *p << std::endl;

}
