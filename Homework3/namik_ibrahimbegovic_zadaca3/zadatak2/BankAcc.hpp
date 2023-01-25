#include <iomanip>
#include <iostream>
#include <queue>
#include <string>

class transaction {
  private:
  double value;
  std::string date;
  std::string time;

  public:
  transaction() = default;
  transaction(const double& value_, const std::string& d, const std::string& t)
      : value{value_}, date{d}, time{t} {}
  double getValue() { return value; }
  void setValue(const double& val) { value = val; }
  std::string getDate() { return date; }
  void setDate(const std::string& date_) { date = date_; }
  std::string getTime() { return time; }
  void setTime(const std::string& time_) { time = time_; }
};

class BankAccount {
  private:
  std::string name;
  std::string surname;
  double ballance = 0;
  std::queue<transaction> transactions;

  public:
  BankAccount() = default;
  void setName(const std::string& name_) { name = name_; }
  std::string getName() { return name; }
  void setSurname(const std::string& surname_) { surname = surname_; }
  std::string getSurname() { return surname; }
  double getBallance() { return ballance; }
  std::queue<transaction>& getTransactions() { return transactions; }
  void addTransaction(const transaction& trans) { transactions.push(trans); }
  void applyTransaction();
  void pendingTransaction();
  void discardTrans();
};
void BankAccount::applyTransaction() {
  if (getTransactions().size() == 0) {
    std::cout << "There are no pending transactions!" << std::endl;
    return;
  }
  std::cout << "What you want to do?" << std::endl;
  std::cout << "1.Add to account" << std::endl;
  std::cout << "2.Withdraw from te account" << std::endl;
  int choice;
  std::cout << "Your choice: ";
  std::cin >> choice;
  if (choice == 1) {
    ballance += getTransactions().front().getValue();
    getTransactions().pop();
  } else if (choice == 2) {
    ballance -= getTransactions().front().getValue();
    getTransactions().pop();
  } else
    throw std::invalid_argument{"Invalid input!"};
}
void BankAccount::pendingTransaction() {
  if (transactions.size() == 0) {
    std::cout << "There are no pending transactions!" << std::endl;
    return;
  }
  std::cout << "Date:" << std::setw(10)
            << "Time:" << std::setw(10)
            << "Value:" << std::endl;

  std::cout << transactions.front().getDate() << std::setw(10)
            << transactions.front().getTime() << std::setw(10)
            << transactions.front().getValue() << std::endl;
}
void BankAccount::discardTrans() {
  if (transactions.size() == 0) {
    std::cout << "There are no pending transactions!" << std::endl;
    return;
  }
  transactions.pop();
}
