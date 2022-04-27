#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}
int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "\nEnter the elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    auto start = high_resolution_clock::now();
    quicksort(arr, 0, n - 1);
    auto end = high_resolution_clock::now();
    double timetaken = duration<double, std::milli>(end - start).count();
    cout << "\nSorted array using quick sort: \n";
    printarray(arr, n);
    cout << "Time taken : " << timetaken << " microseconds";

    return 0;
}