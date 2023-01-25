#pragma once
#include <cstdio>
#include "ToDoTask.hpp"
#include "node.hpp"

template <typename T>
class sorted_list {
  private:
  Node<T>* first = nullptr;
  Node<T>* tail = nullptr;
  size_t size_ = 0;

  public:
  sorted_list() = default;
  sorted_list(const sorted_list&);
  sorted_list(sorted_list&&);
  sorted_list& operator=(const sorted_list&);
  sorted_list& operator=(sorted_list&&);
  ~sorted_list();
  class iterator;
  iterator begin() const { return iterator{first, nullptr}; }
  iterator end() const { return iterator{nullptr, tail}; }
  void add(const T&);
  void add(T&&);
  iterator find(const T&);
  template <typename U>
  iterator find_if(U);
  void remove(iterator);
  size_t size() const;
  bool empty() const;
  void clear();
  // zadatak2
  void add(ToDoTask&);
  iterator find(int);
  void done(int);
  void the_biggest_priority();
  void the_smallest_priority();
  void print();
};
template <typename T>
sorted_list<T>::sorted_list(const sorted_list& other) : size_{other.size_} {
  if (other.size_ > 0) {
    Node<T>* temp = other.first;
    first = tail = new Node<T>{temp->value};
    Node<T>* tmp = first;
    temp = temp->next;
    while (temp != nullptr) {
      tmp->next = new Node<T>{temp->value, tail};
      tmp = tmp->next;
      tail = tmp;
      temp = temp->next;
    }
  }
}
template <typename T>
sorted_list<T>::sorted_list(sorted_list&& other)
    : first{other.first}, tail{other.tail}, size_{other.size_} {
  other.first = nullptr;
  other.tail = nullptr;
  other.size_ = 0;
}
template <typename T>
sorted_list<T>& sorted_list<T>::operator=(const sorted_list<T>& other) {
  while (first != nullptr) {
    Node<T>* temp = first;
    first = first->next;
    delete temp;
  }
  tail = nullptr;
  if (other.size_ > 0) {
    Node<T>* temp = other.first;
    first = tail = new Node<T>{temp->value};
    temp = temp->next;
    while (temp != nullptr) {
      tail->next = new Node<T>{temp->value, tail};
      tail = tail->next;
      temp = temp->next;
    }
  }
  size_ = other.size_;
  return *this;
}
template <typename T>
sorted_list<T>& sorted_list<T>::operator=(sorted_list&& other) {
  while (first != nullptr) {
    Node<T>* temp = first;
    first = first->next;
    delete temp;
  }
  first = other.first;
  tail = other.tail;
  size_ = other.size_;
  other.first = nullptr;
  other.tail = nullptr;
  other.size_ = 0;
  return *this;
}
template <typename T>
sorted_list<T>::~sorted_list() {
  Node<T>* temp = first;
  while (first != nullptr) {
    first = first->next;
    delete temp;
    temp = first;
  }
}
template <typename T>
void sorted_list<T>::add(const T& item) {
  if (size_ == 0) {
    first = tail = new Node<T>{item};
    size_++;
    return;
  } else if (size_ == 1) {
    if (item > first->value) {
      first->next = tail = new Node<T>{item, first};
      size_++;
      return;
    } else {
      first = new Node<T>{item, nullptr, tail};
      tail->previous = first;
      size_++;
      return;
    }
  } else if (size_ >= 2) {
    if (item <= first->value) {
      auto temp = first;
      first = new Node<T>{item, nullptr, temp};
      size_++;
      return;
    } else if (item >= tail->value) {
      auto temp = tail;
      tail = new Node<T>{item, temp};
      temp->next = tail;
      size_++;
      return;
    } else {
      Node<T>* left = first;
      Node<T>* right = first->next;
      while (right != nullptr) {
        if (item >= left->value && item <= right->value) {
          left->next = new Node<T>{item, left, right};
          right->previous = left->next;
          size_++;
          return;
        }
        left = left->next;
        right = right->next;
      }
    }
  }
}

