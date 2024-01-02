#include <iostream>
using namespace std;

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }cout << endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'A', 'B', 'C', 'D', 'E'};

    printArray(intArray, 5);
    printArray(charArray, 5);

    return 0;
}
