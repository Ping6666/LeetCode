#include <vector>
using std::vector;

// Runtime: 6 ms (Beats 99.08 %), Memory: 77.76 MB (Beats 99.21 %).

class ProductOfNumbers
{
    vector<int> prefix;

public:
    ProductOfNumbers()
    {
        prefix.clear();
    }

    void add(int num)
    {
        if (num == 0)
        {
            prefix.clear();
        }
        else
        {
            if (prefix.empty())
            {
                prefix.push_back(num);
            }
            else
            {
                prefix.push_back(prefix.back() * num);
            }
        }
    }

    int getProduct(int k)
    {
        int n = prefix.size();

        if (n < k)
        {
            return 0;
        }
        else if (n == k)
        {
            return prefix[n - 1];
        }

        return prefix[n - 1] / prefix[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
