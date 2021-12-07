#include <iostream>
#include <list>
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

    void addEdge(int i, int j, bool undir = false)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void dfsHelper(int node, bool *visited, vector<bool> path, bool &iscycle)
    {
        visited[node] = true;
        path[node] = true;
        //make a dfs call on all its unvisited neighbours
        for (int nbr : l[node])
        {
            // cout << nbr << endl;
            if (path[nbr] && visited[nbr])
                iscycle = true;
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited, path, iscycle);
            }
        }
        path[node] = false;
    }

    void dfs(int source, int size)
    {
        bool *visited = new bool[V]{0};
        vector<bool> path(size, false);
        bool iscycle = false;
        dfsHelper(source, visited, path, iscycle);
        cout << iscycle << endl;
        if (iscycle)
            cout << "Given graph has cycles" << endl;
        else
            cout << "Given graph has No cycles" << endl;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.dfs(0, 4);
    return 0;
}