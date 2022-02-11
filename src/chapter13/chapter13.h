//
// Created by admin on 2022/1/26.
//

#ifndef CPP_PRACTICE_SRC_CHAPTER13_CHAPTER13_H_
#define CPP_PRACTICE_SRC_CHAPTER13_CHAPTER13_H_
#include <string>
class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()) :
	  ps(new std::string(s)), i(0) {}

  //对ps指向的string，每个HasPtr对象都有自己的拷贝
  HasPtr(const HasPtr &p) :
	  ps(new std::string(*p.ps)), i(p.i) {}
  HasPtr &operator=(const HasPtr &);
  ~HasPtr() { delete ps; }

 private:
  std::string *ps;
  int i;
};

#endif //CPP_PRACTICE_SRC_CHAPTER13_CHAPTER13_H_
