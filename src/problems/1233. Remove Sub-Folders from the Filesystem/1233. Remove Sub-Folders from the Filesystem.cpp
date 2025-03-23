#include <vector>
#include <string>
#include <unordered_map>
using std::vector, std::string, std::unordered_map;

// Runtime: 163 ms (Beats 52.75 %), Memory: 93.78 MB (Beats 32.97 %).

struct Trie
{
    unordered_map<string, Trie *> nexts;
    bool subfolder;

    Trie()
    {
        subfolder = false;
    }

    Trie *get(string s)
    {
        if (nexts.find(s) == nexts.end())
        {
            // no hit
            nexts[s] = new Trie();
        }

        return nexts[s];
    }
};

class Solution
{
private:
    vector<string> bfs(Trie *root)
    {
        vector<string> r;
        for (const auto &n : root->nexts)
        {
            // printf("%s ", n.first.c_str());
            // if (n.second->subfolder)
            // {
            //     printf("T\n");
            // }
            // else
            // {
            //     printf("F\n");
            // }

            if (n.second->subfolder)
            {
                r.emplace_back('/' + n.first);
            }
            else
            {
                vector<string> v = bfs(n.second);

                for (int i = 0; i < v.size(); i++)
                {
                    r.emplace_back('/' + n.first + v[i]);
                }
            }
        }

        return r;
    }

public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        Trie *root = new Trie();

        Trie *curr;
        for (const auto &f : folder)
        {
            curr = root;

            int l = 1;
            for (int r = l + 1; r <= f.size(); r++)
            {
                if (f[r] == '/' || r == f.size())
                {
                    string sub = f.substr(l, r - l);
                    // printf("%s\n", sub.c_str());

                    curr = curr->get(sub);
                    l = ++r;
                }
            }
            // printf("\n");

            curr->subfolder = true;
        }

        return bfs(root);
    }
};
