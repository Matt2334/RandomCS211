#include <iostream>
using namespace std;

void modifyArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        *(arr + i) *= 2;
    }
}
int main() {
    int size = 5;
    int* dynamicArray = new int[size];
    for (int i = 0; i < size; ++i) {
        dynamicArray[i] = i + 1;
    }
    modifyArray(dynamicArray, size);
    cout << "The modified array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;
    delete[] dynamicArray;
    return 0;
}
