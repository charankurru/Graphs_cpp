#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> lst;
    int *parent;

public:
    Graph(int v)
    {
        this->V = v;
        this->parent = new int[V + 1];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }
    }
    void addEdge(int u, int v)
    {
        lst.push_back({u, v});
    }

    int find_set(int node)
    {
        if (parent[node] == -1)
            return node;
        return find_set(parent[node]);
    }

    bool union_set(int x, int y)
    {
        int s1 = find_set(x);
        int s2 = find_set(y);
        if (s1 != s2)
        {
            parent[s2] = s1;
            return true; // no cycle
        }
        return false; // false returned when there is an cycle
    }

    bool Contains_Cycle()
    {
        for (auto pr : lst)
        {
            if (!union_set(pr.first, pr.second))
            {
                cout << "At the edge " << pr.first << "-->" << pr.second << endl;
                cout << "There contains cycle";
                return true; // Cycle is there
            }
        }
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    cout << g.Contains_Cycle();
}

// Simple Intution
//Disjoint Set_union mainly contains two functions Union and set
// ==> Theese are used to detect the cycles in the graph
// Operations are performed on a array named parent
// ==> Union function is used to merge two sets
// ==> It uses the find_set method to get parent node and assigns this parent to new sets
// ==> Find_set method is used to get parent of provided node.