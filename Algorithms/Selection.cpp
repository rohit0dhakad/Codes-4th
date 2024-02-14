#include <iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}
int main()
{
    int n;
    cout << "Emter Number of Element in Array : " << endl;
    cin >> n;
    int arr[n];
    for (int k = 0; k < n; k++)
    {
        int value;
        cout << "Enter Array Element : " << endl;
        cin >> value;
        arr[k] = value;
    }
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout<< arr[i]<<" ";
    return 0;
}