#pragma once

template <typename T>
class Node {
  public:
  T value;
  Node* next=nullptr;;

  Node(const T& val, Node* ptr=nullptr) : value{val}, next{ptr} {}
  Node(const Node& other) : value{other.value}, next{other.next} {}
};
