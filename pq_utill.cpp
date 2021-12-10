#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> pi;
int main()
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({20, {0, 1}});
    pq.push({10, {1, 2}});
    pq.push({5, {3, 4}});
    while (!pq.empty())
    {
        auto best = pq.top();
        pq.pop();
        cout << best.first << " " << best.second.first << "," << best.second.second << endl;
    }
    return 0;
}