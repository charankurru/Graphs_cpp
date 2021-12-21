//This is All pairs shortest path algorithm i.e Floyd Floyd_warshell Algorithm

#include <bits/stdc++.h>
#define INF 10000
using namespace std;

void Floyd_warshell(vector<vector<int>> &dist, int V)
{
    int phases = V;
    for (int p = 0; p < phases; p++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                dist[i][j] = min(dist[i][j], dist[i][p] + dist[p][j]);
}

int main()
{
    vector<vector<int>> graph = {
        {0, INF, -2, INF},
        {4, 0, 3, INF},
        {INF, INF, 0, 2},
        {INF, -1, INF, 0}};

    Floyd_warshell(graph, graph.size());
    cout << "Minimum Distances from each vertex to every other vertex is :" << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}