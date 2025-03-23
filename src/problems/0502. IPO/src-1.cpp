#include <vector>
#include <map>
#include <iostream>
using std::vector, std::map;

// Runtime: 403 ms (Beats 5.02 %), Memory: 123.86 MB (Beats 5.31 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        map<int, map<int, vector<int>>> cap_to_pro_to_indices_table;
        map<int, vector<int>> pro_to_indices_table;

        for (int i = 0; i < n; i++)
        {
            cap_to_pro_to_indices_table[capital[i]][profits[i]].push_back(i);
        }

        map<int, map<int, vector<int>>>::iterator it =
            cap_to_pro_to_indices_table.begin();
        for (int i = 0; i < k; i++)
        {
            while (it != cap_to_pro_to_indices_table.end() && it->first <= w)
            {
                // push
                printf("push %d\n", it->first);
                for (auto iter : it->second)
                {
                    pro_to_indices_table[iter.first].insert(
                        pro_to_indices_table[iter.first].end(),
                        iter.second.begin(), iter.second.end());
                }
                it++;
            }

            printf("check\n");
            // check
            for (auto iter2 = pro_to_indices_table.rbegin();
                 iter2 != pro_to_indices_table.rend(); ++iter2)
            {
                if (iter2->second.size() > 0)
                {
                    printf("%d %d\n", w, iter2->first);
                    w += iter2->first;
                    iter2->second.pop_back();
                    break;
                }
            }
        }

        return w;
    }
};
