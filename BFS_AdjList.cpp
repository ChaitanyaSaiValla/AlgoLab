#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
vector<int> bfs(vector<vector<int>> &adj, int n)
{
    vector<bool> visited(n, 0);
    vector<int> ans;
    queue<int> q;
    for (int j = 0; j < n; j++)
    {
        if (visited[j])
            continue;
        q.push(j);
        visited[j] = 1;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            visited[curr] = 1;
            ans.push_back(curr);
            for (auto i : adj[curr])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    return ans;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto start = high_resolution_clock::now();
    auto traversal = bfs(adj, n);
    auto end = high_resolution_clock::now();
    for (auto i : traversal)
        cout << i << " ";
    cout << "\n";
    double timetaken = duration<double, std::milli>(end - start).count();
    cout << "Time taken : " << timetaken << " microseconds";
}
