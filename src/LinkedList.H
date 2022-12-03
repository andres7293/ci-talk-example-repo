#ifndef __SRC_LINKEDLIST_H__
#define __SRC_LINKEDLIST_H__

#include <functional>
#include <tuple>

template <class T>
class Node {
 public:
  Node(T data, Node* next = nullptr) : data(data), next(next) {}
  ~Node(){};
  T data;
  Node* next;
};

template <class T>
class LinkedList {
 public:
  LinkedList() : head(nullptr), num_nodes(0){};
  ~LinkedList() { };
  void iterate(std::function<void(T)> func) {
    auto current = this->head;
    while (current) {
      func(current->data);
      current = current->next;
    }
  }
  void iterate_nodes(std::function<void(Node<T>*)> func) {
    auto current = this->head;
    while (current) {
      func(current);
      current = current->next;
    }
  }
  bool exist(Node<T>* node) {
    bool exists = false;
    auto func = [&](Node<T>* n) {
      if (n == node) {
        exists = true;
      }
    };
    this->iterate_nodes(func);
    return exists;
    ;
  }
  void add(T data) {
    auto new_node = new Node<T>(data);
    this->append(new_node);
  }
  void append(Node<T>* node) {
    node->next = this->head;
    this->head = node;
    this->increment_num_nodes();
  }
  void delete_node(Node<T>* node) {
    if (node == nullptr) {
      return;
    }
    if (node == this->head) {
      this->delete_head_node();
      this->decrement_num_nodes();
    }
    auto current = this->head;
    auto prev = current;
    ;
    while (current) {
      if (current == node) {
        auto next = current->next;
        delete current;
        prev->next = next;
        this->decrement_num_nodes();
      }
      prev = current;
      current = current->next;
    }
  }
  void delete_all() {
    if (this->head == nullptr) {
      return;
    }
    auto current = this->head->next;
    while (current) {
      auto next = current->next;
      delete current;
      current = next;
    }
    delete this->head;
    this->head = nullptr;
    this->num_nodes = 0;
  }
  unsigned int getNumNodes() { return this->num_nodes; }

 private:
  Node<T>* head;
  unsigned int num_nodes;

  void increment_num_nodes() { this->num_nodes++; }
  void decrement_num_nodes() { this->num_nodes--; }
  void delete_head_node() {
    auto next = this->head->next;
    delete this->head;
    this->head = next;
  }
};

#endif
