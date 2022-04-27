#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

typedef struct priorityqueue
{
    int data;
    int priority;
} pq;
int size = -1;
pq arr[1000000];
void enqueue(int data, int priority)
{
    size++;
    arr[size].data = data;
    arr[size].priority = priority;
}
int peek()
{
    int hp = INT_MIN;
    int q = -1;
    for (int i = 0; i <= size; i++)
    {
        if (hp == arr[i].priority && q > -1 && arr[q].data < arr[i].data)
        {
            hp = arr[i].priority;
            q = i;
        }
        else if (hp < arr[i].priority)
        {
            hp = arr[i].priority;
            q = i;
        }
    }
    return q;
}
void dequeue()
{
    int p = peek();
    for (int i = p; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}
int main()
{
    int x = 0;
    while (x < 4)
    {
        cout << "\nOptions:\n";
        cout << "1)Enqueue\n";
        cout << "2)Dequeue\n";
        cout << "3)Peek\n";
        cout << "4)Exit\n";
        cout << "Enter the option for required operation:";
        cin >> x;
        switch (x)
        {
        case 1:
        {
            int a, b;
            cout << "Enter the element:";
            cin >> a;
            cout << "Enter the priority:";
            cin >> b;
            auto start = high_resolution_clock::now();
            enqueue(a, b);
            auto end = high_resolution_clock::now();
            double timetaken = duration<double, std::milli>(end - start).count();
            cout << "Time taken : " << timetaken << " microseconds";
            break;
        }
        case 2:
        {
            auto start = high_resolution_clock::now();
            dequeue();
            auto end = high_resolution_clock::now();
            double timetaken = duration<double, std::milli>(end - start).count();
            cout << "Time taken : " << timetaken << " microseconds";
            break;
        }
        case 3:
        {
            auto start = high_resolution_clock::now();
            int b = peek();
            auto end = high_resolution_clock::now();
            double timetaken = duration<double, std::milli>(end - start).count();
            cout << "Top element: " << arr[b].data;
            cout << "\nTime taken : " << timetaken << " microseconds";
            break;
        }
        case 4:
            return 1;
        }
    }

    return 0;
}