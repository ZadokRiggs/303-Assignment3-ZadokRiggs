#pragma once
#include <iostream>
#include "Queue.h"

using namespace std;


int main() {
    Queue<int> que;

    cout << "Instantiating queue of integers..." << endl;
    for (int i = 6; i > 0; i--) {
        que.push(i);
    }
    que.printQueue();
    cout << endl << endl;

    cout << "Popping from queue..." << endl;
    que.pop();
    que.printQueue();
    cout << endl << endl;

    cout << "Front of queue: " << que.front() << endl;
    que.printQueue();
    cout << endl << endl;

    cout << "Is queue empty? " << que.empty() << endl;
    if (que.empty())
        cout << "Queue is empty." << endl;
    else
        cout << "Queue is not empty." << endl << endl;

    cout << "Cycle Queue once..." << endl;
    que.move_to_rear();
    que.printQueue();
    cout << endl << endl;

    int j = 2;
    cout << "The last location of " << j << " is: " << que.last_search(j) << endl << endl;

    cout << "Sorting list..." << endl;
    que.insertion_wrapper();
    que.printQueue();
}