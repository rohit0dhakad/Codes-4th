#include <iostream>
using namespace std;
void buildheap(int arr[], int n, int current_i)
{   int left=2*current_i-1;
    int right=2*current_i;
    int parent=current_i-1;
    if (current_i > 0)
    {

        int largest = current_i;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != current_i)
        {
            swap(arr[current_i], arr[largest]);
            buildheap(arr, n, largest);
        }
    }
}
void heapcheck(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        buildheap(arr, n, i);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        buildheap(arr, n, i/2-1);
    }
}
int main()
{
    int n = 7;

    int arr[7] = {2, 3, 6, 8, 33, 7, 1};
    for (int i = 0; i < n; i++)
        cout << " " << arr[i] << " ";
    cout << endl;
    heapcheck(arr, n);
    cout << "Heap array: \n";
    for (int i = 0; i < n; i++)
        cout << " " << arr[i];
    cout << endl;

    heapsort(arr, n);
    cout << "Sorted Heap array: \n";
    for (int i = 0; i < n; i++)
        cout << " " << arr[i];
    return 0;
}
