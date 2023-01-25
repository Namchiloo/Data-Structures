#pragma once
#include <iostream>
#include <sstream>
#include "stack.hpp"
class PostfixCalc {
  private:
  stack<int> stack_;
  public:
  void add_operand(const int& operand) { stack_.push(operand); }
  void add_operator(const char&);
  void result();
  void push(const std::string&);
  void loadOperation();
};

void PostfixCalc::add_operator(const char& c) {
  int first, second, x;
  if (stack_.size() >= 2) {
    second = stack_.top();
    stack_.pop();
    first = stack_.top();
    stack_.pop();
    if (c == '+') {
      x = first + second;
      stack_.push(x);
    } else if (c == '-') {
      x = first - second;
      stack_.push(x);
    } else if (c == '*') {
      x = first * second;
      stack_.push(x);
    } else if (c == '/') {
      x = first / second;
      stack_.push(x);
    }
  }
}

void PostfixCalc::result() {
  if (stack_.size() == 1)
    std::cout << "Result:" << stack_.top() << std::endl;
  else
    throw std::invalid_argument{"Invalid input!"};
}
void PostfixCalc::push(const std::string& str) {
  if (str == "+" || str == "-" || str == "*" || str == "/") {
    char z = str[0];
    add_operator(z);
  } else {
    int x = std::stoi(str);
    add_operand(x);
  }
}

void PostfixCalc::loadOperation() {
  std::string s;
  std::string z(50, '*');
  std::cout << z << std::endl;
  std::cout << "Unesite operaciju:" << std::endl;
  getline(std::cin, s);
  std::stringstream input(s);
  std::string s1;
  while (std::getline(input, s1, ' ')) {
    if (s1.size() == 0) break;
    push(s1);
  }
  result();
  std::cout << z << std::endl;
}
