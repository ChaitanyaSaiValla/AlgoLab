#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int linear_search(int array[], int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == x)
            return i;
    }
    return -1;
}
int main()
{
    int arr[1000], x;
    for (int i = 0; i < 1000; i++)
        arr[i] = i;
    cout << "Enter the Number to be Searched: ";
    cin >> x;
    auto start1 = high_resolution_clock::now();
    int position = linear_search(arr, 1000, x);
    auto stop1 = high_resolution_clock::now();
    double duration1 = duration<double, std::milli>(stop1 - start1).count();
    if (position == -1)
        cout << "Number is not present in the array\n";
    else
        cout << "Number is present at index " << position << " in the array\n";
    cout << "Time taken : " << duration1 << " microseconds";
    return 0;
}