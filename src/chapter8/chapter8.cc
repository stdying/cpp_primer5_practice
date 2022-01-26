//
// Created by admin on 2022/1/25.
//

#include "chapter8.h"
#include "chapter7.h"

void test() {
  std::ifstream input("input.txt");
  std::ofstream output("output.txt");
  Sales_data total;
  if (read(input, total)) {
	Sales_data trans;
	while (read(input, trans)) {
	  if (total.isbn() == trans.isbn()) {
		total.combine(trans);
	  } else {
		print(output, total) << std::endl;
		total = trans;
	  }

	}
	print(output, total) << std::endl;

  } else {
	std::cerr << "NO data?!" << std::endl;
  }

}

void openMode(){
  std::ofstream out;
  out.open("scratchpad");
  out.close();
  out.open("precious",std::ofstream::app);
  out.close();
}

void invoke_chapter8() {
  std::cout << "===> invoke_chapter8" << std::endl;
  int ival;
  std::cin >> ival;
  std::cout << std::unitbuf;
  std::cout << std::unitbuf;

  std::cout << "hi!" << std::endl;
  std::cout << "hi!" << std::flush;
  std::cout << "hi!" << std::ends;

  std::cin.tie(&std::cout);
  std::ostream *old_tie = std::cin.tie(nullptr);
  std::cin.tie(&std::cerr);
  std::cin.tie(old_tie);

  test();
  openMode();

}
