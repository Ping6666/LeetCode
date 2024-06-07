#include <string>
#include <unordered_set>
#include <iostream>
using std::string, std::unordered_set;

// Runtime: 68 ms (Beats 23.68 %), Memory: 35.80 MB (Beats 97.90 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Trie
{
    unordered_set<string> prefix_table, word_table;

public:
    Trie() {}

    void insert(string word)
    {
        string prefix = "";
        for (auto c : word)
        {
            prefix += c;
            prefix_table.insert(prefix);
        }
        word_table.insert(prefix);
    }

    bool search(string word)
    {
        return word_table.find(word) != word_table.end();
    }

    bool startsWith(string prefix)
    {
        return prefix_table.find(prefix) != prefix_table.end();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
