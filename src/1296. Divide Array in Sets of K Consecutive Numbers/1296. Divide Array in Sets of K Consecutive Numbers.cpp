#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using std::vector, std::map, std::unordered_map, std::sort;

class Solution
{
    // Runtime: 67 ms (Beats 98.11 %), Memory: 53.35 MB (Beats 80.79 %).
    // same question as q.0846

public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        // magic
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        if ((k > nums.size()) || ((nums.size() % k) != 0))
        {
            return false;
        }
        else if (k == 1)
        {
            return true;
        }

        sort(nums.begin(), nums.end());

        unordered_map<int, int> table;
        for (auto n : nums)
        {
            table[n]++;
        }

        for (auto n : nums)
        {
            if (table[n] == 0)
            {
                continue;
            }

            int freq;
            freq = table[n];
            for (int i = n; i < n + k; i++)
            {
                if (table[i] < freq)
                {
                    return false;
                }

                table[i] -= freq;
            }
        }

        return true;
    }
};

class Solution
{
    // Runtime: 101 ms (Beats 88.63 %), Memory: 53.37 MB (Beats 80.79 %).
    // same question as q.0846

public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        // magic
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        int l = nums.size();

        if ((k > l) || ((l % k) != 0))
        {
            return false;
        }
        else if (k == 1)
        {
            return true;
        }

        map<int, int> table;
        for (auto n : nums)
        {
            table[n]++;
        }

        std::map<int, int>::iterator it;
        int v, n;

        while (table.size() > 0)
        {
            it = table.begin();
            v = it->first;
            n = it->second;
            table.erase(v);

            for (int i = 1; i < k; i++)
            {
                v++;
                it = table.find(v);

                if (it == table.end() || it->second < n)
                {
                    // not found next or the frequency of next
                    return false;
                }
                it->second -= n;

                if (it->second == 0)
                {
                    table.erase(v);
                }
            }
        }

        return true;
    }
};

class Solution
{
    // Runtime: 1362 ms (Beats 5.01 %), Memory: 39.15 MB (Beats 99.73 %).
    // in-place, same question as q.0846

    // since the nums length was too large `1 <= k <= nums.length <= 105`
    // therefore the runtime performance worse than q.0846

public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        // magic
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        int l = nums.size();

        if ((k > l) || ((l % k) != 0))
        {
            return false;
        }
        else if (k == 1)
        {
            return true;
        }

        sort(nums.begin(), nums.end());

        int count, curr_value;
        while (l > 0)
        {
            count = 1;
            curr_value = nums[0];

            // remove item
            nums.erase(nums.begin() + 0);
            l--;

            for (int idx = 0; idx < l && count < k; idx++)
            {
                // init idx = 0 since the front has been removed

                if (curr_value + 1 == nums[idx])
                {
                    // consecutive
                    curr_value++;
                    count++;

                    // remove item
                    nums.erase(nums.begin() + idx);
                    l--;
                    idx--;
                }
            }

            if (count != k)
            {
                return false;
            }
        }

        return true;
    }
};
