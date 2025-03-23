#include <string>
#include <unordered_set>
using std::string, std::unordered_set;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.80 MB (Beats 92.23 %).
// ref.: LeetCode Editorial - Approach 2: Optimized Recursion

class Solution
{
private:
    void find(int &count, int arr[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] == 0)
            {
                continue;
            }

            count++;
            arr[i]--;
            find(count, arr);
            arr[i]++;
        }
    }

public:
    int numTilePossibilities(string tiles)
    {
        int arr[26] = {0};
        for (const auto &c : tiles)
        {
            arr[c - 'A']++;
        }

        int ans = 0;
        find(ans, arr);
        return ans;
    }
};
