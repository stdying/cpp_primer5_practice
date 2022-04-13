//
// Created by admin on 2022/3/4.
//

#ifndef CPP_PRACTICE_SRC_STRVEC_H_
#define CPP_PRACTICE_SRC_STRVEC_H_
#include <memory>
#include <string>

class StrVec
{
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &);
  StrVec &operator=(const StrVec &);
  StrVec(StrVec &&) noexcept;
  StrVec &operator=(StrVec &&) noexcept;
  ~StrVec();
  void push_back(const std::string &);
  void push_back(std::string &&);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }

private:
  std::allocator<std::string> alloc;
  void chk_n_alloc()
  {
    if (size() == capacity())
      reallocate();
  }
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
  void free();
  void reallocate();

  std::string *elements;   //指向数组首元素的指针
  std::string *first_free; //指向数组第一个空闲元素的指针
  std::string *cap;        //指向数组尾后位置的指针
};

#endif // CPP_PRACTICE_SRC_STRVEC_H_
