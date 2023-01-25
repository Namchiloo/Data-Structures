#include <fstream>
#include <iomanip>
#include <iostream>
#include "station.hpp"

void loadStations(std::vector<station>&);
void insertData(const std::string&, std::vector<station>&);
void loadData(std::vector<station>&);
void year_inf(const std::string&, std::vector<station>&);
void month_inf(const std::string&, std::vector<station>&);
void add_data(const std::string&, std::vector<station>&);

int main(void) {
  std::vector<station> stations;
  loadStations(stations);
  loadData(stations);
  while (true) {
    std::cout << "********HISTORICAL TEMPERATURE INFORMATION********"
              << std::endl;
    std::cout << "        1.Get information for entire year        "
              << std::endl;
    std::cout << "        2.Get information for specific month        "
              << std::endl;
    std::cout
        << "        3.Insert new historical temperature information        "
        << std::endl;
    std::cout << "        4.Exit        " << std::endl;
    int choice;
    std::cout << "Your choice: ";
    std::cin >> choice;
    if (choice == 1) {
      std::cout << "Enter location where station is placed: ";
      std::string location;
      std::cin >> location;
      year_inf(location, stations);
    } else if (choice == 2) {
      std::cout << "Enter location where station is placed: ";
      std::string location;
      std::cin >> location;
      month_inf(location, stations);
    } else if (choice == 3) {
      std::string station_id;
      std::cout << "Enter the station ID: ";
      std::cin >> station_id;
      add_data(station_id, stations);
    } else if (choice == 4)
      break;
    else
      std::cout << "Invalid input, please try again" << std::endl;
  }
  return 0;
}
void loadStations(std::vector<station>& stations) {
  std::ifstream file;
  std::string tmp;
  station stan;
  file.open("stations.csv");
  if (!file.is_open()) std::cout << "Error" << std::endl;
  getline(file, tmp);
  while (file.good()) {
    getline(file, tmp, ',');
    if (tmp.size() == 0) break;
    stan.setId(tmp);
    getline(file, tmp, ',');
    stan.setLatt(std::stod(tmp));
    getline(file, tmp, ',');
    stan.setLong(std::stod(tmp));
    getline(file, tmp, ',');
    stan.setEle(std::stod(tmp));
    getline(file, tmp, '\n');
    stan.setCity(tmp);
    stations.push_back(stan);
  }
}

void year_inf(const std::string& city_, std::vector<station>& s) {
  bool exist = true;
  int pos;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i].getCity() == city_) {
      pos = i;
      exist = false;
    }
  }
  if (exist) {
    std::cout << std::endl << std::endl;
    std::cout << "We dont have the requested city in the archive!" << std::endl
              << std::endl;
    return;
  }
  for (auto it = s.begin(); it != s.end(); ++it) {
    if (it->getCity() == city_) {
      std::cout << "Station ID: " << it->getId() << std::endl;
      std::cout << "Lattitude: " << it->getLatt() << std::endl;
      std::cout << "Longitude: " << it->getLong() << std::endl;
      std::cout << "Elevation: " << it->getEle() << std::endl << std::endl;
      break;
    }
  }
  int year;
  std::cout << "Enter year: ";
  std::cin >> year;
  std::cout << std::setw(10) << setiosflags(std::ios::left)
            << "Month:" << std::setw(14) << setiosflags(std::ios::left)
            << "Max. temp" << std::setw(10) << setiosflags(std::ios::left)
            << "Min. temp" << std::endl;
  for (int i = 0; i < s[pos].getData().size(); ++i) {
    if (s[pos].getData()[i].getYear() == year) {
      std::cout << std::setw(10) << setiosflags(std::ios::left)
                << s[pos].getData()[i].getMonth() << std::setw(10);
      if (s[pos].getData()[i].getMax_temp() == 0)
        std::cout << std::setw(14) << setiosflags(std::ios::left) << "N/A";
      else
        std::cout << std::setw(14) << setiosflags(std::ios::left)
                  << s[pos].getData()[i].getMax_temp();
      if (s[pos].getData()[i].getMin_temp() == 0)
        std::cout << std::setw(10) << setiosflags(std::ios::left) << "N/A";
      else
        std::cout << std::setw(10) << setiosflags(std::ios::left)
                  << s[pos].getData()[i].getMin_temp();
      std::cout << std::endl;
    }
  }
}
void insertCity(const std::string& city, std::vector<station>& s) {
  int pos;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i].getCity() == city) pos = i;
  }
  std::string city_ = city + ".csv";
  std::ifstream file;
  file.open(city_);
  std::string tmp;
  data inf;
  getline(file, tmp, '\n');
  while (file.good()) {
    getline(file, tmp, ',');
    if (tmp.size() == 0) break;
    inf.setID(tmp);
    getline(file, tmp, '-');
    inf.setYear(std::stod(tmp));
    getline(file, tmp, ',');
    inf.setMonth(std::stod(tmp));
    getline(file, tmp, ',');
    if (tmp.size() == 0) {
      inf.setMax_temp(0);
    } else {
      inf.setMax_temp(std::stod(tmp));
    }
    getline(file, tmp, '\n');
    if (tmp.size() == 0) {
      inf.setMin_temp(0);
    } else {
      inf.setMin_temp(std::stod(tmp));
    }
    s[pos].getData().push_back(inf);
  }
}
void loadData(std::vector<station>& s) {
  insertCity("Tuzla", s);
  insertCity("Belgrade", s);
  insertCity("Bjelasnica", s);
  insertCity("Mostar", s);
  insertCity("BanjaLuka", s);
  insertCity("Neum", s);
  insertCity("Zagreb", s);
}

