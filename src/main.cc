#include <iostream>
#include "chapter2/chapter2.h"
#include "chapter3/chapter3.h"
#include "chapter6/chapter6.h"
#include "chapter7/chapter7.h"
#include "chapter8/chapter8.h"
#include "StrVec.h"

void test_rvalue() {
  int i = 42;
  int &r = i;
  //错误 不能讲一个右值引用绑定到一个左值
  //  int &&rr = i;
  //错误，i*42是一个右值
  //  int &r2 = i*42;
  const int &r3 = i * 42; //可以将一个const的引用绑定到一个
  int &&rr2 = i * 42;     //将rr2绑定到乘法结果上
}

void test_test_rvalue() {
  StrVec vec;
  std::string s = "some string or another";
  vec.push_back(s);
  vec.push_back("done");

}

int main() {
  std::cout << "Hello, world!\n";

  int a = 10;
  int a2 = 20;
  int &b = a;
  b = a2;

  std::cout << a << std::endl;

//  fun_print();
  // print_chapter3();
//  fun1(1);

//  invoke_chapter7();
//  invoke_chapter8();
  test_test_rvalue();

}