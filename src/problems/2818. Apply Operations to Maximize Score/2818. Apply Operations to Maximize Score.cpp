#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using std::vector, std::stack, std::priority_queue, std::sqrt, std::pair;

// Runtime: 310 ms (Beats 64.02 %), Memory: 164.61 MB (Beats 54.27 %).
// ref: LeetCode Editorial - Approach 1: Monotonic Stack & Priority Queue

class Solution
{
private:
    const int MOD = 1e9 + 7;

    // Helper function to compute the power of a number modulo MOD
    long long power(long long base, long long exponent)
    {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0)
        {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1)
            {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }

public:
    int maximumScore(vector<int> &nums, int k)
    {
        const int n = nums.size();
        vector<int> prime_score(n);

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];

            for (int factor = 2; factor <= sqrt(num); factor++)
            {
                if (num % factor == 0)
                {
                    prime_score[i]++;

                    while (num % factor == 0)
                    {
                        num /= factor;
                    }
                }
            }

            if (num >= 2)
            {
                prime_score[i]++;
            }
        }

        vector<int> prev_dominant(n, -1);
        vector<int> next_dominant(n, n);

        // decreasing prime score index stack
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && prime_score[s.top()] < prime_score[i])
            {
                int t = s.top();
                s.pop();

                next_dominant[t] = i;
            }

            if (!s.empty())
            {
                prev_dominant[i] = s.top();
            }

            s.push(i);
        }

        vector<long long> num_subarr(n);
        for (int i = 0; i < n; i++)
        {
            num_subarr[i] = (long long)(next_dominant[i] - i) * (long long)(i - prev_dominant[i]);
        }

        priority_queue<pair<int, long long>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], num_subarr[i]});
        }

        long long score = 1;
        while (k > 0)
        {
            auto [num, _times] = pq.top();
            pq.pop();

            long long op_times = min((long long)k, _times);

            score = (score * power(num, op_times)) % MOD;

            k -= op_times;
        }
        return score;
    }
};
