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
void merge(int arr[], int l, int m, int r)
{
    int p, q;
    p = m - l + 1;
    q = r - m;
    int larr[p], rarr[q];
    for (int i = 0; i < p; i++)
        larr[i] = arr[l + i];
    for (int j = 0; j < q; j++)
        rarr[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < p && j < q)
    {
        if (larr[i] <= rarr[j])
        {
            arr[k] = larr[i];
            i++;
        }
        else
        {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < p)
    {
        arr[k] = larr[i];
        i++;
        k++;
    }
    while (j < q)
    {
        arr[k] = rarr[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int l, int r)
{
    int m;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    mergesort(arr, 0, n - 1);
    auto end = high_resolution_clock::now();
    double timetaken = duration<double, std::milli>(end - start).count();
    cout << "\nSorted array using Merge sort: \n";
    printarray(arr, n);
    cout << "Time taken : " << timetaken << " microseconds";

    return 0;
}