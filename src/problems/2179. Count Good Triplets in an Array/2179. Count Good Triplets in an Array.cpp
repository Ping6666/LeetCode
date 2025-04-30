#include <vector>
using std::vector;

// Runtime: 11 ms (Beats 99.39 %), Memory: 88.06 MB (Beats 82.73 %).
// ref.: LeetCode Eidtorial - Approach 1: Binary Indexed Tree

struct FenwickTree
{
    int _size;
    vector<int> tree;

    FenwickTree(int l)
    {
        _size = l;
        tree.resize(l + 1, 0);
    }

    void update(int idx, int v)
    {
        // start from 1
        idx++;

        while (idx <= _size)
        {
            tree[idx] += v;
            idx += idx & -idx;
        }
    }

    int query(int idx)
    {
        // start from 1
        idx++;

        int ans = 0;
        while (idx > 0)
        {
            ans += tree[idx];
            idx -= idx & -idx;
        }
        return ans;
    }
};

class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        const int n = nums1.size();

        vector<int> pos2(n);
        for (int i = 0; i < n; i++)
        {
            pos2[nums2[i]] = i;
        }

        vector<int> idx2_idx1(n);
        for (int i = 0; i < n; i++)
        {
            idx2_idx1[pos2[nums1[i]]] = i;
        }

        FenwickTree *ft = new FenwickTree(n);

        long long ans = 0;
        for (int idx2 = 0, idx1 = 0; idx2 < n; idx2++)
        {
            idx1 = idx2_idx1[idx2];

            int l = ft->query(idx1);
            int r = ((n - 1) - idx1) - (idx2 - l);

            ans += (long long)l * r;

            ft->update(idx1, 1);
        }
        return ans;
    }
};
