#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(const int arr[], int size, int target) {
    int block = sqrt(size);  // jump size
    int start = 0;
    while (arr[min(block, size) - 1] < target) {
        start = block;
        block += sqrt(size);
        if (start >= size) return -1;
    }

    for (int i = start; i < min(block, size); i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1; // not found
}

int main() {
    int data[] = {5, 12, 19, 26, 33, 47, 55, 63, 72};
    int length = sizeof(data) / sizeof(data[0]);

    int key = 47;
    int idx = jumpSearch(data, length, key);

    if (idx != -1)
        cout << "Value " << key << " located at index " << idx << endl;
    else
        cout << "Value " << key << " not present in array" << endl;

    return 0;
}
