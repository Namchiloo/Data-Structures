#include "dna_storage.hpp"
#include <iostream>

DNAStorage::DNAStorage() = default;
DNAStorage::DNAStorage(const DNAStorage& other)
    : capacity_{other.capacity_}, size_{other.size_}, mol{new char[capacity_]} {
  std::copy(other.mol, other.mol + other.size_, mol);
}
DNAStorage::DNAStorage(DNAStorage&& other)
    : capacity_{other.capacity_}, size_{other.size_}, mol{other.mol} {
  other.capacity_ = 0;
  other.size_ = 0;
  other.mol = nullptr;
}
DNAStorage& DNAStorage::operator=(const DNAStorage& other) {
  return *this = DNAStorage{other};
}
DNAStorage& DNAStorage::operator=(DNAStorage&& other) {
  capacity_ = other.capacity_;
  size_ = other.size_;
  other.size_ = 0;
  mol = other.mol;
  other.mol = nullptr;
  return *this;
}
DNAStorage::~DNAStorage() { delete[] mol; }
void DNAStorage::realocate() {
  if (size_ == capacity_) {
    capacity_ *= 2;
    auto temp = new char[capacity_];
    for (int i = 0; i < size_; ++i) temp[i] = mol[i];
    delete[] mol;
    mol = temp;
  }
}
bool DNAStorage::check(const char& c) const {
  return c == 'A' || c == 'C' || c == 'T' || c == 'G';
}
void DNAStorage::insert(int pos, std::string lanac) {
  if (size_ + lanac.size() > capacity_) realocate();
  for (int m = 0; m < pos; ++m) {
    if (mol[m] != 'A' && mol[m] != 'C' && mol[m] != 'T' && mol[m] != 'G' &&
        mol[m] != '\0') {
      mol[m] = '\0';
    }
  }
  for (int i = 0; i < lanac.size(); ++i) {
    mol[pos] = lanac[i];
    ++pos;
  }

  if (size_ <= pos)
    size_ = pos + lanac.size();
  else if (pos < size_ && pos + lanac.size() > size_)
    size_ = pos + lanac.size();
  else
    size_ += lanac.size();
}
int DNAStorage::remove(int pos, int len) {
  int counter = 0;
  while (check(mol[pos]) && pos <= pos + len) {
    mol[pos] = '\0';
    pos++;
    counter++;
  }
  if (size_ <= pos + len) size_ = pos + len;
  return counter;
}
void DNAStorage::print(std::ostream& out, int pos, int len) const {
  int right = 0;
  int left = pos;
  std::string lanac = "";
  while (check(mol[pos]) && pos <= pos + len) {
    lanac += mol[pos];
    ++right;
    ++pos;
  }
  --right;
  out << left << "-" << right << ":" << lanac << std::endl;
}

void DNAStorage::print(std::ostream& out) const {
  if (size_ == 0) {
    out << "0:0 NULL" << std::endl;
    return;
  }
  int start, end = 0;
  std::string s;
  while (end < size_) {
    start = end;
    s = "";
    if (mol[end] == '\0') {
      s += "NULL";
      while (mol[end] == '\0') ++end;
    } else
      while (end < size_ && mol[end] != '\0') s += mol[end++];
    out << start << ":" << end - 1 << "-" << s << std::endl;
  }
}
