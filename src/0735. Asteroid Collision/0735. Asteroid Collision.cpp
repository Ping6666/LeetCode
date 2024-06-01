#include <stdio.h>

#include <vector>

using namespace std;

bool checkSameSign(int a, int b)
{
    // problem's constraint a, b will not be zero

    return ((a > 0) == (b > 0));
}

class Solution
{
    // Runtime: 13 ms (Beats 77.16 %), Memory: 17.1 MB (Beats 99.94 %).

public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {

        vector<int> remains;

        int n = asteroids.size();

        for (int i = 0; i < n; i++)
        {
            if (remains.empty() || remains.back() < 0 || checkSameSign(remains.back(), asteroids[i]))
            {
                // if 1~3 happened any do things below
                //   1. there has no previous asteroid
                //   2. previous asteroid fly left
                //   3.previous asteroid and current asteroid fly in different direction

                remains.push_back(asteroids[i]);
            }
            else
            {
                int collision = remains.back() + asteroids[i];

                if (collision == 0)
                {
                    remains.pop_back();
                }
                else if (checkSameSign(collision, asteroids[i]))
                {
                    remains.pop_back();
                    i--;
                }
                else
                {
                    // do nothing
                }
            }
        }

        return remains;
    }
};

void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main()
{
    vector<int> asteroids;

    Solution s;
    vector<int> ans;

    asteroids = {5, 10, -5};
    s = Solution();
    ans = s.asteroidCollision(asteroids);
    printVector(ans);

    asteroids = {8, -8};
    s = Solution();
    ans = s.asteroidCollision(asteroids);
    printVector(ans);

    asteroids = {10, 2, -5};
    s = Solution();
    ans = s.asteroidCollision(asteroids);
    printVector(ans);

    asteroids = {-2, -1, 1, 2};
    s = Solution();
    ans = s.asteroidCollision(asteroids);
    printVector(ans);

    return 0;
}
