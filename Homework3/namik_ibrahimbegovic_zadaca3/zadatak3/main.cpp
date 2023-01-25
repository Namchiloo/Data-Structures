#include "circular.hpp"

int main(void) {
  circular_queue<int> red{6};
  red.push(1);
  red.push(2);
  red.push(3);
  red.push(4);
  red.push(5);
  red.push(6);
  std::cout << "Elementi: " << std::endl;
  for (int i = 0; i < red.size(); ++i) {
    std::cout << red[i] << " ";
  }
  std::cout << std::endl;
  red.pop();
  std::cout << "Red nakon pop: ";
  for (int i = 0; i < red.size(); ++i) {
    std::cout << red[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Front: " << red.front() << std::endl;
  std::cout << "Back: " << red.back() << std::endl;
  return 0;
}
