#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;  // Internal queue to simulate stack

public:
    // Constructor
    MyStack() {
        // Nothing to do here; queue is initialized automatically
    }

    // Push element onto the stack
    void push(int x) {
        q.push(x);  // Add element to the back

        // Rotate the queue to bring the new element to the front
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());  // Move front element to back
            q.pop();
        }
    }

    // Removes the element on top of the stack and returns it
    int pop() {
        int top_element = q.front();  // Top of stack is front of queue
        q.pop();  // Remove it
        return top_element;
    }

    // Get the top element of the stack
    int top() {
        return q.front();  
    }

    // Returns true if the stack is empty
    bool empty() {
        return q.empty();
    }
};

// Main function 
int main() {
    MyStack* stack = new MyStack();

    stack->push(10);
    stack->push(20);
    stack->push(30); // Stack is now [30, 20, 10]

    cout << "Top element: " << stack->top() << endl;  // Should print 30

    cout << "Popped element: " << stack->pop() << endl; // Should remove and print 30

    cout << "Top after pop: " << stack->top() << endl;  // Should print 20

    cout << "Is stack empty? " << (stack->empty() ? "Yes" : "No") << endl;

    delete stack;  // Free allocated memory

    return 0;
}
