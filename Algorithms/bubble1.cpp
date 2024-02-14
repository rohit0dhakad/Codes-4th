#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    bool Swapbit;
    for (int i = 0; i < n - 1; i++)
    {
        Swapbit = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                Swapbit = true;
            }
        }
        if (Swapbit == false)
            break;
    }
}
int main()
{
    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter Array Element:" << endl;
    for (int k = 0; k < n; k++)
    {
        int value;
        cin >> value;
        arr[k] = value;
    }

    bubbleSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << " " << arr[i];
    return 0;
}
