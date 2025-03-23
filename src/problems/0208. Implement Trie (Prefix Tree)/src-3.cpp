#include <string>
#include <iostream>
using std::string;

// Runtime: 30 ms (Beats 99.22 %), Memory: 48.03 MB (Beats 79.86 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

struct Node
{
    Node *next[26];
    bool hit;
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        this->root = new Node();
    }

    void insert(string word)
    {
        Node *tmp = this->root;
        for (auto c : word)
        {
            if (!tmp->next[c - 'a'])
            {
                tmp->next[c - 'a'] = new Node();
            }
            tmp = tmp->next[c - 'a'];
        }
        tmp->hit = true;
    }

    bool search(string word)
    {
        Node *tmp = this->root;
        for (auto c : word)
        {
            tmp = tmp->next[c - 'a'];
            if (!tmp)
            {
                return false;
            }
        }

        return tmp->hit;
    }

    bool startsWith(string prefix)
    {
        Node *tmp = this->root;
        for (auto c : prefix)
        {
            tmp = tmp->next[c - 'a'];
            if (!tmp)
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
