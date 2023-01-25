#pragma once
#include <iomanip>
#include <iostream>
#include <string>
class ToDoTask {
  private:
  int id;
  std::string title;
  std::string description;
  int priority;

  public:
  ToDoTask(const std::string&, const std::string&, const int&);
  ToDoTask(std::string&&, std::string&&, int&&);
  bool operator==(const int&);
  int getPriority() { return priority; }
  int getId() { return id; }
  void print(std::ostream& out);
};
int generateId() {
  static int counter = 0;
  return ++counter;
}
ToDoTask ::ToDoTask(const std::string& title_, const std::string& desc_,
                    const int& priority_)
    : title{title_}, description{desc_}, priority{priority_} {
  id = generateId();
}
ToDoTask::ToDoTask(std::string&& title_, std::string&& desc, int&& prior)
    : title{title_}, description{desc}, priority{prior} {
  id = generateId();
}
void ToDoTask ::print(std::ostream& out) {
  out << std::setw(10) << setiosflags(std::ios::left) << id << std::setw(20)
      << setiosflags(std::ios::left) << title << std::setw(40)
      << setiosflags(std::ios::left) << description << std::setw(10)
      << setiosflags(std::ios::left) << priority << std::endl;
}
bool ToDoTask::operator==(const int& x) { return id == x; }
