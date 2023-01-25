#include <string>

class student {
  private:
  std::string name;
  double grade;  

  public:
  void setName(const std::string& name_) { name = name_; }
  void setGrade(const double& g) { grade = g; }
  std::string getName() { return name; }
  double getGrade() { return grade; }
};
