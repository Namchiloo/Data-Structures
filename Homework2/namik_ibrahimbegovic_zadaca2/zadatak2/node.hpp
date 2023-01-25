template <typename T>
class Node {
  public:
  T value;
  Node* next = nullptr;
  Node* previous = nullptr;
  Node() = default;
  Node(const T& val, Node* prev_ = nullptr, Node* next_ = nullptr)
      : value{val}, next{next_}, previous{prev_} {};
};

