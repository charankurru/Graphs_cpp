#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pd;
struct myComp
{
    constexpr bool operator()(
        pair<int, int> const &a,
        pair<int, int> const &b)
        const noexcept
    {
        return a.second < b.second;
    }
}; //{2, 15}, {5, 7}, {9, 27}, {18, 29}, {25, 35}
int main()
{
    vector<vector<int>> ladders = {};
    vector<vector<int>> snakes = {{17, 4}, {20, 6}, {34, 12}, {24, 16}, {32, 30}};
    int board = 36;
    board = sqrt(36);

    priority_queue<pd, vector<pd>, myComp> lads[board + 1];
    for (auto each : ladders)
    {
        int level = each[0] <= 6 ? 1 : ceil(each[0] / (float)board);
        lads[level].push({each[0], each[1]});
    }
    for (int i = 0; i < board; i++)
    {
        auto each = lads[i];
        if (lads[i].size() == 0)
            continue;
        cout << i << "==>";
        while (!each.empty())
        {
            auto node = each.top();
            each.pop();
            cout << node.first << " " << node.second << " ";
        }
        cout << endl;
    }
    unordered_map<int, int> mp;
    for (auto each : snakes)
    {
        mp[each[0]] = each[1];
    }
    int curpos = 0;
    int curlevel;
    int count = 0;
    while (curpos != board * board)
    {
        // check if any ladder exits in the current level
        curlevel = curpos <= 6 ? 1 : ceil(curpos / (float)board);
        bool ldfound = false;
        while (!lads[curlevel].empty())
        {
            auto lift = lads[curlevel].top();
            lads[curlevel].pop();
            // check whether you have crossed the ladder point.
            if (lift.first > curpos)
            {
                ldfound = true;
                curpos = lift.second;
                break;
            }
        }
        if (!ldfound)
        {
            //ladder wont exist
            for (int i = 6; i > 0; i--)
            {
                if (mp.find(curpos + i) != mp.end() || curpos + i > board * board)
                    continue;
                curpos += i;
                break;
            }
        }
        count++;
    }
    cout << "Minium dice roles required are " << count << endl;
}