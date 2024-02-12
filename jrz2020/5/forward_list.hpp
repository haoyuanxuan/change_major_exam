#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

template <typename T>
struct Node {
 public:
  Node* next = nullptr;
  T data;
};

template <typename T>
class ForwardList {
 public:
  ForwardList();

  int size() const;
  bool empty() const;
  T const& front() const;
  T const& back() const;
  void remove(T const& value);
  void push_front(T const& value);
  void push_back(T const& value);

  // Returns the first element that equals to value in the range [start_position, list_last_node]
  // - If `start_position == nullptr`, the range is [list_first_node, list_last_node]
  // - Returns nullptr if no such element is found
  Node<T> const* find(Node<T> const* start_position, T const& value) const;
};

#endif