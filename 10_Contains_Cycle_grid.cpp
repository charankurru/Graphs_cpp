#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid = {{'c', 'c', 'c', 'a'}, {'c', 'd', 'c', 'c'}, {'c', 'c', 'e', 'c'}, {'f', 'c', 'c', 'c'}};
int rows = grid.size();
int cols = grid[0].size();
vector<vector<int>> vis(rows, vector<int>(cols, 0));
vector<vector<int>> data(rows, vector<int>(cols, 0));
void display()
{
    for (auto inn : vis)
    {
        for (auto ele : inn)
            cout << ele << " ";
        cout << "\n";
    }
    cout << "\n";
    for (auto inn : data)
    {
        for (auto ele : inn)
            cout << ele << " ";
        cout << "\n";
    }
}

bool isvalid(int x, int y)
{
    if (x < 0 || y < 0 || x >= rows || y >= cols)
        return false;
    return true;
}

bool dfs(char ch, int x, int y, int dist)
{
    //leftside
    if (isvalid(x, y - 1) && grid[x][y - 1] == ch)
    {
        if (!vis[x][y - 1])
        {
            vis[x][y - 1] = 1;
            data[x][y - 1] = dist;
            if (dfs(ch, x, y - 1, dist + 1))
                return true;
        }
        else
        {
            if (abs(data[x][y - 1] - data[x][y]) > 2)
                return true;
        }
    }

    // rightside
    if (isvalid(x, y + 1) && grid[x][y + 1] == ch)
    {
        if (!vis[x][y + 1])
        {
            vis[x][y + 1] = 1;
            data[x][y + 1] = dist;
            if (dfs(ch, x, y + 1, dist + 1))
                return true;
        }
        else
        {
            if (abs(data[x][y + 1] - data[x][y]) > 2)
                return true;
        }
    }
    // up
    if (isvalid(x - 1, y) && grid[x - 1][y] == ch)
    {
        if (!vis[x - 1][y])
        {
            vis[x - 1][y] = 1;
            data[x - 1][y] = dist;
            if (dfs(ch, x - 1, y, dist + 1))
                return true;
        }
        else
        {
            if (abs(data[x - 1][y] - data[x][y]) > 2)
                return true;
        }
    }
    //down
    if (isvalid(x + 1, y) && grid[x + 1][y] == ch)
    {
        if (!vis[x + 1][y])
        {
            vis[x + 1][y] = 1;
            data[x + 1][y] = dist;
            if (dfs(ch, x + 1, y, dist + 1))
                return true;
        }
        else
        {
            if (abs(data[x + 1][y] - data[x][y]) > 2)
                return true;
        }
    }
    data[x][y] = 0;
    return false;
}
int main()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!vis[i][j])
            {
                if (dfs(grid[i][j], i, j, 2))
                {
                    cout << "True" << endl;
                    display();
                    return 0;
                }
            }
        }
    }

    return 0;
}