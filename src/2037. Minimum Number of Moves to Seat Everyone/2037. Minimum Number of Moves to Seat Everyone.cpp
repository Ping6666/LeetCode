#include <vector>
#include <algorithm>
using std::vector, std::sort;

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 20.83 MB (Beats 85.21 %).

public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        int n = seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += abs(seats[i] - students[i]);
        }

        return ans;
    }
};
