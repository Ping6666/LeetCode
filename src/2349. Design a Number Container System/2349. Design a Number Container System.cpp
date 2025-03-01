#include <unordered_map>
#include <set>
using std::unordered_map, std::set;

// Runtime: 99 ms (Beats 82.81 %), Memory: 195.74 MB (Beats 71.56 %).

class NumberContainers
{
    unordered_map<int, int> idx_num;
    unordered_map<int, set<int>> num_idx;

public:
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        if (idx_num.find(index) != idx_num.end())
        {
            // hit
            int t = idx_num[index];

            num_idx[t].erase(index);
            if (num_idx[t].empty())
            {
                num_idx.erase(t);
            }
        }

        // replace
        idx_num[index] = number;
        num_idx[number].insert(index);
    }

    int find(int number)
    {
        if (num_idx.find(number) == num_idx.end())
        {
            return -1;
        }

        return *num_idx[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
