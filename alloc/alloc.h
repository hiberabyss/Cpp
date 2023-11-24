/**
 * Copyright (c) 2021, Soul Inc
 * Author: Hongbo Liu <liulu3@soulapp.com>
 * Date  : 2021-11-02 22:43:10
 */

#include <iostream>

class Alloc {
public:
  Alloc () {}
  ~Alloc () {}

  void* allocate(size_t n) {
    if (free_header_ == nullptr) {
      Node* p = (Node*)malloc(kChunk * n);
      free_header_ = p;

      for (size_t i = 1; i < kChunk; ++i) {
        p->next = (Node*)((char*)p + n);
        p = p->next;
      }
      p->next = nullptr;
    }

    auto* res = free_header_;
    free_header_ = free_header_->next;
    return res;
  }

  void deallocate(void* p, size_t n) {
    if (p == nullptr) {
      return;
    }

    ((Node*)p)->next = free_header_;
    free_header_ = (Node*)p;
  }

private:
  struct Node {
    Node* next = nullptr;
  };

private:
  const size_t kChunk = 8;
  Node* free_header_ = nullptr;
};
