#include <iostream>
using namespace std;
// Function to heapify a subtree rooted at index 'i'
void build_heap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        int parent = i;
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;

        // Compare parent with left child
        if (left_child < n && arr[left_child] > arr[parent])
            swap(arr[parent], arr[left_child]);

        // Compare parent with right child
        if (right_child < n && arr[right_child] > arr[parent])
            swap(arr[parent], arr[right_child]);
    }
}

// Main function to perform heap sort
// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr[] = {2,3,4,5,6,7,8,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    build_heap(arr, n);

    cout << "Heap  array: ";
    printArray(arr, n);

    return 0;
}