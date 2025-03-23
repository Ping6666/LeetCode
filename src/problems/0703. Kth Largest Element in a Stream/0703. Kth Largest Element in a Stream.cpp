#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::greater;

// Runtime: 19 ms (Beats 95.63 %), Memory: 24.77 MB (Beats 39.10 %).

class KthLargest
{
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;

        for (int n : nums)
        {
            add(n);
        }
    }

    int add(int val)
    {
        if (this->heap.size() < k || this->heap.top() < val)
        {
            this->heap.push(val);
            if (this->heap.size() > k)
            {
                this->heap.pop();
            }
        }

        return this->heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
