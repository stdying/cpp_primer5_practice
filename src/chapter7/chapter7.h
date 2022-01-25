#ifndef CHAPTER_7
#define CHAPTER_7

#include <string>
#include <iostream>
#include<vector>

class Sales_data {
  //Sales_data 的非成员函数所做的友元函数
  friend Sales_data add(const Sales_data &, const Sales_data &);

  friend std::istream &read(std::istream &, Sales_data &);

  friend std::ostream &print(std::ostream &, const Sales_data &);

 public:
//  Sales_data() = default;
  Sales_data(std::string s, unsigned cnt, double price) :
	  bookNo(s), units_sold(cnt), revenue(cnt * price) {
	std::cout << "Sales_data(std::string s, unsigned cnt, double price)" << std::endl;
  }

  Sales_data() : Sales_data("", 0, 0) {
	std::cout << "Sales_data()" << std::endl;
  }

  //抑制构造函数定义的隐士转换
  explicit Sales_data(std::string s) : Sales_data(s, 0, 0) {
	std::cout << "Sales_data(std::string s)" << std::endl;
  }

  virtual ~Sales_data();

//  Sales_data(const std::string &s) : bookNo(s) {}

//  Sales_data(std::string s = "") : bookNo(s) {}

  explicit Sales_data(std::istream &is) : Sales_data() {
	read(is, *this);
  }

  std::string isbn() const {
	return bookNo;
  }

  Sales_data &combine(const Sales_data &);

  double avg_price() const;

 private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

//Sales_data接口的非成员组成部分的声明
Sales_data add(const Sales_data &, const Sales_data &);

std::ostream &print(std::ostream &os, const Sales_data &item);

std::istream &read(std::istream &is, Sales_data &item);

class Screen;

class Window_mgr {
 public:
  using ScreenIndex = std::vector<Screen>::size_type;

  void clear(ScreenIndex index);

  ScreenIndex addScreen(const Screen &);

 private:
  //std::vector<Screen> screens{ Screen(24,80,' ') };
  std::vector<Screen> screens;
};

extern std::ostream &storeOn(std::ostream &, Screen &);
//extern BitMap & storeOn(BitMap&, Screen&);

class Screen {
  //Window_mgr的成员可以访问Screen类的私有部分
  //friend class Window_mgr;
  friend void Window_mgr::clear(ScreenIndex index);

 public:
  using pos = std::string::size_type;

  Screen() = default;

  Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {
  }

  Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {
  }

  //隐士内联
  char get() const {
	return contents[cursor];
  }

  //显示内敛
  inline char get(pos ht, pos wd) const;

  Screen &move(pos r, pos c);

  void some_member() const;
  //void some_member();

  Screen &set(char);

  Screen &set(pos, pos, char);

  Screen &display(std::ostream &os) {
	do_display(os);
	return *this;
  }

  const Screen &display(std::ostream &os) const {
	do_display(os);
	return *this;
  }

 private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  mutable size_t access_ctr;

  void do_display(std::ostream &os) const {
	os << contents << "\n";
  }
};

class ConstRef {
 public:
  ConstRef(int ii);
 private:
  int i;
  const int ci;
  int &ri;

};

class NoDefault {
 public:
  NoDefault(const std::string &);
};

//struct A{
//  NoDefault my_mem;
//};
//
//A a;
//
//struct B{
//  B(){}
//  NoDefault b_menber;
//};

void invoke_chapter7();

struct Sales_data2 {
  std::string bookNo;
  unsigned units_sold;
  double revenue;
};

class Debug {
 public:
  constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
  constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
  constexpr bool any() {
	return hw || io || other;
  }

  void set_io(bool b) { io = b; }
  void set_hw(bool b) { hw = b; }
  void set_other(bool b) { hw = b; }

 private:
  bool hw;
  bool io;
  bool other;
};

class Account {
 public:
  void calculate() { amount += amount * interestRate; }
  static double rate() { return interestRate; }
  static void rate(double);
 private:
  std::string owner;
  double amount;

  static double interestRate;
  static double initRate();

  //period是常量表达式
  static constexpr int period = 30;
  double daily_tbl[period];
};

#endif