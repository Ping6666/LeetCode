#include <vector>
using std::vector, std::pair, std::max, std::min;

// Runtime: 77 ms (Beats 86.13 %), Memory: 37.75 MB (Beats 99.06 %).

class MyCalendarTwo
{
private:
    vector<pair<int, int>> booking_one;
    vector<pair<int, int>> booking_two;

    bool overlap(int s1, int e1, int s2, int e2, int &s, int &e)
    {
        s = max(s1, s2);
        e = min(e1, e2);
        return max(s1, s2) < min(e1, e2);
    }

public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        int s, e;
        for (const auto &b : booking_two)
        {
            if (overlap(b.first, b.second, start, end, s, e))
            {
                return false;
            }
        }

        for (const auto &b : booking_one)
        {
            if (overlap(b.first, b.second, start, end, s, e))
            {
                booking_two.emplace_back(s, e);
            }
        }

        booking_one.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
