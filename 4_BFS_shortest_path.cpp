#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 5}, {5, 6}, {4, 5}, {0, 4}, {3, 4}};
    int v = 7;
    vector<int> adj[v];
    for (auto each : edges)
    {
        adj[each[0]].push_back(each[1]);
        adj[each[1]].push_back(each[0]);
    }
    //Performing BFS
    vector<bool> vis(v, false);
    queue<pair<int, int>> qu;
    qu.push({0, 0});
    vector<int> dist(v, -1);
    while (!qu.empty())
    {
        auto node = qu.front();
        cout << node.first << " " << node.second << endl;
        qu.pop();
        vis[node.first] = true;
        dist[node.first] = node.second;
        for (auto child : adj[node.first])
            if (!vis[child])
                qu.push({child, node.second + 1});
    }
}