#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> input, output;

public:
    // Constructor
    MyQueue() {}

    // Push element to the back of the queue
    void push(int x) {
        input.push(x);
    }

    // Remove the element from the front of the queue
    int pop() {
        if (output.empty()) {
            // Move all elements to output stack
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int front = output.top();
        output.pop();
        return front;
    }

    // Get the front element
    int peek() {
        if (output.empty()) {
            // Move all elements to output stack
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    // Return whether the queue is empty
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);  // Queue: 1 <- 2 <- 3

    cout << "Front: " << q.peek() << endl; // Output: 1
    cout << "Pop: " << q.pop() << endl;    // Output: 1
    cout << "Front: " << q.peek() << endl; // Output: 2
    cout << "Is Empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
