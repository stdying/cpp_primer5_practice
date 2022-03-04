//
// Created by admin on 2022/1/26.
//

#ifndef CPP_PRACTICE_SRC_CHAPTER13_CHAPTER13_H_
#define CPP_PRACTICE_SRC_CHAPTER13_CHAPTER13_H_
#include <string>
class HasPtr {
  friend void swap(HasPtr &, HasPtr &);
 public:
  HasPtr(const std::string &s = std::string()) :
	  ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

  //拷贝构造函数拷贝所有三个数据成员，并递增计数器
  HasPtr(const HasPtr &p) :
	  ps(p.ps), i(p.i), use(p.use) { ++*use; }

  HasPtr &operator=(const HasPtr &);

  ~HasPtr() {
	if (--*use == 0) {
	  //释放string内存
	  delete ps;
	  //释放计数器内存
	  delete use;
	}
  }

 private:
  std::string *ps;
  int i;
  //用来记录有多少对象共享*ps的成员
  std::size_t *use;
};
inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}

#endif //CPP_PRACTICE_SRC_CHAPTER13_CHAPTER13_H_
