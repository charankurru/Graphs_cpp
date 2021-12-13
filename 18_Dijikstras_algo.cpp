#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
class Graph
{
    int V;
    list<pair<int, int>> *lst;
    int *dist;
    priority_queue<pi, vector<pi>, greater<pi>> pq;

public:
    Graph(int v)
    {
        this->V = v;
        this->dist = new int[v];
        this->lst = new list<pair<int, int>>[V];
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX;
    }
    void addEdge(int u, int v, int wt)
    {
        lst[u].push_back({v, wt});
        lst[v].push_back({u, wt});
    }

    void Dijikstras(int start)
    {
        pq.push({0, start});
        dist[start] = 0;
        while (!pq.empty())
        {
            pi curnode = pq.top();
            pq.pop();
            int cur_nodeval = curnode.second;
            for (auto nbr : lst[cur_nodeval])
            {
                int nbr_node = nbr.first;
                int wt_to_reach = nbr.second;
                // if distance of neighbour is already less than the distance when we reach from currnode
                if (dist[nbr_node] < dist[cur_nodeval] + wt_to_reach)
                    continue;

                dist[nbr_node] = dist[cur_nodeval] + wt_to_reach;
                pq.push({dist[nbr_node], nbr_node});
            }
        }

        for (int i = 0; i < V; i++)
            cout << i << " " << dist[i] << endl;
    }
};

int main()
{
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.Dijikstras(0);
    return 0;
}