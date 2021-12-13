#include <bits/stdc++.h>
using namespace std;

void bellmanFord(vector<vector<int>> edges, int src, int V, vector<int> &dist)
{
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
                dist[v] = dist[u] + wt;
        }
    }

    // Check for Negative cycles
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
        {
            cout << "Negative cycles detected" << endl;
            return;
        }
    }
}

int main()
{
    int E, V;
    cin >> E >> V;
    vector<vector<int>> edges;
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    vector<int> dist(V + 1, INT_MAX);
    bellmanFord(edges, 1, V, dist);
    dist[0] = 0;
    for (int i = 1; i <= V; i++)
    {
        cout << "Distance for node " << i << " from source node is  ==> " << dist[i] << endl;
    }
}