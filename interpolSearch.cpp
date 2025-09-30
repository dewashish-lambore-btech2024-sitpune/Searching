#include <iostream>
using namespace std;

int interpSearch(const int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            return (arr[left] == target) ? left : -1;
        }

        // Estimate the probable position using interpolation formula
        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]);

        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }

    return -1; // not found
}

int main() {
    int numbers[] = {12, 18, 24, 32, 47, 59, 63, 71};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    int key = 47;
    int index = interpSearch(numbers, length, key);

    if (index != -1) {
        cout << "Element " << key << " found at index " << index << endl;
    } else {
        cout << "Element " << key << " not found in the array" << endl;
    }

    return 0;
}
