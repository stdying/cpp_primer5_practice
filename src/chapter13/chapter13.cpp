//
// Created by admin on 2022/1/26.
//

#include "chapter13.h"
HasPtr &HasPtr::operator=(const HasPtr &rhs) {
  //递增右侧运算对象的引用计数
  ++*rhs.use;
  //递减本对象引用计数
  if (--*use == 0) {
	delete ps;
	delete use;
  }
  ps = rhs.ps;
  i = rhs.i;
  use = rhs.use;
  return *this;
}
