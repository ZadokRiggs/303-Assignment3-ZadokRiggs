#include <iostream>
#include "Queue.h"

using namespace std;


int main() {
  Queue<int> que;

    //creates queue and fills it with integers, then prints.
  cout << "Instantiating queue of integers..." << endl;
  for(int i = 6; i > 0; i--) {
    que.push(i);
  }
  que.printQueue();
  cout << endl << endl;

    //pops the head from the queue
  cout << "Popping from queue..." << endl;
  que.pop();
  que.printQueue();
  cout << endl << endl;

    //gets the front of the queue
  cout << "Front of queue: " << que.front() << endl;
  que.printQueue();
  cout << endl << endl;

    //checks if the queue is empty
  cout << "Is queue empty? " << que.empty()  << endl;
  if(que.empty()) 
    cout << "Queue is empty." << endl;
  else
    cout << "Queue is not empty." << endl << endl;

    //moves the first item in queue to the back
  cout << "Cycle Queue once..." << endl;
  que.move_to_rear();
  que.printQueue();
  cout << endl << endl;

    //checks what the last location of an item in the queue is
  int j = 2;
  cout << "The last location of " << j << " is: " << que.last_search(j) << endl << endl;

    //sorts the queue using insertion sort
  cout << "Sorting list..." << endl;
  que.insertion_wrapper();
  que.printQueue();
}
