#include "BankAcc.hpp"

void meni() {
  std::string s(40, '*');
  std::string z(8, ' ');
  std::cout << s << std::endl;
  std::cout << "Actions:" << std::endl;
  std::cout << z << "1.New transaction" << std::endl;
  std::cout << z << "2.Apply transaction" << std::endl;
  std::cout << z << "3.Pending transaction" << std::endl;
  std::cout << z << "4.Discard pending transaction" << std::endl;
  std::cout << z << "5.Ballance" << std::endl;
  std::cout << z << "6.Exit" << std::endl;
  std::cout << "Your choice: ";
}

int main(void) {
  BankAccount acc;
  while (true) {
    meni();
    int choice;
    std::cin >> choice;
    if (choice == 1) {
      std::string date, time_;
      double val;
      std::cout << "Enter date for new transaction: ";
      std::cin >> date;
      std::cout << "Enter time for new transaction: ";
      std::cin >> time_;
      std::cout << "Enter value for new transaction: ";
      std::cin >> val;
      transaction new_(val, date, time_);
      acc.addTransaction(new_);
    } else if (choice == 2) {
      acc.applyTransaction();
    } else if (choice == 3) {
      acc.pendingTransaction();
    } else if (choice == 4) {
      acc.discardTrans();
    } else if (choice == 5) {
      std::cout << "Ballance: " << acc.getBallance() <<" KM"<< std::endl;
    } else if (choice == 6) {
      break;
    }
  }
  return 0;
}
