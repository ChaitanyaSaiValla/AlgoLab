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
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    heapsort(arr, n);
    auto end = high_resolution_clock::now();
    double timetaken = duration<double, std::milli>(end - start).count();
    cout << "\nSorted array using heap sort: \n";
    printarray(arr, n);
    cout << "Time taken : " << timetaken << " microseconds";

    return 0;
}