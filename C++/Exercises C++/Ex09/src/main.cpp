//// Copyright 2021 Ozhiganova Polina
#include <iostream>
#include "MyStack.h"

int main() {
  MyStack<int> st(3);
  st.push(5);
  st.push(10);
  st.push(15);
  std::cout << "Get: " << st.get() << std::endl;
  std::cout << "Full: " << st.isFull() << std::endl;
  while (!st.isEmpty()) {
    std::cout << st.pop() << " ";
  }
  std::cout << std::endl;
  std::cout << "Empty: " << st.isEmpty() << std::endl;
  //////////////////////
  std::cout << std::endl;
  //////////////////////
  MyStack<int> st2(2);
  st2.push(1);
  st2.push(2);
  std::cout << "Get: " << st2.get() << std::endl;
  std::cout << "2nd get: " << st2.get() << std::endl;
  std::cout << "Pop: " << st2.pop() << std::endl;
  std::cout << "Pop: " << st2.pop() << std::endl;
  std::cout << "Pop: " << st2.pop() << std::endl;
  //////////////////////
  std::cout << std::endl;
  //////////////////////
  MyStack<int> st3(1);
  std::cout << "Get: " << st3.get() << std::endl;
  return 0;
}
