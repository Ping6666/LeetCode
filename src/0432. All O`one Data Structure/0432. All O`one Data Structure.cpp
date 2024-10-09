#include <string>
#include <unordered_map>
using std::string, std::unordered_map;

// Runtime: 67 ms (Beats 97.69 %), Memory: 50.62 MB (Beats 92.37 %).

struct Node
{
    string val;
    int count;
    Node *prev, *next;

    Node(string val) : val(val), count(1), prev(nullptr), next(nullptr) {};
    Node(string val, Node *prev, Node *next) : val(val), count(1), prev(prev), next(next) {};
};

class AllOne
{
private:
    unordered_map<string, Node *> table;
    Node *front, *back;

    // void print()
    // {
    //     if (!(!front))
    //     {
    //         printf("FRONT: %d %s\n", front->count, front->val.c_str());
    //     }
    //     if (!(!back))
    //     {
    //         printf("BACK: %d %s\n", back->count, back->val.c_str());
    //     }

    //     Node *tmp;
    //     tmp = front;
    //     while (!(!tmp))
    //     {
    //         printf("%d %s\n", tmp->count, tmp->val.c_str());
    //         tmp = tmp->next;
    //     }
    //     printf("###\n\n");
    // }

public:
    AllOne()
    {
        front = back = nullptr;
    }

    void inc(string key)
    {
        // printf("INC: %s\n", key.c_str());
        // print();

        if (table.find(key) == table.end())
        {
            Node *tmp = new Node(key);
            table[key] = tmp;

            if (back == nullptr)
            {
                front = back = tmp;
            }
            else
            {
                if (front == back)
                {
                    front->next = tmp;
                }

                back->next = tmp;
                tmp->prev = back;
                back = tmp;
            }
        }
        else
        {
            int _count = ++(table[key]->count);

            Node *a, *b, *c, *d;
            c = table[key];
            b = table[key]->prev;

            while (!(!b))
            {
                if (_count > b->count)
                {
                    // do swap
                    // a b c d -> a c b d

                    a = b->prev;
                    d = c->next;

                    c->prev = a;
                    c->next = b;

                    b->prev = c;
                    b->next = d;

                    if (!(!a))
                    {
                        a->next = c;
                    }

                    if (!(!d))
                    {
                        d->prev = b;
                    }

                    if (front == b)
                    {
                        front = c;

                        if (!front)
                        {
                            back = nullptr;
                        }
                    }

                    if (back == c)
                    {
                        back = b;

                        if (!back)
                        {
                            front = nullptr;
                        }
                    }
                }
                else
                {
                    break;
                }

                // a c b d
                // b c

                b = a;
            }
        }

        // print();
    }

    void dec(string key)
    {
        // printf("DEC: %s\n", key.c_str());
        // print();

        int _count = --(table[key]->count);

        if (_count == 0)
        {
            Node *a, *b, *c;
            // a b c -> a c

            a = table[key]->prev;
            b = table[key];
            c = table[key]->next;

            table.erase(key);

            if (!(!a))
            {
                a->next = c;
            }

            if (!(!c))
            {
                c->prev = a;
            }

            if (back == b)
            {
                back = a;

                if (!back)
                {
                    front = nullptr;
                }
            }

            if (front == b)
            {
                front = c;

                if (!front)
                {
                    back = nullptr;
                }
            }
        }
        else
        {
            Node *a, *b, *c, *d;

            b = table[key];
            c = table[key]->next;

            while (!(!c))
            {
                if (_count < c->count)
                {
                    // do swap
                    // a b c d -> a c b d

                    a = b->prev;
                    d = c->next;

                    c->prev = a;
                    c->next = b;

                    b->prev = c;
                    b->next = d;

                    if (!(!a))
                    {
                        a->next = c;
                    }

                    if (!(!d))
                    {
                        d->prev = b;
                    }

                    if (back == c)
                    {
                        back = b;

                        if (!back)
                        {
                            front = nullptr;
                        }
                    }

                    if (front == b)
                    {
                        front = c;

                        if (!front)
                        {
                            back = nullptr;
                        }
                    }
                }
                else
                {
                    break;
                }

                // a c b d
                //     b c
                c = d;
            }
        }

        // print();
    }

    string getMaxKey()
    {
        if (!front)
        {
            return "";
        }
        return front->val;
    }

    string getMinKey()
    {
        if (!back)
        {
            return "";
        }
        return back->val;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
