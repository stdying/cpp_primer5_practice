#include "chapter7.h"

void invoke_chapter7() {
  std::cout << "====> invoke_chapter7" << std::endl;
  Screen myScreen(5, 3);
  const Screen blank(5, 3);
  myScreen.set('#').display(std::cout);
  blank.display(std::cout);

  Sales_data item;
  std::string null_book = "9-999-9999-9";
  item.combine(Sales_data(null_book));
  //使用static_cast可以使用explicit的构造函数
  item.combine(static_cast<Sales_data>(null_book));
  std::cout << "after combine " << std::endl;

  //聚合类
  //去除类内初始值
  Sales_data2 item2 = {"798-2232", 25, 15.99};
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << "Print something to wherever the caller wants to";
  os << item.isbn() << " " << item.units_sold << " "
	 << item.revenue << " " << item.avg_price();
  return os;
}

std::istream &read(std::istream &is, Sales_data &item) {

  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

double Sales_data::avg_price() const {
  if (units_sold) {
	return units_sold / units_sold;
  } else {
	return 0;
  }
};

//Sales_data::Sales_data(std::istream &is) {
//  read(is, *this);
//}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}
Sales_data::~Sales_data() {
  std::cout << "~Sales_data" << std::endl;
}

inline char Screen::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}

inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

void Screen::some_member() const {
  std::cout << "some_menber";
  ++access_ctr;
}

Screen &Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

Screen &Screen::set(pos r, pos col, char ch) {
  contents[r * width + col] = ch;
  return *this;
}

void Window_mgr::clear(ScreenIndex index) {
  Screen &s = screens[index];
  s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
  screens.push_back(s);

  return screens.size() - 1;
}

ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(i) {}

//定义并初始化一个静态成员，可以访问类的私有成员
double Account::interestRate = initRate();

//一个不带初始值的静态成员的定义
constexpr int Account::period;

void Account::rate(double newRate) {
  interestRate = newRate;
}
double Account::initRate() {
  return 0;
}
