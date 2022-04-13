//
// Created by admin on 2022/3/4.
//

#include <iostream>
#include "StrVec.h"
void StrVec::push_back(const std::string &s) {
  std::cout << "StrVec::push_back copy" << std::endl;
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string &&s) {
  std::cout << "StrVec::push_back move" << std::endl;
  chk_n_alloc();
  alloc.construct(first_free++, std::move(s));
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}
void StrVec::free() {
  if (elements) {
	for (auto p = first_free; p != elements;)
	  alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements);
  }
}
StrVec::StrVec(const StrVec &s) {
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}
StrVec::~StrVec() {
  free();
}
StrVec &StrVec::operator=(const StrVec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}
void StrVec::reallocate() {
  auto newcapcity = size() ? 2 * size() : 1;
  //分配新内存
  auto newdata = alloc.allocate(newcapcity);
  //将数据从旧内存移送到新内存
  auto dest = newdata;  //指向新数组中下一个空闲位置
  auto elem = elements; //指向旧数组中下一个元素
  for (size_t i = 0; i != size(); ++i) {
	alloc.construct(dest++, std::move(*elem++));
  }
  free();
  elements = newdata;
  first_free = dest;
  cap = elements + newcapcity;
}
StrVec::StrVec(StrVec &&s) noexcept
//成员初始化器接管s中的资源
	: elements(s.elements), first_free(s.first_free), cap(s.cap) {
  s.elements = s.first_free = s.cap = nullptr;
}
StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
  if (this != &rhs) {
	free();                  //释放已有资源
	elements = rhs.elements; //从rhs接管资源
	first_free = rhs.first_free;
	cap = rhs.cap;
	//将rhs置于可析构状态
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }
  return *this;
}