void month_inf(const std::string& city_, std::vector<station>& s) {
  bool exist = true;
  int pos;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i].getCity() == city_) {
      pos = i;
      exist = false;
    }
  }
  if (exist) {
    std::cout << std::endl;
    std::cout << "We dont have the requested city in the archive!" << std::endl;
    std::cout << std::endl;
    return;
  }
  for (auto it = s.begin(); it != s.end(); ++it) {
    if (it->getCity() == city_) {
      std::cout << "Station ID: " << it->getId() << std::endl;
      std::cout << "Lattitude: " << it->getLatt() << std::endl;
      std::cout << "Longitude: " << it->getLong() << std::endl;
      std::cout << "Elevation: " << it->getEle() << std::endl << std::endl;
      break;
    }
  }
  int year;
  std::string month;
  std::cout << "Enter year: ";
  std::cin >> year;
  std::cout << "Enter month: ";
  std::cin >> month;
  data tmp;
  tmp.setMonth(std::stoi(month));
  for (int i = 0; i < s[pos].getData().size(); ++i) {
    if (s[pos].getData()[i].getYear() == year &&
        s[pos].getData()[i].getMonth() == tmp.getMonth()) {
      std::cout << std::setw(10) << std::setiosflags(std::ios::left)
                << "Max temp";
      std::cout << std::setw(10) << std::setiosflags(std::ios::left)
                << "Min temp" << std::endl;
      std::cout << std::setw(10) << std::setiosflags(std::ios::left)
                << s[pos].getData()[i].getMax_temp();
      std::cout << std::setw(10) << std::setiosflags(std::ios::left)
                << s[pos].getData()[i].getMin_temp() << std::endl;
    }
  }
}

bool the_city_exists(const std::string& id, std::vector<station>& s) {
  for (auto it = s.begin(); it != s.end(); ++it) {
    if (it->getId() == id) return true;
  }
  return false;
}
int position(const std::string& id, std::vector<station>& s) {
  for (int i = 0; i < s.size(); ++i) {
    if (s[i].getId() == id) return i;
  }
}
void add_data(const std::string& id, std::vector<station>& s) {
  if (!the_city_exists(id, s)) {
    std::cout << "Stanica sa unesenim identifikatorom ne postoji!" << std::endl;
    return;
  }
  int pos = position(id, s);
  int year, month;
  double max, min;
  data temp;
  std::cout << "Enter year: ";
  std::cin >> year;
  std::cout << "Enter month: ";
  std::cin >> month;
  std::cout << "Enter max temp: ";
  std::cin >> max;
  std::cout << "Enter min temp: ";
  std::cin >> min;
  temp.setMonth(month);
  for (int i = 0; i < s[pos].getData().size(); ++i) {
    if (s[pos].getData()[i].getYear() == year &&
        s[pos].getData()[i].getMonth() == temp.getMonth()) {
      s[pos].getData()[i].setMax_temp(max);
      s[pos].getData()[i].setMin_temp(min);
      return;
    }
  }
  temp.setYear(year);
  temp.setMax_temp(max);
  temp.setMin_temp(min);
  s[pos].getData().push_back(temp);
}
