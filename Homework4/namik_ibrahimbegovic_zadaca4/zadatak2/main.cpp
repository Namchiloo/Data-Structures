#include <iomanip>
#include <iostream>
#include <map>
#include "student.hpp"

std::string s(60, '*');

void meni();
void addStudent(std::map<int, student>&);
void deleteStudent(std::map<int, student>&);
void display_of_all_students(std::map<int, student>&);
void oneStudent(std::map<int, student>&);
void students_app();

int main(void) {
  students_app();
  return 0;
}

void students_app() {
  std::map<int, student> studenti;
  while (1) {
    meni();
    int choice;
    std::cin >> choice;
    if (choice == 1) {
      addStudent(studenti);
    } else if (choice == 2) {
      deleteStudent(studenti);
    } else if (choice == 3) {
      display_of_all_students(studenti);
    } else if (choice == 4) {
      oneStudent(studenti);
    } else
      break;
  }
}

void meni() {
  std::cout << std::endl << s << std::endl << std::endl;
  std::cout << "Dobrodosli u aplikaciju koja vodi evidenciju o studentima!"
            << std::endl;
  std::cout << "Izaberite opciju koju zelite:" << std::endl;
  std::cout << "1. Dodati studenta" << std::endl;
  std::cout << "2. Izbrisati studenta" << std::endl;
  std::cout << "3. Prikazati sve studente" << std::endl;
  std::cout << "4. Prikazati jednog studenta" << std::endl;
  std::cout << "Vas izbor: ";
}

void addStudent(std::map<int, student>& mapa) {
  std::cout << "Unesite index studenta: ";
  int index_;
  std::cin >> index_;
  auto it = mapa.find(index_);
  if (it == mapa.end()) {
    student student_;
    std::cout << "Unesite ime i prezime studenta: ";
    std::string name_;
    std::cin.ignore();
    std::cin.clear();
    getline(std::cin, name_);
    student_.setName(name_);
    std::cout << "Unesite prosjecnu ocjenu studenta: ";
    double average_grade;
    std::cin >> average_grade;
    student_.setGrade(average_grade);
    mapa[index_] = student_;
  } else {
    std::cout << std::endl
              << "Greska! Uneseni student vec postoji!" << std::endl;
    return;
  }
}

void oneStudent(std::map<int, student>& mapa) {
  std::cout << "Po cemu zelite traziti studenta:" << std::endl;
  std::cout << "1. Po imenu i prezimenu" << std::endl;
  std::cout << "2. Po broju indexa" << std::endl;
  std::cout << "Vas izbor je: ";
  int choice;
  std::cin >> choice;
  if (choice == 1) {
    std::string name_;
    std::cout << "Unesite ime i prezime studenta: ";
    std::cin.ignore();
    std::cin.clear();
    getline(std::cin, name_);
    bool x = true;
    for (auto it = mapa.begin(); it != mapa.end(); ++it) {
      if (it->second.getName() == name_) {
        std::string s1(10, ' ');
        std::cout << it->second.getName() << s1 << it->first << s1
                  << it->second.getGrade() << std::endl;
        x = false;
      }
    }
    if (x) {
      std::cout << std::endl << "Trazeni student ne postoji!" << std::endl;
    }
  }

  else if (choice == 2) {
    int index_;
    std::cout << "Unesite broj indexa studenta: ";
    std::cin >> index_;
    auto it = mapa.find(index_);
    if (it == mapa.end()) {
      std::cout << std::endl
                << "Greska! Trazeni student ne postoji!" << std::endl;
    } else {
      std::string s1(10, ' ');
      std::cout << std::endl
                << it->second.getName() << s1 << it->first << s1
                << it->second.getGrade() << std::endl;
    }
  }

  else {
    std::cout << std::endl << "Pogresan unos! " << std::endl;
  }
}

void display_of_all_students(std::map<int, student>& mapa) {
  if (mapa.size()) {
    std::cout << s << std::endl;
    std::cout << std::setw(30) << std::setiosflags(std::ios::left)
              << "Ime studenta:" << std::setw(25)
              << std::setiosflags(std::ios::left)
              << "Broj indexa studenta:" << std::setw(10)
              << std::setiosflags(std::ios::left)
              << "Prosjecna ocjena studenta:" << std::endl;
    for (auto it = mapa.begin(); it != mapa.end(); ++it) {
      std::cout << std::setw(30) << std::setiosflags(std::ios::left)
                << it->second.getName() << std::setw(25)
                << std::setiosflags(std::ios::left) << it->first
                << std::setw(10) << std::setiosflags(std::ios::left)
                << it->second.getGrade() << std::endl;
    }
    std::cout << s << std::endl;
  } else {
    std::cout << std::endl << "Nema unesenih studenata!" << std::endl;
  }
}

void deleteStudent(std::map<int, student>& mapa) {
  std::cout << "Unesite broj indexa studenta kojeg zelite izbrisati: ";
  int index_;
  std::cin >> index_;
  auto it = mapa.find(index_);
  if (it == mapa.end()) {
    std::cout << "Trazeni student ne postoji! " << std::endl;
    return;
  } else {
    std::cout << "Ime i prezime studenta: " << it->second.getName()
              << std::endl;
    std::cout << "Broj indexa: " << it->first << std::endl;
    std::cout << "Prosjecna ocjena: " << it->second.getGrade() << std::endl;
    std::cout << "Jeste li sigurni da zelite izbrisati studenta? " << std::endl;
    std::cout << "1.Da" << std::endl;
    std::cout << "2.Ne" << std::endl;
    std::cout << "Vas izbor: ";
    int choice;
    std::cin >> choice;
    if (choice == 1) {
      mapa.erase(index_);
    } else
      return;
  }
}
