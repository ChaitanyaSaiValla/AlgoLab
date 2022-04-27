#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int start_vertex, end_vertex;
    int weight;
};

void bellman_ford(struct edge a[], int e, int n)
{
    int dist[n], k = 1;
    for (int k = 0; k < n; k++)
        dist[k] = INT_MAX;
    dist[0] = 0;
    while (k < n)
    {
        for (int i = 0; i < e; i++)
        {
            if (dist[a[i].start_vertex] + a[i].weight < dist[a[i].end_vertex])
                dist[a[i].end_vertex] = dist[a[i].start_vertex] + a[i].weight;
        }
        k++;
    }
    cout << "Shortest distances of All Vertex from 1st vertex: ";
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int n, e;
    cin >> n >> e;
    struct edge a[e];
    for (int i = 0; i < e; i++)
        cin >> a[i].start_vertex >> a[i].end_vertex >> a[i].weight;
    bellman_ford(a, e, n);
    return 0;
}
/*
6 9
0 1 6
0 2 4
0 3 5
1 4 -1
2 1 -2
2 4 3
3 2 -2
3 5 -1
4 5 3
*/