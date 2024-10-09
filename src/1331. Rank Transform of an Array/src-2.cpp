#include <vector>
#include <map>
using std::vector, std::map;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        map<int, vector<int>> table;
        for (int i = 0; i < arr.size(); i++)
        {
            table[arr[i]].push_back(i);
        }

        int rank = 1;
        for (const auto &t : table)
        {
            for (const auto &i : t.second)
            {
                arr[i] = rank;
            }
            rank++;
        }

        return arr;
    }
};
