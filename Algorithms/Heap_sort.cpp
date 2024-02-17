#include <iostream>
using namespace std;
void build_heap(int arr[], int current_i)
{
    if (current_i > 0)
    {

        if ((arr[2 * current_i - 1] > arr[2 * current_i]) && (arr[current_i - 1] < arr[2 * current_i - 1]))
        {
            swap(arr[current_i - 1], arr[2 * current_i - 1]);
        }
        if ((arr[2 * current_i] > arr[2 * current_i - 1]) && (arr[current_i - 1] < arr[2 * current_i]))
        {
            swap(arr[current_i - 1], arr[2 * current_i]);
        }
        int current_i2 = current_i - 1;
        build_heap(arr, current_i2);
    }
}
void heapcheck(int arr[],int n){
    int current_i = n / 2;
    for (int i = n / 2; i > 0; i--)
    {
        build_heap(arr, current_i);
    }
}
void heapsort(int arr[],int n){
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        int current_i=i/2-1;
        build_heap(arr,current_i);
    }
}
int main()
{
    int n = 7;

    int arr[7] = {2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 7; i++)
        cout << " " << arr[i] << " ";
    cout << endl;
    // int current_i = n / 2;
    // for (int i = n / 2; i > 0; i--)
    // {
    //     build_heap(arr, current_i);
    // }
    heapcheck(arr,n);
    heapsort(arr,n);
    cout << "Sorted array: \n";
    for (int i = 0; i < 7; i++)
        cout << " " << arr[i];
    return 0;
}
