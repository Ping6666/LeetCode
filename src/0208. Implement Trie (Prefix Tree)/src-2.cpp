#include <string>
#include <vector>
using std::string, std::vector;

// Runtime: 45 ms (Beats 72.54 %), Memory: 55.77 MB (Beats 87.79 %).

struct Node
{
    vector<Node *> next;

    Node() : next(27, nullptr) {}
    // '#' + lowercase English letters = 1 + 26 = 27

    bool find_next(char c)
    {
        if ((c == '#' && this->next[0] == nullptr) || (c != '#' && this->next[c - 'a' + 1] == nullptr))
        {
            return false;
        }
        return true;
    }

    Node *get_next(char c)
    {
        if (c == '#')
        {
            return this->next[0];
        }
        return this->next[c - 'a' + 1];
    }

    void insert_next(char c)
    {
        if (!this->find_next(c))
        {
            Node *tmp = new Node();

            if (c == '#')
            {
                this->next[0] = tmp;
            }
            else
            {
                this->next[c - 'a' + 1] = tmp;
            }
        }
    }
};

class Trie
{
    // NOTE: '#' will not in the string word, use it as EOF

    Node *root;

public:
    Trie()
    {
        this->root = new Node();
    }

    void insert(string word)
    {
        word += '#';

        Node *tmp = this->root;
        for (auto c : word)
        {
            tmp->insert_next(c);
            tmp = tmp->get_next(c);
        }
    }

    bool search(string word)
    {
        word += '#';
        return this->startsWith(word);
    }

    bool startsWith(string prefix)
    {
        Node *tmp = this->root;
        for (auto c : prefix)
        {
            tmp = tmp->get_next(c);
            if (tmp == nullptr)
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
