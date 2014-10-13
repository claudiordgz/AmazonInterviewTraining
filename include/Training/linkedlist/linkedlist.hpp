#ifndef __LINKEDLIST__HPP__
#define __LINKEDLIST__HPP__

#include <memory>


namespace linkedlist
{
template<class T>
class Node {
public:
  Node(){}
  Node(T const &pData) : data(pData) {}
  
public:
  std::unique_ptr<Node<T> > next = nullptr;
  T data;
};

template<class T>
class List {
public:
  typedef Node<T>* iterator;

  List() {}
  List(T const &root);
  void push_back(T const &root);
  iterator begin() { return _root.get(); }
private:
  std::unique_ptr<Node<T> > _root;

};

}

#include <Training\linkedlist\linkedlistImpl.hpp>

#endif