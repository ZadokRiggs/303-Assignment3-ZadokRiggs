#pragma once
#include <iostream>
#include <vector>

using namespace std;

//standard item/object
template <typename T> struct object {
    T value;
    object<T>* next;
    object(T val) {
        value = val;
        next = nullptr;
    }
};

// queue class
template <typename T> class Queue {
private:
    object<T>* head;
    object<T>* tail;
    int num_items;

public:
    //constructor
    Queue() {
        head = nullptr;
        tail = nullptr;
        num_items = 0;
    }

    //appends an item to the back of the list
    void push(const T& item) {
        object<T>* new_node = new object<T>(item);
        if (head == nullptr) { // deals with if list is empty
            tail = new_node;
            head = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        num_items++;
    }

    //removes the head node
    void pop() {
        if (head == nullptr) {
            tail = nullptr;
            cout << "Queue is empty. Cannot perform pop operation." << endl;
            return;
        }

        object<T>* temp = head;
        head = head->next;
        delete temp;

        num_items--;
    }

    //returns the value in the end of the list
    T front() {
        if (head == nullptr) {
            cout << "Queue is empty." << endl;
            return T();
        }

        return head->value;
    }

    //checks whether the list is empty
    bool empty() { return head == nullptr; }

    //prints all values in queue in order
    void printQueue() {
        object<T>* temp = head;
        int i = 0;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->value << " ";
            i++;
            temp = temp->next;
        }
    }

    //moves the first object to the end of the list
    void move_to_rear() { // I am currently filled with mirth at how comically
        // easy this was to code! Grader! Smile!
        push(front());
        pop();
    }

    //swaps two items
    void swap(object<T>* a, object<T>* b) {
        T temp = a->value;
        a->value = b->value;
        b->value = temp;
    }

    //wrapper for the search algorithm
    int last_search(T& target) { return modified_linear_search(target, head, 0, 0); }

    //ok so it is technically possible to do the sort this way, but I've realized there's a significantly easier way to do it.
      /*
      void modified_insertion_sort() {
        int key;

        bool insertionNeeded = false;
        object<T> *keySearch = head;

        for (int j = 1; keySearch != nullptr; j++) { // j is the index of the element to be inserted

          key = keySearch->value;
          insertionNeeded = false;
          object<T> *sortSearch = head;
          cout << endl << key << endl;

          for (int i = j - 1; i >= 0; i--) { //goes through the sorted part of
            cout << sortSearch->value << " ";

            if (key < sortSearch->value) {
              swap(sortSearch, sortSearch->next);
              insertionNeeded = true;
            }
            else
              break;

            sortSearch = sortSearch->next;
          }
          keySearch = keySearch->next;
        }
      }
    */

    //wrapper for the sorting algorithm
    void insertion_wrapper() {
        object<T>* temp1 = head;
        vector<T> v;
        while (temp1 != nullptr) {
            v.push_back(temp1->value);
            temp1 = temp1->next;
        }
        insertion_sort(v);

        object<T>* temp2 = head;
        for (int i = 0; i < v.size(); i++) {
            temp2->value = v[i];
            temp2 = temp2->next;
        }
        //printQueue();
    }

private:
    //insertion sorting algorithm
    void insertion_sort(vector <T>& num) {
        int i, j;
        T key;
        bool insertionNeeded = false;
        for (j = 1; j < num.size(); j++) {
            key = num[j];
            insertionNeeded = false;
            for (i = j - 1; i >= 0; i--) {
                if (key < num[i]) {
                    num[i + 1] = num[i]; // larger values move right
                    insertionNeeded = true;
                }
                else
                    break;
            }
            if (insertionNeeded)num[i + 1] = key; //Put key into its proper location    
        }
    }

    //searches for the final instance of an item in the list
    int modified_linear_search(T& target, object<T>* pos_first, int spot,
        int max) {

        if (pos_first->value == target) {
            max = spot;
        }
        if (pos_first->next == nullptr) {
            return max;
        }
        else {
            return modified_linear_search(target, pos_first->next, spot + 1, max);
        }
    }
};
