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

// #include <iostream>
// using namespace std;

// template <typename T>
// void printArray(T arr[], int size) {
//     for (int i = 0; i < size; ++i) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int intArray[] = {1, 2, 3, 4, 5};
//     char charArray[] = {'A', 'B', 'C', 'D', 'E'};

//     printArray(intArray, 5);
//     printArray(charArray, 5);

//     return 0;
// }
