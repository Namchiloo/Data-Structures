#pragma once
#include <cstdio>
#include <iostream>
#include <string>

template <typename T>
class circular_queue {
  private:
  T* ptr_;
  size_t capacity_;
  size_t beg_;
  size_t end_;
  size_t size_;

  public:
  circular_queue(size_t n);
  ~circular_queue();
  circular_queue(const circular_queue&);
  circular_queue(circular_queue&&);
  circular_queue& operator=(const circular_queue&);
  circular_queue& operator=(circular_queue&&);
  void realocate();
  template <typename U>
  void push(U&&);
  T& front();
  const T& front() const;
  T& back();
  const T& back() const;
  void pop();
  size_t size() const;
  bool empty() const;
  size_t capacity();
  T operator[](int);
};

template <typename T>
T circular_queue<T>::operator[](int x) {
  return ptr_[x];
}

template <typename T>
circular_queue<T>::~circular_queue() {
  delete[] ptr_;
  ptr_ = nullptr;
  beg_ = 0;
  end_ = 0;
  capacity_ = 0;
}

template <typename T>
circular_queue<T>::circular_queue(const circular_queue& l) {
  capacity_ = l.capacity_;
  ptr_ = new T[capacity_];
  for (auto i = 0; i < capacity_; i++) ptr_[i] = l.ptr_[i];
  beg_ = l.beg_;
  end_ = l.end_;
  size_ = l.size_;
}

template <typename T>
circular_queue<T>::circular_queue(circular_queue&& l) {
  capacity_ = l.capacity_;
  beg_ = l.beg_;
  end_ = l.end_;
  size_ = l.size_;
  ptr_ = l.ptr_;
  l.ptr_ = nullptr;
}

template <typename T>
circular_queue<T>& circular_queue<T>::operator=(const circular_queue& l) {
  delete[] ptr_;
  capacity_ = l.capacity_;
  ptr_ = new T[capacity_];
  for (auto i = 0; i < capacity_; i++) ptr_[i] = l.ptr_[i];
  beg_ = l.beg_;
  end_ = l.end_;
  size_ = l.size_;
  return *this;
}

template <typename T>
circular_queue<T>& circular_queue<T>::operator=(circular_queue&& l) {
  delete[] ptr_;
  capacity_ = l.capacity_;
  beg_ = l.beg_;
  end_ = l.end_;
  size_ = l.size_;
  ptr_ = l.ptr_;
  l.ptr_ = nullptr;
  return *this;
}

template <typename T>
circular_queue<T>::circular_queue(size_t n) : beg_{0}, end_{0}, size_{0} {
  capacity_ = n;
  ptr_ = new T[capacity_];
}

template <typename T>
template <typename U>
void circular_queue<T>::push(U&& val) {
  if (size_ == capacity_) {
    throw std::out_of_range{"Queue is full!"};

  } else {
    end_ = (end_ + 1) % capacity_;
    ptr_[end_] = std::forward<U>(val);
    ++size_;
  }
}

template <typename T>
T& circular_queue<T>::front() {
  return ptr_[beg_];
}

template <typename T>
const T& circular_queue<T>::front() const {
  return ptr_[beg_];
}

template <typename T>
T& circular_queue<T>::back() {
  return ptr_[end_];
}

template <typename T>
const T& circular_queue<T>::back() const {
  return ptr_[end_];
}

template <typename T>
void circular_queue<T>::pop() {
  if (!empty()) {
    beg_ = (beg_ + 1) % capacity_;
    --size_;
  }
}

template <typename T>
size_t circular_queue<T>::size() const {
  return size_;
}

template <typename T>
bool circular_queue<T>::empty() const {
  return (size_ == 0);
}

template <typename T>
size_t circular_queue<T>::capacity() {
  return capacity_;
}
