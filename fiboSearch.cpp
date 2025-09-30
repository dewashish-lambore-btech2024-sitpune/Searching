#include <iostream>
using namespace std;

int fibSearch(const int arr[], int length, int target) {
    int f0 = 0;    // (m-2)'th Fibonacci number
    int f1 = 1;    // (m-1)'th Fibonacci number
    int f2 = f0 + f1; // m'th Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to length
    while (f2 < length) {
        f0 = f1;
        f1 = f2;
        f2 = f0 + f1;
    }

    int offset = -1; // eliminated range from front

    while (f2 > 1) {
        int index = min(offset + f0, length - 1);

        if (arr[index] < target) {
            f2 = f1;
            f1 = f0;
            f0 = f2 - f1;
            offset = index;
        } 
        else if (arr[index] > target) {
            f2 = f0;
            f1 = f1 - f0;
            f0 = f2 - f1;
        } 
        else {
            return index; // found
        }
    }

    // Check last element
    if (f1 && arr[offset + 1] == target) {
        return offset + 1;
    }

    return -1; // not found
}

int main() {
    int data[] = {5, 15, 25, 35, 45, 55, 65};
    int size = sizeof(data) / sizeof(data[0]);
    int key = 55;

    int pos = fibSearch(data, size, key);

    if (pos >= 0) {
        cout << "Value " << key << " found at index " << pos << endl;
    } else {
        cout << "Value " << key << " not present in array" << endl;
    }

    return 0;
}
