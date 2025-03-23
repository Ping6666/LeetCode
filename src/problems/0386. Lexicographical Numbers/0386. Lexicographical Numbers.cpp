#include <vector>
using std::vector;

// Runtime: 3 ms (Beats 94.22 %), Memory: 12.36 MB (Beats 93.86 %).

class Solution
{
private:
    int getNum(vector<int> &vec)
    {
        int ret = 0;
        for (const auto &n : vec)
        {
            ret *= 10;
            ret += n;
        }

        return ret;
    }

public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;

        int curr_num;
        vector<int> curr_vec = {1};

        for (int i = 0; i < n; i++)
        {
            curr_num = getNum(curr_vec);
            ans.push_back(curr_num);

            // try to push back
            if (curr_num * 10 <= n)
            {
                curr_vec.push_back(0);
            }
            else
            {
                while (!curr_vec.empty() && (curr_vec.back() == 9 || curr_num == n))
                {
                    curr_vec.pop_back();
                    curr_num = getNum(curr_vec);
                }

                if (!curr_vec.empty())
                {
                    curr_vec.back()++;
                }
            }
        }

        return ans;
    }
};
