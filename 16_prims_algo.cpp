#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int V;
    vector<pair<int, int>> *lst;

public:
    Graph(int v)
    {
        this->V = v;
        this->lst = new vector<pair<int, int>>[V];
        cout << "Graph created \n";
        // This is an adjacency list with formated
        // [[{nbr1,wt1},{nbr2,wt2},{nbr3,wt3}],[{nbr1,wt1},{nbr2,wt2}],......]
        // index = vertices;
    }

    void addEdge(int u, int v, int wt)
    {
        lst[u].push_back({v, wt});
        lst[v].push_back({u, wt});
    }
    int PrimsMST(int start)
    {
        vector<int> path;
        int mincost = 0;
        vector<bool> vis(this->V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({start, 0});
        while (!pq.empty())
        {
            pair<int, int> best = pq.top();
            pq.pop();
            int dest = best.second;
            int wt = best.first;
            if (vis[dest])
                continue;
            mincost += wt;
            vis[dest] = true;
            path.push_back(dest);
            for (auto nbr : lst[dest])
            {
                if (!vis[nbr.first])
                    pq.push({nbr.second, nbr.first});
            }
        }
        cout << "The path visited is ";
        for (int el : path)
            cout << el << " ==> ";
        cout << "\n";
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
    int cost = g.PrimsMST(0);
    cout << "Minimum Cost is " << cost << endl;
}
