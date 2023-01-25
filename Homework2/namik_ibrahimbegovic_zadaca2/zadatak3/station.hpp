#pragma once
#include <string>
#include <vector>
class data;
class station {
  private:
  std::string stationID;
  double lattitude;
  double longitude;
  double elevation;
  std::string city_;
  std::vector<data> data_;

  public:
  std::string getId() { return stationID; }
  void setId(const std::string id) { stationID = id; }
  double getLatt() { return lattitude; }
  void setLatt(const double& latt) { lattitude = latt; }
  double getLong() { return longitude; }
  void setLong(const double& longitude_) { longitude = longitude_; }
  double getEle() { return elevation; }
  void setEle(const double& ele) { elevation = ele; }
  std::string getCity() { return city_; }
  void setCity(const std::string& city) { city_ = city; }
  std::vector<data>& getData() { return data_; }
};

class data {
  private:
  std::string stationID;
  int year;
  std::string month;
  double max_temp;
  double min_temp;

  public:
  std::string getId() { return stationID; }
  void setID(const std::string& id) { stationID = id; }
  int getYear() { return year; }
  void setYear(const int& year_) { year = year_; }
  std::string getMonth() { return month; }
  void setMonth(const int& month_) {
    if (month_ == 1)
      month = "Jan";
    else if (month_ == 2)
      month = "Feb";
    else if (month_ == 3)
      month = "Mar";
    else if (month_ == 4)
      month = "Apr";
    else if (month_ == 5)
      month = "May";
    else if (month_ == 6)
      month = "Jun";
    else if (month_ == 7)
      month = "Jul";
    else if (month_ == 8)
      month = "Aug";
    else if (month_ == 9)
      month = "Sep";
    else if (month_ == 10)
      month = "Oct";
    else if (month_ == 11)
      month = "Nov";
    else if (month_ == 12)
      month = "Dec";
  }
  double getMax_temp() { return max_temp; }
  void setMax_temp(const double& temp) { max_temp = temp; }
  double getMin_temp() { return min_temp; }
  void setMin_temp(const double& temp) { min_temp = temp; }
};
