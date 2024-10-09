#include <vector>
#include <set>
#include <unordered_map>
using std::vector, std::set, std::unordered_map;

// Runtime: 95 ms (Beats 35.91 %), Memory: 50.02 MB (Beats 15.61 %).

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        set<int> table;
        for (const auto &a : arr)
        {
            table.insert(a);
        }

        int rank = 1;
        unordered_map<int, int> _map;
        for (auto it = table.begin(); it != table.end(); it++)
        {
            _map[*it] = rank++;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = _map[arr[i]];
        }

        return arr;
    }
};
