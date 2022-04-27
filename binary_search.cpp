#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int binary_search_recursive(int array[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] > x)
            return binary_search_recursive(array, l, mid - 1, x);

        return binary_search_recursive(array, mid + 1, r, x);
    }
    return -1;
}
int binary_search_iterative(int array[], int l, int r, int x)
{
    int mid;
    while (r >= l)
    {
        mid = l + (r - l) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[1000], x, y;
    for (int i = 0; i < 1000; i++)
        arr[i] = i;

    cout << "Binary Search (Recursive Method)\n";
    cout << "Enter the Number to be Searched:\n ";
    cin >> x;
    auto start1 = high_resolution_clock::now();
    int position1 = binary_search_recursive(arr, 0, 1000, x);
    auto stop1 = high_resolution_clock::now();
    double duration1 = duration<double, std::milli>(stop1 - start1).count();
    if (position1 == -1)
        cout << "Number is not present in the array\n";
    else
        cout << "Number is present at index " << position1 << " in the array\n";
    cout << "Time taken : " << duration1 << " milliseconds\n";

    cout << "Binary Search (iterative method)\n";
    cout << "Enter the Number to be Searched:\n ";
    cin >> y;
    auto start2 = high_resolution_clock::now();
    int position2 = binary_search_recursive(arr, 0, 1000, y);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration<double, std::milli>(stop2 - start2).count();
    if (position2 == -1)
        cout << "Number is not present in the array\n";
    else
        cout << "Number is present at index " << position2 << " in the array\n";
    cout << "Time taken : " << duration2 << " milliseconds";
    return 0;
}