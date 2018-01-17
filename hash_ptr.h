#ifndef HASH_PTR_H
#define HASH_PTR_H

#include "picosha2.h"

// TODO include for serialization

template<typename T>
class hash_ptr {
public:

  explicit hash_ptr(T* pointee) : pointee_{pointee} {

  }    

  hash_ptr& operator=(const hash_ptr& other) {
    // TODO
  };

  ~hash_ptr() {
    // TODO
  }

  T& operator*() const {
    return *pointee_;
  }

  T* operator->() const {
    return pointee_;
  }

  bool valid() const {
    // TODO
    return false;
  };

private:

  T* pointee_;

  // todo member for hash
  

};

#endif // HASH_PTR_H
