#include <iostream>
#include "dna_storage.cpp"
void meni() {
  std::cout
      << "Welcome to DNA storage. Please enter one of the following options:"
      << std::endl;
  std::cout << "1.Print" << std::endl;
  std::cout << "2.Print <pos> <len>" << std::endl;
  std::cout << "3.Insert <pos> <len>" << std::endl;
  std::cout << "4.Remove <pos> <len>" << std::endl;
  std::cout << "5.Store <file>" << std::endl;
  std::cout << "6.Load <file>" << std::endl;
  std::cout << "Your choice:" << std::endl;
}
int main(void) {
  meni();
  DNAStorage storage;
  int choice;
  while (std::cin >> choice) {
    if (choice == 1) {
      storage.print(std::cout);
    } else if (choice == 2) {
      int position, length;
      std::cin >> position >> length;
      storage.print(std::cout, position, length);
    } else if (choice == 3) {
      int position;
      std::string s;
      std::cout << "Position:";
      std::cin >> position;
      std::cout << "Value:";
      std::cin >> s;
      storage.insert(position, s);
    } else if (choice == 4) {
      int position, length;
      std::cout << "Position:";
      std::cin >> position;
      std::cout << "Length:";
      std::cin >> length;
      storage.remove(position, length);
    } else if (choice == 5) {
    } else if (choice == 6) {
    } else
      std::cout << "Invalid input!" << std::endl;
    std::cout << "Your choice:";
  }
  return 0;
}
