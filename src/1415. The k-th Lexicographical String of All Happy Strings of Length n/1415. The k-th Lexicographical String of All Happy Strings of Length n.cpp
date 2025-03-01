#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.73 MB (Beats 99.21 %).

class Solution
{
private:
    void find(const int &n, const int &k, string &curr, int &idx, string &ans)
    {
        if (curr.size() == n)
        {
            idx++;
            if (idx == k)
            {
                ans = curr;
            }
            return;
        }

        for (int i = 0; i < 3; i++)
        {
            if (curr.size() > 0 && 'a' + i == curr.back())
            {
                continue;
            }

            curr += ('a' + i);

            find(n, k, curr, idx, ans);

            if (curr.size() == 0)
            {
                continue;
            }

            curr.pop_back();
        }
        return;
    }

public:
    string getHappyString(int n, int k)
    {
        string curr = "";
        string ans = "";
        int idx;
        find(n, k, curr, idx, ans);
        return ans;
    }
};
