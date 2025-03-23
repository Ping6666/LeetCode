#include <vector>
#include <string>
#include <iostream>
using std::vector, std::string;

// without magic
//   Runtime: 551 ms (Beats 73.81 %), Memory: 719.03 MB (Beats 44.64 %).

// with magic
//   Runtime: 488 ms (Beats 87.53 %), Memory: 718.40 MB (Beats 47.38 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

struct TrieNode
{
    // NOTE do not use vector
    TrieNode *next[26] = {};
    int count = 0;
};

class Solution
{
    TrieNode *root;

private:
    void insert(string s)
    {
        TrieNode *curr = root;

        int ch;
        for (const auto &c : s)
        {
            ch = c - 'a';

            if (!curr->next[ch])
            {
                curr->next[ch] = new TrieNode();
            }

            curr->next[ch]->count++;
            curr = curr->next[ch];
        }
    }

    int count(string s)
    {
        int ans = 0;
        TrieNode *curr = root;

        int ch;
        for (const auto &c : s)
        {
            ch = c - 'a';

            ans += curr->next[ch]->count;
            curr = curr->next[ch];
        }

        return ans;
    }

public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        this->root = new TrieNode();

        for (const auto &s : words)
        {
            this->insert(s);
        }

        vector<int> ans;
        for (const auto &s : words)
        {
            ans.push_back(this->count(s));
        }

        return ans;
    }
};
