#include <bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>> &graph, int s, int v)
{
    vector<int> vertex;
    for (int i = 0; i < v; i++)
        if (i != s)
            vertex.push_back(i);
    int ans = INT_MAX;
    do
    {
        int j = s;
        int x = 0;
        for (int i = 0; i < vertex.size(); i++)
        {
            x += graph[j][vertex[i]];
            j = vertex[i];
        }
        x += graph[j][s];
        ans = min(ans, x);
    } while (next_permutation(vertex.begin(), vertex.end()));
    return ans;
}
int main()
{
    int v;
    cin >> v;
    vector<vector<int>> graph(v, vector<int>(v));
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            cin >> graph[i][j];
    cout << "Minimum cost:" << tsp(graph, 0, v) << endl;
}
/*
4
0 5 10 15
5 0 30 20
10 30 0 25
15 20 25 0
*/