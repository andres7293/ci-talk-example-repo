#include <gtest/gtest.h>

#include "../src/LinkedList.H"

class LinkedList_Test : public ::testing::Test {
 protected:
  LinkedList<int> int_list;
};

TEST_F(LinkedList_Test, checkNumNodes_of_empy_list) {
  ASSERT_EQ(0, int_list.getNumNodes());
}

TEST_F(LinkedList_Test, checkNumNodes_after_adding_two_elements) {
  int_list.add(1);
  int_list.add(2);
  ASSERT_EQ(2, int_list.getNumNodes());
}

TEST_F(LinkedList_Test, delete_all_nodes) {
  for (int i = 0; i < 100; i++) {
    int_list.add(i);
  }
  ASSERT_EQ(100, int_list.getNumNodes());
  int_list.delete_all();
  ASSERT_EQ(0, int_list.getNumNodes());
}

TEST_F(LinkedList_Test, check_iterate_nodes_function) {
  int expected = 0;
  std::function<void(Node<int>*)> func = [&](Node<int>* node) {};
  for (int i = 0; i < 100; i++) {
    int_list.add(i);
  }
  int_list.iterate_nodes(func);
}

TEST_F(LinkedList_Test, append_a_new_node) {
  auto new_node = new Node<int>(1214);
  int_list.append(new_node);
  ASSERT_EQ(1, int_list.getNumNodes());
  new_node = new Node<int>(1214);
  int_list.append(new_node);
  ASSERT_EQ(3, int_list.getNumNodes());
}

TEST_F(LinkedList_Test, delete_node) {
  auto node = new Node<int>(121);
  int_list.append(node);
  int_list.delete_node(node);
  ASSERT_EQ(2, int_list.getNumNodes());
}

TEST_F(LinkedList_Test, check_if_created_node_exists) {
  auto node = new Node<int>(121);
  auto unknow_node = new Node<int>(122);
  int_list.append(node);
  ASSERT_EQ(true, int_list.exist(node));
  ASSERT_EQ(false, int_list.exist(unknow_node));
  ASSERT_EQ(false, int_list.exist(nullptr));
  delete unknow_node;
}
