#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using std::vector, std::string, std::unordered_set, std::unordered_map, std::queue;

// Runtime: 232 ms (Beats 32.84 %), Memory: 169.76 MB (Beats 7.52 %).

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes,
                                  vector<vector<string>> &ingredients,
                                  vector<string> &supplies)
    {
        const int n = recipes.size();

        unordered_map<string, vector<int>> table;
        vector<unordered_set<string>> ingredients_vec(n);
        for (int i = 0; i < n; i++)
        {
            for (const auto &ing : ingredients[i])
            {
                table[ing].push_back(i);
                ingredients_vec[i].insert(ing);
            }
        }

        unordered_set<string> done;
        queue<string> q;
        for (const auto &s : supplies)
        {
            q.push(s);
        }

        vector<string> ans;
        while (!q.empty())
        {
            string s = q.front();
            q.pop();

            for (const auto &idx : table[s])
            {
                ingredients_vec[idx].erase(s);
                if (ingredients_vec[idx].size() == 0)
                {
                    ans.push_back(recipes[idx]);

                    if (done.find(recipes[idx]) == done.end())
                    {
                        done.insert(recipes[idx]);
                        q.push(recipes[idx]);
                    }
                }
            }
        }
        return ans;
    }
};
