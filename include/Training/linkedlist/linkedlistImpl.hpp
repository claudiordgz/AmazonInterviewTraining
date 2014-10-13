#ifndef __LINKEDLISTIMPL__HPP__
#define __LINKEDLISTIMPL__HPP__

namespace linkedlist
{

template<class T>
List<T>::List(T const &root) {
  _root.reset(new Node<T>(root));
}

template<class T>
void List<T>::push_back(T const &root) {
  if (_root == nullptr) {
    _root.reset(new Node<T>(root));
  }
  else {
    auto current = begin();
    while (current->next != nullptr) {
      current = current->next.get();
    }
    current->next.reset(new Node<T>(root));
  }
}

}

#endif