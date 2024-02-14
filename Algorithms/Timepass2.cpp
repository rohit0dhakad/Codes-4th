#include <iostream>
using namespace std;

// Merge function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1];
    int rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the two subarrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            ++i;
        }
        else
        {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copy remaining elements if any
    while (i < n1)
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Recursive Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);      // Sort left half
        mergeSort(arr, mid + 1, right); // Sort right half
        merge(arr, left, mid, right);   // Merge the sorted halves
    }
}

int main()
{
    int n;
    cout << "Enter number of element : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int element;
        cout << "Enter Element Number in Array : ";
        cin>>element;
        arr[i]=element;
    }
    mergeSort(arr, 0, n-1);
    cout << "Merge Sorted Array Is : " << endl;
    for (int j = 0; j < n; j++)
    {
        cout << arr[j]<<" ";
    }
}