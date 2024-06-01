#include <stdio.h>

#include <climits> // INT_MIN
#include <vector>
#include <algorithm> // sort

using namespace std;

bool sorter(const vector<int> &a, const vector<int> &b)
{
    // content in vector is [start, end]
    // intervals is [start, end) in mathamatical interval expression

    return a[1] < b[1];

    /*
    if (a[1] != b[1])
    {
        return a[1] < b[1];
    }

    return a[0] < b[0];
    */
}

class Solution
{
    // Runtime: 458 ms (Beats 84.25 %), Memory: 89.60 MB (Beats 94.24 %).

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int t = INT_MIN;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), sorter);

        int counter = n;

        for (int i = 0; i < n; i++)
        {
            if (t <= intervals[i][0])
            {
                t = intervals[i][1];
                counter--;
            }
        }

        return counter;
    }
};

void print2DVector(vector<vector<int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            printf("%d ", vec[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    vector<vector<int>> intervals;

    Solution s;
    int ans;

    intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    s = Solution();
    ans = s.eraseOverlapIntervals(intervals);
    printf("%d\n", ans);

    intervals = {{1, 2}, {1, 2}, {1, 2}};
    s = Solution();
    ans = s.eraseOverlapIntervals(intervals);
    printf("%d\n", ans);

    intervals = {{1, 2}, {2, 3}};
    s = Solution();
    ans = s.eraseOverlapIntervals(intervals);
    printf("%d\n", ans);

    return 0;
}
