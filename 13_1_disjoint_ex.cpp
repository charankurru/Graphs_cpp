#include <bits/stdc++.h>
using namespace std;
int find(int, vector<int> &);
bool find_set(int x, int y, vector<int> &par)
{
    if (find(x, par) == find(y, par))
        return true;
    return false;
}
int find(int x, vector<int> &par)
{
    if (par[x] == -1)
        return x;
    return find(par[x], par);
}
void union_set(int x, int y, vector<int> &par)
{
    int s1 = find(x, par);
    int s2 = find(y, par);
    if (s1 != s2)
        par[s2] = s1;
}
vector<bool> dsu(vector<vector<int>> query)
{
    vector<int> parent(100000, -1);
    vector<bool> res;
    for (auto inn : query)
    {
        int type = inn[0];
        int u = inn[1];
        int v = inn[2];
        if (type == 1)
            union_set(u, v, parent);
        if (type == 2)
            res.push_back(find_set(u, v, parent));
    }
    return res;
}
int main()
{
    vector<vector<int>> query = {{1, 1, 2}, {1, 1, 3}, {2, 1, 4}, {2, 2, 3}};
    vector<bool> ans = dsu(query);
    for (auto each : ans)
        cout << each << " ";
}