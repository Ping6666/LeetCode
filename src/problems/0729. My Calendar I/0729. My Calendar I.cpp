#include <set>
using std::set, std::pair;

// Runtime: 65 ms (Beats 93.97 %), Memory: 42.72 MB (Beats 59.10 %).

class MyCalendar
{
private:
    set<pair<int, int>> calendar;

public:
    bool book(int start, int end)
    {
        const pair<int, int> event(start, end);

        const auto after = calendar.lower_bound(event);

        if (after != calendar.end() && after->first < end)
        {
            return false;
        }

        if (after != calendar.begin())
        {
            const auto before = prev(after);

            if (before->second > start)
            {
                return false;
            }
        }

        calendar.insert(event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
