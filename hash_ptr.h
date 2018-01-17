#ifndef HASH_PTR_H
#define HASH_PTR_H

#include "picosha2.h"

#include <cstdlib>
#include <vector>

using std::memcpy;

template<typename T>
class hash_ptr {
public:

  explicit hash_ptr(T* pointee) : pointee_{pointee} {
    // TODO compute the hash

    // 1. Convert the pointee data to a vector of bytes
    // 1a. Allocate buffer for bytes (must free)
    unsigned char *pointee_bytes = new unsigned char[sizeof(T)];
    
    // 1b. use memcpy to convert bytes from pointee type to unsigned char[].
    memcpy(pointee_bytes, pointee, sizeof(T));
    
    // 2. Compute hash of bytes
    picosha2::hash256(pointee_bytes, pointee_bytes + sizeof(T),
		      hash_, hash_ + 32);

    // 3. Cleanup 1a.
    delete[] pointee_bytes;
    

  }    

  hash_ptr& operator=(const hash_ptr& other) {
    this->pointee_ = other.pointee_;
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

    // compute the hash of the pointee's current data
    unsigned char candidate_hash[32];
    unsigned char *candidate_bytes = new unsigned char[sizeof(T)];
    memcpy(candidate_bytes, pointee_, sizeof(T));
    picosha2::hash256(candidate_bytes, candidate_bytes + sizeof(T),
		      candidate_hash, candidate_hash + 32);    
    delete[] candidate_bytes;
    
    // compare to the stored hash
    for (int i = 0; i < 32; ++i) {
      if (hash_[i] != candidate_hash[i]) {
	return false;
      }
    }
    
    return true;
  };

private:

  T* pointee_;
  unsigned char hash_[32];
  
};

#endif // HASH_PTR_H
