#include <iostream>
using namespace std;

int searchBinary(const int numbers[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (numbers[middle] == target) {
            return middle; // found
        } 
        else if (numbers[middle] < target) {
            left = middle + 1;
        } 
        else {
            right = middle - 1;
        }
    }
    return -1; // not found
}

int main() {
    int values[] = {5, 15, 25, 35, 45, 55};
    int length = sizeof(values) / sizeof(values[0]);
    int toFind = 35;

    int index = searchBinary(values, length, toFind);

    if (index >= 0) {
        cout << "Value " << toFind << " located at position " << index << endl;
    } else {
        cout << "Value " << toFind << " not present in the array" << endl;
    }

    return 0;
}
