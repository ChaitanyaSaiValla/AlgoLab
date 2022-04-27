#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
#define edge pair<int, int>

class Graph
{
private:
    vector<pair<int, edge>> G, T;
    int *parent;
    int V;

public:
    Graph(int V);
    void AddEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void printMST();
};
Graph::Graph(int V)
{
    parent = new int[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}
void Graph::AddEdge(int u, int v, int w)
{
    G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i)
{
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}

void Graph::union_set(int u, int v)
{
    parent[u] = parent[v];
}
void Graph::kruskal()
{
    int i, u1, v1;
    sort(G.begin(), G.end());
    for (i = 0; i < G.size(); i++)
    {
        u1 = find_set(G[i].second.first);
        v1 = find_set(G[i].second.second);
        if (u1 != v1)
        {
            T.push_back(G[i]);
            union_set(u1, v1);
        }
    }
}
void Graph::printMST()
{
    cout << "Edges :" << endl;
    int cost = 0;
    for (int i = 0; i < T.size(); i++)
    {
        cout << T[i].second.first << " - " << T[i].second.second << endl;
        cost += T[i].first;
    }
    cout << "Cost of MST: " << cost << endl;
}
int main()
{
    int v, e, p, q, r;
    cin >> v >> e;
    Graph g(v);
    for (int i = 0; i < e; i++)
    {
        cin >> p >> q >> r;
        g.AddEdge(p, q, r);
    }
    auto start = high_resolution_clock::now();
    g.kruskal();
    auto end = high_resolution_clock::now();
    double timetaken = duration<double, std::milli>(end - start).count();
    g.printMST();
    cout << "Time taken : " << timetaken << " microseconds";
    return 0;
}