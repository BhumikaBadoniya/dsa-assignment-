#include <iostream>
#include <string>

using namespace std;

// Function to calculate the address of an element in a 3D array
unsigned long calculateAddress(string type, int rows, int cols, int depth, string arrangement, unsigned long baseAddress, int i, int j, int k) {
    int elementSize;

    // Determine the size of the element based on the type
    if (type == "int") {
        elementSize = sizeof(int);
    } else if (type == "char") {
        elementSize = sizeof(char);
    } else if (type == "float") {
        elementSize = sizeof(float);
    } else if (type == "double") {
        elementSize = sizeof(double);
    } else {
        cout << "Unsupported type!" << endl;
        return 0;
    }

    // Calculate the address based on the memory arrangement
    if (arrangement == "ROW") {
        return baseAddress + elementSize * (i * cols * depth + j * depth + k);
    } else if (arrangement == "COLUMN") {
        return baseAddress + elementSize * (k * rows * cols + j * rows + i);
    } else {
        cout << "Unsupported memory arrangement!" << endl;
        return 0;
    }
}

int main() {
    string type;
    int rows, cols, depth, i, j, k;
    string arrangement;
    unsigned long baseAddress;

    // Input the type of array
    cout << "Enter the type of array (int, char, float, double): ";
    cin >> type;

    // Input the size of the array
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    cout << "Enter the depth: ";
    cin >> depth;

    // Input the memory arrangement
    cout << "Enter the memory arrangement (ROW or COLUMN): ";
    cin >> arrangement;

    // Input the base address of the array
    cout << "Enter the base address of the array: ";
    cin >> baseAddress;

    // Input the index of the element
    cout << "Enter the row index of the element: ";
    cin >> i;
    cout << "Enter the column index of the element: ";
    cin >> j;
    cout << "Enter the depth index of the element: ";
    cin >> k;

    // Calculate and output the address of the element
    unsigned long address = calculateAddress(type, rows, cols, depth, arrangement, baseAddress, i, j, k);
    cout << "The address of the element at (" << i << ", " << j << ", " << k << ") is: " << address << endl;

    return 0;
}
