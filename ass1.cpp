#include <iostream>
using namespace std;

// Function for binary search
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;      // Element found
        else if (arr[mid] < key) left = mid + 1; // Search right half
        else right = mid - 1;                 // Search left half
    }
    return -1; // Element not found
}

// Function for bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find missing number in 1..n
int findMissingNumber(int arr[], int n) {
    int expectedSum = (n + 1) * (n + 2) / 2; // Sum of 1 to n+1
    int actualSum = 0;
    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }
    return expectedSum - actualSum;
}

int main() {
    // ------------------- BUBBLE SORT -------------------
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    bubbleSort(arr1, n1);

    cout << "Sorted array: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // ------------------- BINARY SEARCH -------------------
    int key;
    cout << "Enter the number to search in sorted array: ";
    cin >> key;

    int result = binarySearch(arr1, n1, key);
    if (result != -1) 
        cout << "Element found at index " << result << endl;
    else 
        cout << "Element not found" << endl;

    // ------------------- FIND MISSING NUMBER -------------------
    int arr2[] = {1, 2, 3, 4, 6, 7, 8}; // Example array with missing number
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int missing = findMissingNumber(arr2, n2);
    cout << "Missing number is: " << missing << endl;

    return 0;
}
