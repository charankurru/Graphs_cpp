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

    void dfsHelper(int node, bool *visited, int par, int color, vector<int> &colorTrack, bool &iscycle)
    {
        visited[node] = true;
        colorTrack[node] = color;
        //make a dfs call on all its unvisited neighbours
        for (int nbr : l[node])
        {
            if (nbr != par && visited[nbr] && colorTrack[node] == colorTrack[nbr])
            {
                iscycle = true;
            }
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited, node, color ^ 1, colorTrack, iscycle);
            }
        }
    }

    void dfs(int source)
    {
        bool *visited = new bool[V]{0};
        vector<int> colorTrack(V, 0);
        bool iscycle = false;
        dfsHelper(source, visited, -1, 0, colorTrack, iscycle);
        if (iscycle)
            cout << "Given graph has cycles with odd number of vertices " << endl;
        else
            cout << "Given graph may has cycles but with no odd number of vertices " << endl;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 0);
    g.addEdge(3, 0);
    g.dfs(0);
    return 0;
}