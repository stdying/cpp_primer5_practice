//
// Created by admin on 2022/1/26.
//

#include "chapter13.h"
HasPtr &HasPtr::operator=(const HasPtr &rhs) {
  //拷贝底层string
  auto newP = new std::string(*rhs.ps);
  //释放旧内存
  delete ps;
  ps = newP;
  i = rhs.i;
  //返回本对象
  return *this;
}
