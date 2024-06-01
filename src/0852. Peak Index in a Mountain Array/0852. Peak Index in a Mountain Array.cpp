#include <stdio.h>

#include <vector>

using namespace std;

class Solution
{
    // Runtime: 104 ms (Beats 98.02 %), Memory: 59.55 MB (Beats 88.25 %).

    // You must solve it in O(log(arr.length)) time complexity.

public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int l = 0, r = arr.size() - 1;
        int mid;

        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1])
            {
                r = mid;
                // r = mid - 1;
            }
            else
            {
                l = mid;
                // l = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> arr;

    Solution s;
    int idx;

    arr = {0, 1, 0};
    s = Solution();
    idx = s.peakIndexInMountainArray(arr);
    printf("%d\n", idx);

    arr = {0, 2, 1, 0};
    s = Solution();
    idx = s.peakIndexInMountainArray(arr);
    printf("%d\n", idx);

    arr = {0, 10, 5, 2};
    s = Solution();
    idx = s.peakIndexInMountainArray(arr);
    printf("%d\n", idx);

    arr = {3, 5, 3, 2, 0};
    s = Solution();
    idx = s.peakIndexInMountainArray(arr);
    printf("%d\n", idx);

    return 0;
}
