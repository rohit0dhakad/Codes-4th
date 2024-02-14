#include <iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int leftarr[n1];
    int rightarr[n2];
    for (int i = 0; i < n1; i++)
    {
        leftarr[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightarr[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (leftarr[i] < rightarr[j])
        {
            arr[k] = leftarr[i];
            i++;
        }
        else
        {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int start, int end)
{   if(start<end){
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
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
    mergesort(arr, 0, n-1);
    cout << "Merge Sorted Array Is : " << endl;
    for (int j = 0; j < n; j++)
    {
        cout << arr[j]<<" ";
    }
}