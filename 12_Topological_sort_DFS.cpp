#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool dir = true)
    {
        l[x].push_back(y);
        if (!dir)
            l[y].push_back(x);
    }

    void dfs_helper(int node, vector<bool> &vis, vector<int> &ordered)
    {
        vis[node] = true;
        for (int nbr : l[node])
        {
            if (!vis[nbr])
                dfs_helper(nbr, vis, ordered);
        }
        ordered.push_back(node);
    }

    void topologicalSort()
    {
        vector<int> indeg(V, 0);
        for (int i = 0; i < V; i++)
            for (int ele : l[i])
                indeg[ele]++;
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        vector<bool> vis(V, false);
        vector<int> order;
        while (!q.empty())
        {
            int curnode = q.front();
            q.pop();
            if (!vis[curnode])
                dfs_helper(curnode, vis, order);
        }
        for (int i = order.size() - 1; i > -1; i--)
            cout << order[i] << " ==> ";
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    cout << "Dependencies are in the Order,i.e after performing topologicalSorting" << endl;
    g.topologicalSort();
}