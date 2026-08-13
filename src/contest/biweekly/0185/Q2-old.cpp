#include <vector>

using std::vector;

class Solution
{
public:
    int minLights(vector<int> &lights)
    {
        const int n = lights.size();
        vector<bool> visible = vector<bool>(n, false);

        for (int i = 0; i < n; i++)
        {
            if (lights[i] == 0)
            {
                continue;
            }
            visible[i] = true;

            // right
            for (int j = 1; j <= lights[i] && i + j < n; j++)
            {
                if (i - j >= 0 && lights[i - j] > lights[i] + j)
                {
                    break;
                }
                visible[i + j] = true;
            }

            // left
            for (int j = 1; j <= lights[i] && i - j >= 0; j++)
            {
                if (i - j >= 0 && lights[i - j] > lights[i] - j)
                {
                    break;
                }
                visible[i - j] = true;
            }
        }

        int c = 0;
        int zero_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (visible[i])
            {
                // printf("1");
                if (zero_count != 0)
                {
                    zero_count = 0;
                    c++;
                }
            }
            else
            {
                // printf("0");
                zero_count++;
                if (zero_count == 3)
                {
                    zero_count = 0;
                    c++;
                }
            }
        }
        if (zero_count != 0)
        {
            zero_count = 0;
            c++;
        }
        return c;
    }
};
