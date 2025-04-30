#include <vector>
using std::vector;

// TLE (Time Limit Exceeded)
// 773 / 782 testcases passed

class Solution
{

private:
    // bool can_cut(int cr, int k)
    // {
    //     return false;
    // }

    long long compute(const vector<int> &nums, const int r, const int k)
    {
        const int n = nums.size();

        long long ans = 0;
        long long cr;
        for (int i = 0; i < n; i++)
        {
            cr = nums[i];
            if (cr == r)
            {
                ans++;
            }

            for (int j = i + 1; j < n; j++)
            {
                cr = (cr * nums[j]) % k;
                if (cr == r)
                {
                    ans++;
                }
            }
        }

        /*
        int _l = 0, _r = 0;
        long long cr = -1;
        while (_l < n)
        {
            cr = nums[_l];
            while (_r < n)
            {
                if (cr % k == r)
                {
                    ans++;
                }
                // else if (can_cut(cr, k))
                // {
                //     break;
                // }

                _r++;
                if (_r >= n)
                {
                    break;
                }
                cr = (cr * nums[_r]) % k;
            }

            _l++;
            _r = _l;
        }
        */
        return ans;
    }

public:
    vector<long long> resultArray(vector<int> &nums, int k)
    {
        const int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums[i] %= k;
        }

        if (k == 1)
        {
            return {((n + 1) * n / 2)};
        }

        // k is 2, 3, 4, 5

        vector<long long> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(compute(nums, i, k));
        }
        return ans;
    }
};
