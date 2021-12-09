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
        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ==> ";
            q.pop();
            for (auto ele : l[node])
            {
                indeg[ele]--;
                if (indeg[ele] == 0)
                    q.push(ele);
            }
        }
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