#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

typedef struct node
{
    int data;
    int priority;
    struct node *next;
} Node;
Node *head = NULL;
void enqueue(int data, int priority)
{
    Node *temp, *q;

    temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->priority = priority;
    if (head == NULL || priority > head->priority)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        q = head;
        while (q->next != NULL && q->next->priority <= priority)
            q = q->next;
        temp->next = q->next;
        q->next = temp;
    }
}
int peek()
{
    return head->data;
}

void dequeue()
{
    Node *temp;
    if (head == NULL)
        printf("Queue Underflow\n");
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main()
{
    int x = 0;
    Node *p = NULL;
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
            auto start1 = high_resolution_clock::now();
            enqueue(a, b);
            auto end1 = high_resolution_clock::now();
            double timetaken = duration<double, std::milli>(end1 - start1).count();
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
            cout << "Top element: " << b;
            cout << "\nTime taken : " << timetaken << " microseconds";
            break;
        }
        case 4:
            return 1;
        }
    }

    return 0;
}