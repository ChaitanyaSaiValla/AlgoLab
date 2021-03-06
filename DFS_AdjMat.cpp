#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
void dfs(vector<vector<int>> &adj, vector<bool> &visited, int st, vector<int> &ans)
{
    visited[st] = 1;
    ans.push_back(st);
    for (int i = 0; i < adj[st].size(); i++)
    {
        if (adj[st][i] && !visited[i])
        {
            dfs(adj, visited, i, ans);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    auto start = high_resolution_clock::now();
    vector<bool> visited(n, 0);
    vector<int> traversal;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(adj, visited, 0, traversal);
    }
    auto end = high_resolution_clock::now();
    for (auto i : traversal)
        cout << i << " ";
    cout << endl;
    double timetaken = duration<double, std::milli>(end - start).count();
    cout << "Time taken : " << timetaken << " microseconds";
}