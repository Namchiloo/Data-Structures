#include <iostream>
#include "linked_list.hpp"
int main(void) {
  sorted_list<ToDoTask> lista;
  std::cout << "Dobrodosli u program podsjetnik na vase obaveze." << std::endl;
  std::cout << "Slijede radnje koje mozete izvrsavati:" << std::endl;
  std::cout << "1.Dodavanje nove obaveze" << std::endl;
  std::cout << "2.Prikaz trenutnih obaveza" << std::endl;
  std::cout << "3.Oznacavanje obaveze kao izvrsene" << std::endl;
  std::cout << "4.Ispis 3 obaveze sa najmanjim prioritetom" << std::endl;
  std::cout << "5.Ispis 3 obaveze sa najvecim prioritetom" << std::endl;
  int choice;
  std::cout << "Vas izbor: ";
  while (std::cin >> choice) {
    if (choice == 1) {
      std::string title_;
      std::string descr_;
      int priorr;
      std::cout << "Unesite naslov:" << std::endl;
      std::cin >> title_;
      std::cout << "Unesite opis:" << std::endl;
      std::cin.clear();
      std::cin.ignore();
      getline(std::cin, descr_);
      std::cout << "Unesite prioritet:" << std::endl;
      std::cin >> priorr;
      ToDoTask x{title_, descr_, priorr};
      lista.add(x);
      std::cout << "Obaveza je uspjesno dodata!" << std::endl;
    } else if (choice == 2) {
      std::cout << std::setw(10) << setiosflags(std::ios::left)
                << "ID:" << std::setw(20) << setiosflags(std::ios::left)
                << "Naslov:" << std::setw(35) << setiosflags(std::ios::left)
                << "Deskripcija:" << std::setw(10)
                << setiosflags(std::ios::left) << "Prioritet:" << std::endl;
      lista.print();
    } else if (choice == 3) {
      std::cout << "Unesite id obaveze koju ste obavili:" << std::endl;
      int id;
      std::cin >> id;
      lista.done(id);
      std::cout << "Obaveza uspjesno uklonjena!" << std::endl;
    } else if (choice == 4) {
      std::cout << std::setw(10) << setiosflags(std::ios::left)
                << "ID:" << std::setw(20) << setiosflags(std::ios::left)
                << "Naslov:" << std::setw(35) << setiosflags(std::ios::left)
                << "Deskripcija:" << std::setw(10)
                << setiosflags(std::ios::left) << "Prioritet:" << std::endl;
      lista.the_smallest_priority();
    } else if (choice == 5) {
            std::cout << std::setw(10) << setiosflags(std::ios::left)
                << "ID:" << std::setw(20) << setiosflags(std::ios::left)
                << "Naslov:" << std::setw(35) << setiosflags(std::ios::left)
                << "Deskripcija:" << std::setw(10)
                << setiosflags(std::ios::left) << "Prioritet:" << std::endl;
      lista.the_biggest_priority();
    }
    std::cout << "Ako zelite prekinuti program pritisnite Ctrl+D, ukoliko "
                 "zelite odraditi neku operaciju unesite vas izbor:"
              << std::endl;
  }

  return 0;
}
