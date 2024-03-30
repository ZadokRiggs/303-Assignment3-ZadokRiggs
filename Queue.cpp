

// had to be folded into the .h file because the program would not function if it was not
// i believe this to be due to issues with how the template class interacted between files, although I am not sure if that is accurate

/*#include "Queue.h"
#include <iostream>

template <typename T>
object<T>::object(T val) {
  value = val;
  next = nullptr;
}

template <typename T>
Queue<T>::Queue() {
  head = nullptr;
  tail = nullptr;
  num_items = 0;
}

template <typename T>
void Queue<T>::push(const T& item) {
  if (head == nullptr) { //deals with if list is empty
    tail = new object<T>(item, nullptr);
    head = tail;
  }
  else { //if list isn't empty
    tail->next = new object<T>(item, nullptr); //sets the next value of the tail
to a new object tail = tail->next; //moves tail to the new ending object
  }
  num_items++;
}

template <typename T>
void Queue<T>::pop() {
  if (head == nullptr) {
      tail = nullptr;
      cout << "Queue is empty. Cannot perform pop operation." << endl;
      return;
  }

  object<T>* temp = head;
  head = head->next;
  delete temp; //deletes the temporary variable

  num_items--; //decrements the number of items in the list
}

template <typename T>
object<T> Queue<T>::front() {
  return *head;
}

template <typename T>
bool Queue<T>::empty() {
  if (head == nullptr)
    return true;
  else
    return false;
}

template <typename T>
void Queue<T>::printQueue(){
  object<T>* temp = head;
  while(temp != nullptr){
    cout << temp->value << " ";
  }
}*/
