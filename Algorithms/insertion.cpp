#include <iostream>
using namespace std;
void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        for (int j = i - 1; j>=0; j--)
        {
            if (key < arr[j])
            {
                swap(arr[j+1], arr[j]);
            }
        }
    }
}
void printarray(int arr[], int n)
{
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {24, 4, 5,2, 77,4, 8, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " Befor Sorting Array : " << endl;
    printarray(arr, n);
    insertionsort(arr, n);
    cout << " After Sorting Array : " << endl;
    printarray(arr, n);
}