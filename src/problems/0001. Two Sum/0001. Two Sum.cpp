#include <map>
#include <vector>
using namespace std;

class Solution
{
    // Runtime: 19 ms (54.71 %), Memory: 12.5 MB (5.91 %).
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int vlength = nums.size();
        vector<int> ansvec;
        if (vlength == 2)
        {
            ansvec.push_back(0);
            ansvec.push_back(1);
            return ansvec;
        }
        map<int, int> hashtable;
        map<int, int>::iterator iter;
        for (int i = 0; i < vlength; i++)
        {
            // num[i] is key, i is value
            hashtable.insert(pair<int, int>(nums[i], i));
        }
        for (int i = 0; i < vlength; i++)
        {
            int currtarget = target - nums[i];
            iter = hashtable.find(currtarget);
            if (iter != hashtable.end() && i != iter->second)
            {
                ansvec.push_back(i);
                ansvec.push_back(iter->second);
                return ansvec;
            }
        }
        return ansvec;
    }
};

/*
class Solution
{
    // Runtime: 746 ms (8.36 %), Memory: 10.3 MB (66.98 %).
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int vlength = nums.size();
        vector<int> ansvec;
        if (vlength == 2)
        {
            ansvec.push_back(0);
            ansvec.push_back(1);
            return ansvec;
        }
        for (int i = 0; i < vlength; i++)
        {
            int currtarget = target - nums[i];
            for (int j = 0; j < vlength; j++)
            {
                if (j == i)
                {
                    continue;
                }
                if (currtarget == nums[j])
                {
                    ansvec.push_back(i);
                    ansvec.push_back(j);
                    return ansvec;
                }
            }
        }
        return ansvec;
    }
};
*/
