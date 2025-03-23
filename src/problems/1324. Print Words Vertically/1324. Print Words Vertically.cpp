#include <string>
#include <vector>
#include <iostream>
using std::string, std::vector, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.59 MB (Beats 86.38 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
public:
    vector<string> printVertically(string s)
    {
        int l = s.size();
        int vec_l = 0, vec_w = 0;

        vector<string> ans;
        string ss = "";

        for (int i = 0, ii = 0, curr_w; i < l; i++)
        {
            if (i == l - 1 || s[i] == ' ')
            {
                if (i == l - 1)
                {
                    ss += s[i];
                }
                ans.push_back(ss);

                ss = "";

                vec_l++;

                if (i == l - 1)
                {
                    curr_w = i + 1 - ii;
                }
                else
                {
                    curr_w = i - ii;
                }
                ii = i + 1;

                if (curr_w > vec_w)
                {
                    vec_w = curr_w;
                }
            }
            else
            {
                ss += s[i];
            }
        }

        int ll = ans.size();
        int m_dim = max(vec_l, vec_w);
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] += string(m_dim - ans[i].size(), ' ');
        }
        for (int i = 0; i < (m_dim - ll); i++)
        {
            ans.push_back(string(m_dim, ' '));
        }

        char c;
        for (int i = 0; i < m_dim; i++)
        {
            for (int j = i + 1; j < m_dim; j++)
            {
                c = ans[i][j];
                ans[i][j] = ans[j][i];
                ans[j][i] = c;
            }
        }

        for (int i = m_dim - 1; i >= 0; i--)
        {
            int j = m_dim - 1;
            while (j >= 0 && ans[i][j] == ' ')
            {
                j--;
            }

            if (j != -1)
            {
                ans[i].erase(ans[i].begin() + j + 1, ans[i].end());
            }
            else
            {
                ans.pop_back();
            }
        }

        return ans;
    }
};
