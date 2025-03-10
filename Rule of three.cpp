#include <iostream>
using namespace std;

class SafeArray {
private:
    int* arr;
    int size;
public:
    // Constructor
    SafeArray(int s) : size(s) {
        arr = new int[size];  // Dynamically allocating memory
    }
    // Destructor (Frees allocated memory)
    ~SafeArray() {
        delete[] arr;
    }
    // Copy Constructor (Performs Deep Copy)
    SafeArray(const SafeArray& other) : size(other.size) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    // Copy Assignment Operator (Handles Deep Copy)
    SafeArray& operator=(const SafeArray& other) {
        if (this != &other) {  // Prevent self-assignment
            delete[] arr;  // Free old memory
            size = other.size;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    // Function to set a value in the array
    void setValue(int index, int value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }

    // Function to print array values
    void display() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SafeArray arr1(5);
    arr1.setValue(0, 10);
    arr1.setValue(1, 20);
    arr1.setValue(2, 30);
    arr1.display();

    SafeArray arr2 = arr1;  // Calls Copy Constructor
    arr2.display();

    SafeArray arr3(3);
    arr3 = arr1;  // Calls Copy Assignment Operator
    arr3.display();

    return 0;  // Destructor automatically called for arr1, arr2, and arr3
}
