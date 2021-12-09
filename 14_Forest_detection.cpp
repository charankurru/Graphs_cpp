#include <bits/stdc++.h>
using namespace std;
int find(int, map<int, int> &);

int find(int x, map<int, int> &par)
{
    if (par[x] == -1)
        return x;
    return find(par[x], par);
}
void union_set(int x, int y, map<int, int> &par)
{
    int s1 = find(x, par);
    int s2 = find(y, par);
    if (s1 != s2)
        par[s2] = s1;
}

int main()
{
    vector<vector<int>> query = {{0, 1}, {0, 2}, {2, 3}, {4, 5}};
    map<int, int> parentmap;
    for (auto inn : query)
    {
        parentmap[inn[0]] = -1;
        parentmap[inn[1]] = -1;
    }
    for (auto inn : query)
    {
        union_set(inn[0], inn[1], parentmap);
    }
    // Check for Trees ,i.e Iterare over the parent map find number of -1 indicates root node.
    int c = 0;
    for (auto pair : parentmap)
    {
        if (pair.second == -1)
            c++;
    }
    if (c > 1)
        cout << "Yes Collection of Trees is formed with givenn edges" << endl;
    else
        cout << "No Collection of Trees Given edges form single graph";
}