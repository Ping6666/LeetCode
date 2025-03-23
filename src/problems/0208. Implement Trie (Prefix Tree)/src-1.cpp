#include <string>
#include <vector>
#include <unordered_map>
using std::string, std::vector, std::unordered_map;

// Runtime: 75 ms (Beats 17.82 %), Memory: 50.15 MB (Beats 26.77 %).

struct Node
{
    unordered_map<char, Node *> next;

    Node() : next(unordered_map<char, Node *>()) {}

    bool find_next(char c)
    {
        if (this->next.find(c) == this->next.end())
        {
            return false;
        }
        return true;
    }

    Node *get_next(char c)
    {
        if (this->find_next(c))
        {
            return this->next[c];
        }
        return nullptr;
    }

    void insert_next(char c)
    {
        if (!this->find_next(c))
        {
            Node *tmp = new Node();

            this->next[c] = tmp;
            // this->next.insert(std::pair<char, Node *>(c, tmp));
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
