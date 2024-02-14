#include <iostream>
using namespace std;
void bubbledort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
    bool flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
}
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {5, 7, 3, 5, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sorting an array : " << endl;
    printarr(arr, n);
    bubbledort(arr, n);
    cout << "After sorting an array : " << endl;
    printarr(arr, n);
    return 0;
}