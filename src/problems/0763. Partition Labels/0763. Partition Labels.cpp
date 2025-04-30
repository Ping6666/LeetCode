#include <vector>
#include <string>
#include <algorithm>
using std::vector, std::string, std::sort, std::pair, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 8.69 MB (Beats 97.09 %).

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int arr[26][2] = {0};
        for (int i = 0; i < 26; i++)
        {
            arr[i][0] = arr[i][1] = -1;
        }

        // for (int i = 0; i < 26; i++)
        // {
        //     printf("%d %d %d\n", i, arr[i][0], arr[i][1]);
        // }

        const int n = s.size();
        for (int i = 0; i < n; i++)
        {
            char ii = s[i] - 'a';

            if (arr[ii][0] == -1)
            {
                arr[ii][0] = arr[ii][1] = i;
            }
            else
            {
                arr[ii][1] = i;
            }
        }

        vector<pair<int, int>> table;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i][0] != -1 && arr[i][1] != -1)
            {
                // valid
                table.push_back({arr[i][0], arr[i][1]});
            }
        }
        sort(table.begin(), table.end());

        // for (const auto &t : table)
        // {
        //     printf("%d %d\n", t.first, t.second);
        // }
        // printf("\n");

        vector<int> ans;
        int _start = 0, _end = 0;
        for (const auto &t : table)
        {
            // printf("%d %d %d %d\n", _start, _end, t.first, t.second);
            if (t.first > _end)
            {
                ans.push_back(_end - _start + 1);
                while (t.first - 1 > _end)
                {
                    ans.push_back(1);
                    _end++;
                }
                _start = t.first;
            }
            _end = max(_end, t.second);
            // printf("%d %d %d %d\n", _start, _end, t.first, t.second);
        }

        // last part
        if (_end - _start + 1 > 0)
        {
            ans.push_back(_end - _start + 1);
        }
        // remain part
        while (n - 1 > _end)
        {
            ans.push_back(1);
            _end++;
        }

        return ans;
    }
};
