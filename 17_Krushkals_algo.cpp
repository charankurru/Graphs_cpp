#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> pi;
class Graph
{
    int V;
    list<pair<int, int>> *lst;
    int *parent;
    priority_queue<pi, vector<pi>, greater<pi>> pq;

public:
    Graph(int v)
    {
        this->V = v;
        this->parent = new int[v];
        this->lst = new list<pair<int, int>>[V];
        for (int i = 0; i < V; i++)
            parent[i] = -1;
    }
    void addEdge(int u, int v, int wt)
    {
        lst[u].push_back({v, wt});
        lst[v].push_back({u, wt});
        pq.push({wt, {u, v}});
    }

    int find(int x)
    {
        if (parent[x] == -1)
            return x;
        return find(parent[x]);
    }

    int krushMst()
    {
        int mincost = 0;
        vector<pair<int, int>> paths;
        while (!pq.empty())
        {

            auto edge = pq.top();
            pq.pop();
            int wt = edge.first;
            int from = edge.second.first;
            int to = edge.second.second;

            int s1 = find(from);
            int s2 = find(to);
            if (s1 == s2)
                continue;
            else
            {
                cout << "wt" << wt << "from" << from << "to" << to << endl;
                parent[s2] = s1;
            }
            paths.push_back({from, to});
            mincost += wt;
        }
        return mincost;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 4);
    g.addEdge(1, 3, 1);
    g.addEdge(3, 2, 5);
    int cost = g.krushMst();
    cout << "Minimum Cost is " << cost << endl;
}