#include <stdio.h>

#include <string>
#include <vector>
#include <bitset>
#include <limits> // numeric_limits
#include <unordered_map>

using namespace std;

class Solution
{
    // Runtime: 98 ms (Beats 65.81 %), Memory: 9.6 MB (Beats 88.39 %).

    // use __builtin_popcountll can be faster than std::bitset::count

public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        int n = people.size();
        int m = req_skills.size();

        unordered_map<string, int> skillid_map;

        for (int i = 0; i < m; i++)
        {
            skillid_map[req_skills[i]] = i;
        }

        vector<int> people_skillid_bitmask(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < people[i].size(); j++)
            {
                people_skillid_bitmask[i] |= (1 << skillid_map[people[i][j]]);
            }
        }

        int dp_size = (1 << m);
        vector<long long> dp(dp_size, (1LL << n) - 1);
        // set all skills that require all people to participate in
        // store the skill that require some bitmask of people

        dp[0] = 0; // init value

        const int n_bit = numeric_limits<long long>::digits;

        for (int i = 0; i < dp_size; i++)
        {
            // i for the curr_skill bitmask

            for (int j = 0; j < n; j++)
            {
                // j for the curr_people id

                int skill_shortage = i & (~people_skillid_bitmask[j]);

                if (skill_shortage != i)
                {
                    // if the current people has at least one skill in current skill bitmask

                    long long new_dp = dp[skill_shortage] | (1LL << j);

                    bitset<n_bit> new_dp_bs(new_dp);
                    bitset<n_bit> curr_dp_bs(dp[i]);

                    if (new_dp_bs.count() < curr_dp_bs.count())
                    {
                        dp[i] = new_dp;
                    }
                }
            }
        }

        long long ans_dp = dp[dp_size - 1];
        vector<int> team;

        for (int i = 0; i < n; i++)
        {
            if ((ans_dp >> i) & 1)
            {
                team.push_back(i);
            }
        }

        return team;
    }
};

void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main()
{
    vector<string> req_skills;
    vector<vector<string>> people;

    Solution s;
    vector<int> ans;

    req_skills = {"java", "nodejs", "reactjs"};
    people = {{"java"}, {"nodejs"}, {"nodejs", "reactjs"}};
    s = Solution();
    ans = s.smallestSufficientTeam(req_skills, people);
    printVector(ans);

    req_skills = {"algorithms", "math", "java", "reactjs", "csharp", "aws"};
    people = {{"algorithms", "math", "java"}, {"algorithms", "math", "reactjs"}, {"java", "csharp", "aws"}, {"reactjs", "csharp"}, {"csharp", "math"}, {"aws", "java"}};
    s = Solution();
    ans = s.smallestSufficientTeam(req_skills, people);
    printVector(ans);

    return 0;
}
