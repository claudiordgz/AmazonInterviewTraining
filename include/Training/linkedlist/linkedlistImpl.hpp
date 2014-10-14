#ifndef __LINKEDLISTIMPL__HPP__
#define __LINKEDLISTIMPL__HPP__

namespace linkedlist
{

template<class T>
List<T>::List(T const &root) : _size(1) {
  _root.reset(new Node<T>(root));
}

template<class T>
void List<T>::push_back(T const &root) {
  if (_root == nullptr) {
    _root.reset(new Node<T>(root));
    _size++;
  }
  else {
    auto current = begin();
    while (current->next != nullptr) {
      current = current->next.get();
    }
    current->next.reset(new Node<T>(root));
    _size++;
  }
}

template<class T>
void List<T>::erase(T const& value) {
  if (_root != nullptr) 
  {
    if (_root->data == value){
      _root = std::move(_root->next);
    }
    auto current = begin(), previous = begin();
    current = current->next.get();
    while (current->next != nullptr) {
      if (current->data == value){
          previous->next = std::move(current->next);
          current = previous->next.get();
          _size--;
      }
      else {
        previous = previous->next.get();
        current = previous->next.get();
      }
    }
    if (current->data == value){
      previous->next.release();
      _size--;
    }
  }
}

}

#endif