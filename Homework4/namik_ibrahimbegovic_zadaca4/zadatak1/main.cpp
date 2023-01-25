#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>

void loadWords(std::map<std::string, std::list<int>>&, std::ifstream&);
void print(const std::map<std::string, std::list<int>>&);
void printPositions(const std::list<int>&);

int main(void) {
  std::ifstream file{"story.txt"};
  std::map<std::string, std::list<int>> mapa;
  loadWords(mapa, file);
  print(mapa);
  return 0;
}

void loadWords(std::map<std::string, std::list<int>>& mapa,
               std::ifstream& file) {
  if (file.is_open()) {
    std::string tmp;
    int counter = 0;
    while (file >> tmp) {
      auto it = mapa.find(tmp);
      if (it != mapa.end()) {
        it->second.push_back(counter);
      } else {
        std::list<int> v;
        v.push_back(counter);
        mapa[tmp] = v;
      }
      ++counter;
    }
  }
}

void print(const std::map<std::string, std::list<int>>& mapa) {
  for (auto it = mapa.begin(); it != mapa.end(); ++it) {
    std::cout << "Word is " << it->first
              << " and is in the following positions" << std::endl;
    printPositions(it->second);
    std::cout << std::endl;
  }
}

void printPositions(const std::list<int>& positions) {
  for (auto it = positions.begin(); it != positions.end(); ++it) {
    std::cout << *it << " ";
  }
}
