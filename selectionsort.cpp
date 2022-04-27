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
void selectionsort(int arr[], int n)
{
    int min_idx;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[i], &arr[min_idx]);
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
    selectionsort(arr, n);
    auto end = high_resolution_clock::now();
    double timetaken = duration<double, std::milli>(end - start).count();
    cout << "\nSorted array using Selection sort: \n";
    printarray(arr, n);
    cout << "Time taken : " << timetaken << " microseconds";

    return 0;
}