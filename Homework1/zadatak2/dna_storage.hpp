#pragma once
#include<string>
#include <iosfwd>
#include<algorithm>

class DNAStorage {
  private:
  size_t capacity_ = 100;
  size_t size_ = 0;
  char* mol = new char[capacity_];

  public:
  DNAStorage();
  DNAStorage(const DNAStorage&);
  DNAStorage(DNAStorage&&);
  DNAStorage& operator=(const DNAStorage&);
  DNAStorage& operator=(DNAStorage&&);
  ~DNAStorage();
  void realocate();
  bool check (const char&) const;
  void print(std::ostream&) const;
  void print(std::ostream&, int pos, int len) const;
  void insert(int pos, std::string lanac);
  // remove vraca broj elemenata koji su obrisani
  int remove(int pos, int len);
  void store(std::string filename);
  // load baca iznimku tipa std::runtime_error ukoliko ne postoji
  // file sa imenom filename
  void load(std::string filename);
};

