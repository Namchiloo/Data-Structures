#pragma once
#include <cstdio>
#include "node.hpp"
template <typename T>
class stack {
  private:
  Node<T>* first = nullptr;
  size_t size_ = 0;

  public:
  stack() = default;
  stack(const stack&);
  stack(stack&&);
  stack& operator=(const stack&);
  stack& operator=(stack&&);
  ~stack();
  void push(const T&);
  void push(T&&);
  T& top();
  const T& top() const;
  size_t size() const;
  bool empty() const;
  void pop();
};
template <typename T>
stack<T>::stack(const stack& other) : size_{other.size_} {
  if (other.size() > 0) {
    Node<T>* tmp = other.first;
    Node<T>* temp = first = new Node<T>{tmp->value};
    Node<T>* ptr = first;
    tmp = tmp->next;
    while (tmp) {
      temp = new Node<T>{tmp->value};
      ptr->next = temp;
      temp = temp->next;
      ptr = ptr->next;
      tmp = tmp->next;
    }
  }
}
template <typename T>
stack<T>::stack(stack<T>&& other) : first{other.first}, size_{other.size_} {
  other.first = nullptr;
  other.size_ = 0;
}
template <typename T>
stack<T>& stack<T>::operator=(const stack<T>& other) {
  if (size_ > 0) {
    Node<T>* temp = first;
    first = first->next;
    delete temp;
    temp = first;
    while (temp) {
      first = first->next;
      delete temp;
      temp = first;
    }
  }
  if (other.size() > 0) {
    Node<T>* tmp = other.first;
    Node<T>* temp = first = new Node<T>{tmp->value};
    Node<T>* ptr = first;
    tmp = tmp->next;
    while (tmp) {
      temp = new Node<T>{tmp->value};
      ptr->next = temp;
      temp = temp->next;
      ptr = ptr->next;
      tmp = tmp->next;
    }
  }
  size_ = other.size_;
}
template <typename T>
stack<T>& stack<T>::operator=(stack&& other) {
  if (size_ > 0) {
    Node<T>* temp = first;
    first = first->next;
    delete temp;
    temp = first;
    while (temp) {
      first = first->next;
      delete temp;
      temp = first;
    }
  }
  first = other.first;
  size_ = other.size_;
  other.first = nullptr;
  other.size_ = 0;
}
template <typename T>
stack<T>::~stack() {
  if (size_ > 0) {
    Node<T>* temp = first;
    first = first->next;
    delete temp;
    temp = first;
    while (temp) {
      first = first->next;
      delete temp;
      temp = first;
    }
  }
}
template <typename T>
void stack<T>::push(const T& item) {
  Node<T>* temp = first;
  first = new Node<T>{item, temp};
  size_++;
}

template <typename T>
void stack<T>::push(T&& item) {
  Node<T>* temp = first;
  first = new Node<T>{item, temp};
  size_++;
}
template <typename T>
T& stack<T>::top() {
  return first->value;
}

template <typename T>
const T& stack<T>::top() const {
  return first->value;
}
template <typename T>
size_t stack<T>::size() const {
  return size_;
}
template <typename T>
bool stack<T>::empty() const {
  return (size_ == 0);
}
template <typename T>
void stack<T>::pop() {
  Node<T>* temp = first;
  first = first->next;
  delete temp;
  --size_;
}
