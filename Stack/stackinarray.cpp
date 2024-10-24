#include <iostream> // Include input-output stream library for using cout and cin
using namespace std; // Use the standard namespace

// Define the Stack class
class Stack {
private:
    int top; // Index of the top element in the stack
    int maxSize; // Maximum size of the stack
    int* stackArray; // Pointer to the array that will hold the stack elements

public:
    // Constructor to initialize stack with given size
    Stack(int size) {
        maxSize = size; // Set the maximum size of the stack
        stackArray = new int[maxSize]; // Allocate memory for the stack array
        top = -1; // Initialize top to -1, indicating the stack is empty
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] stackArray; // Deallocate memory for the stack array
    }

    // Function to add an element to the stack
    void push(int value) {
        // Check if the stack is full
        if (top >= maxSize - 1) {
            cout << "Stack Overflow! Unable to push " << value << endl; // Print overflow error
            return; // Exit the function
        }
        stackArray[++top] = value; // Increment top and add the value to the stack
        cout << value << " pushed onto stack." << endl; // Print success message
    }

    // Function to remove and return the top element from the stack
    int pop() {
        // Check if the stack is empty
        if (top < 0) {
            cout << "Stack Underflow! Unable to pop." << endl; // Print underflow error
            return -1; // Return -1 to indicate that the stack is empty
        }
        return stackArray[top--]; // Return the top element and decrement top
    }

    // Function to display all elements of the stack
    void display() {
        // Check if the stack is empty
        if (top < 0) {
            cout << "Stack is empty." << endl; // Print that the stack is empty
            return; // Exit the function
        }
        cout << "Stack elements are: "; // Print header for stack elements
        // Loop through the stack from top to bottom and print each element
        for (int i = top; i >= 0; i--) {
            cout << stackArray[i] << " "; // Print each element
        }
        cout << endl; // End the line
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top < 0; // Return true if top is less than 0, otherwise false
    }

    // Function to return the top element without removing it
    int peek() {
        // Check if the stack is empty
        if (top < 0) {
            cout << "Stack is empty." << endl; // Print that the stack is empty
            return -1; // Return -1 to indicate that the stack is empty
        }
        return stackArray[top]; // Return the top element of the stack
    }
};

// Main function to demonstrate the stack operations
int main() {
    Stack stack(5); // Create a stack of size 5

    stack.push(10); // Push 10 onto the stack
    stack.push(20); // Push 20 onto the stack
    stack.push(30); // Push 30 onto the stack
    stack.display(); // Display the current elements in the stack

    cout << "Top element is: " << stack.peek() << endl; // Print the top element of the stack

    cout << stack.pop() << " popped from stack." << endl; // Pop the top element and print it
    stack.display(); // Display the current elements in the stack after popping

    return 0; // Return 0 to indicate successful execution
}
