#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;
int minKey(int key[], bool mst[], int n)
{
    int mn = 1e9, idx;
    for (int i = 0; i < n; i++)
    {
        if ((mst[i] == false) && (key[i] < mn))
            mn = key[i], idx = i;
    }
    return idx;
}
int main()
{
    int n, e;
    cout << "Enter No of Vertices & Edges : ";
    cin >> n >> e;
    int **adj = new int *[n];
    for (int i = 0; i < n; i++)
    {
        adj[i] = new int[n];
    }
    cout << "Enter Edges with weight: \n";
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u][v] = wt;
        adj[v][u] = wt;
    }
    auto start = high_resolution_clock::now();
    int parent[n];
    int key[n];
    bool mstSet[n];
    for (int i = 0; i < n; i++)
        key[i] = 1e9, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;
        for (int v = 0; v < n; v++)
            if ((adj[u][v] != 0) && (mstSet[v] == false) && (adj[u][v] < key[v]))
                parent[v] = u, key[v] = adj[u][v];
    }
    auto end = high_resolution_clock::now();
    double timetaken = duration<double, std::milli>(end - start).count();
    cout << "MST contains : \n";
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << "-" << i << "\t" << adj[parent[i]][i] << "\n";
    }
    cout << "Time taken : " << timetaken << " microseconds";
    return 0;
}