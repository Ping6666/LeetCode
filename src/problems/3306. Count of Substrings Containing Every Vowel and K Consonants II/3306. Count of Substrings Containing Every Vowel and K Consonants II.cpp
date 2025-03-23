#include <string>
#include <unordered_map>
using std::string, std::unordered_map;

// Runtime: 196 ms (Beats 53.42 %), Memory: 48.52 MB (Beats 58.36 %).
// ref.: LeetCode Editoral - Approach 2: Sliding Window (Relaxed Constraints)

class Solution
{
public:
    long long countOfSubstrings(string word, int k)
    {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }

private:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        return false;
    }

    long long atLeastK(string word, int k)
    {
        const int n = word.size();
        int l = 0, r = 0;

        unordered_map<int, int> vowels;
        int consonants = 0;

        char c;
        long long ans = 0;
        while (r < n)
        {
            c = word[r];

            if (isVowel(c))
            {
                vowels[c]++;
            }
            else
            {
                consonants++;
            }

            while (vowels.size() == 5 && consonants >= k)
            {
                ans += n - r;

                c = word[l];

                if (isVowel(c))
                {
                    vowels[c]--;

                    if (vowels[c] == 0)
                    {
                        vowels.erase(c);
                    }
                }
                else
                {
                    consonants--;
                }

                l++;
            }

            r++;
        }
        return ans;
    }
};
