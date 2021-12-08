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

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    bool dfsHelper(int node, bool *visited, int par)
    {
        visited[node] = true;

        //make a dfs call on all its unvisited neighbours
        for (int nbr : l[node])
        {
            if (nbr != par && visited[nbr])
                return true;
            if (!visited[nbr])
            {
                return dfsHelper(nbr, visited, node);
            }
        }
        return false;
    }

    void dfs(int source)
    {
        bool *visited = new bool[V]{0};
        if (dfsHelper(source, visited, -1))
            cout << "Given graph has cycles" << endl;
        else
            cout << "Given graph has No cycles" << endl;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.dfs(1);
    return 0;
}