template <typename T>
void sorted_list<T>::add(T&& item) {
  if (size_ == 0) {
    first = tail = new Node<T>{item};
    size_++;
    return;
  } else if (size_ == 1) {
    if (item > first->value) {
      first->next = tail = new Node<T>{item, first};
      size_++;
      return;
    } else {
      first = new Node<T>{item, nullptr, tail};
      tail->previous = first;
      size_++;
      return;
    }
  } else if (size_ >= 2) {
    if (item <= first->value) {
      auto temp = first;
      first = new Node<T>{item, nullptr, temp};
      size_++;
      return;
    } else if (item >= tail->value) {
      auto temp = tail;
      tail = new Node<T>{item, temp};
      temp->next = tail;
      size_++;
      return;
    } else {
      Node<T>* left = first;
      Node<T>* right = first->next;
      while (right != nullptr) {
        if (item >= left->value && item <= right->value) {
          left->next = new Node<T>{item, left, right};
          right->previous = left->next;
          size_++;
          return;
        }
        left = left->next;
        right = right->next;
      }
    }
  }
}
template <typename T>
void sorted_list<T>::add(ToDoTask& item) {
  if (empty()) {
    first = tail = new Node<T>{item};
    size_++;
    return;
  } else if (size_ == 1) {
    if (item.getPriority() > first->value.getPriority()) {
      first->next = tail = new Node<T>{item, first};
      size_++;
      return;
    } else {
      first = new Node<T>{item, nullptr, tail};
      tail->previous = first;
      size_++;
      return;
    }
  } else if (size_ >= 2) {
    if (item.getPriority() <= first->value.getPriority()) {
      auto temp = first;
      first = new Node<T>{item, nullptr, temp};
      size_++;
      return;
    } else if (item.getPriority() >= tail->value.getPriority()) {
      auto temp = tail;
      tail = new Node<T>{item, temp};
      temp->next = tail;
      size_++;
      return;
    } else {
      Node<T>* left = first;
      Node<T>* right = first->next;
      while (right != nullptr) {
        if (item.getPriority() >= left->value.getPriority() &&
            item.getPriority() <= right->value.getPriority()) {
          left->next = new Node<T>{item, left, right};
          right->previous = left->next;
          size_++;
          return;
        }
        left = left->next;
        right = right->next;
      }
    }
  }
}
template <typename T>
class sorted_list<T>::iterator {
  public:
  Node<T>* curr_;
  Node<T>* prev_;

  iterator(Node<T>* ptr, Node<T>* pel) : curr_{ptr}, prev_{pel} {}
  T& operator*() { return curr_->value; }
  const T& operator*() const { return curr_->value; }
  iterator& operator++() {
    prev_ = curr_;
    if (curr_ != nullptr) curr_ = curr_->next;
    return *this;
  }
  iterator operator++(int) {
    iterator temp{curr_, prev_};
    prev_ = curr_;
    if (curr_ != nullptr) curr_ = curr_->next;
    return temp;
  }
  iterator& operator--() {
    curr_ = prev_;
    if (prev_ != nullptr) prev_ = prev_->previous;
    return *this;
  }
  iterator operator--(int) {
    iterator temp{curr_, prev_};
    curr_ = prev_;
    if (prev_ != nullptr) prev_ = prev_->previous;
    return temp;
  }
  bool operator!=(const iterator& other) { return curr_ != other.curr_; }
  bool operator==(const iterator& other) { return curr_ == other.curr_; }
};
template <typename T>
size_t sorted_list<T>::size() const {
  return size_;
}
template <typename T>
bool sorted_list<T>::empty() const {
  return size_ == 0;
}
template <typename T>
void sorted_list<T>::clear() {
  while (first != nullptr) {
    Node<T>* temp = first;
    first = first->next;
    delete temp;
    --size_;
  }
}
template <typename T>
typename sorted_list<T>::iterator sorted_list<T>::find(const T& item) {
  for (auto it = begin(); it != end(); ++it) {
    if (*it == item) return it;
  }
  return end();
}
template <typename T>
typename sorted_list<T>::iterator sorted_list<T>::find(int item) {
  for (auto it = begin(); it != end(); ++it) {
    if (*it == item) return it;
  }
  return end();
}
template <typename T>
template <typename U>
typename sorted_list<T>::iterator sorted_list<T>::find_if(U predicate) {
  for (auto it = begin(); it != end(); ++it) {
    if (predicate(*it)) return it;
  }
  return end();
}
template <typename T>
void sorted_list<T>::remove(iterator it) {
  if (it.curr_ == first) {
    Node<T>* temp = first;
    first = first->next;
    first->previous = nullptr;
    delete temp;
    size_--;
    return;
  }
  if (it.curr_ == tail) {
    Node<T>* temp = tail;
    tail = tail->previous;
    tail->next = nullptr;
    delete temp;
    size_--;
    return;
  }
  for (iterator iter{first, nullptr}; iter != end(); ++iter) {
    if (iter == it) {
      Node<T>* temp = iter.curr_;
      Node<T>* left = temp->previous;
      Node<T>* right = temp->next;
      left->next = right;
      right->previous = left;
      delete temp;
      size_--;
    }
  }
}
template <typename T>
void sorted_list<T>::done(int id_) {
  if (empty()) return;
  auto it = find(id_);
  remove(it);
}
template <typename T>
void sorted_list<T>::the_biggest_priority() {
  if (empty()) {
    std::cout << "Lista je prazna!" << std::endl;
    return;
  }
  if (size_ < 3) {
    for (auto it = begin(); it != end(); ++it) {
      (*it).print(std::cout);
    }
    return;
  }
  int counter = 0;
  for (auto it = begin(); it != end() && counter < 3; ++it) {
    (*it).print(std::cout);
    ++counter;
  }
}
template <typename T>
void sorted_list<T>::the_smallest_priority() {
  if (empty()) {
    std::cout << "Lista je prazna!" << std::endl;
    return;
  }
  if (size_ < 3) {
    for (auto it = begin(); it != end(); ++it) {
      (*it).print(std::cout);
    }
    return;
  }
  int counter = 0;
  auto it = end();
  --it;
  while (counter < 3) {
    (*it).print(std::cout);
    --it;
    ++counter;
  }
}
template <typename T>
void sorted_list<T>::print() {
  if (empty()) return;
  for (auto it = begin(); it != end(); ++it) {
    (*it).print(std::cout);
  }
}
