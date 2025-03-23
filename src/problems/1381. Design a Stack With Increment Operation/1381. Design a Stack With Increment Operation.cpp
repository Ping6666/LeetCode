// Runtime: 28 ms (Beats 57.61 %), Memory: 26.24 MB (Beats 8.62 %).

struct Node
{
    int val;
    Node *prev, *next;

    Node(int val) : val(val), prev(nullptr), next(nullptr) {};
    Node(int val, Node *prev, Node *next) : val(val), prev(prev), next(next) {};
};

class CustomStack
{
private:
    int max_size, curr_size;
    Node *top;

public:
    CustomStack(int maxSize)
    {
        max_size = maxSize;
        curr_size = 0;

        top = nullptr;
    }

    void push(int x)
    {
        if (curr_size < max_size)
        {
            Node *tmp = new Node(x, top, nullptr);

            if (!(!top))
            {
                top->next = tmp;
            }

            top = tmp;
            curr_size++;
        }

        return;
    }

    int pop()
    {
        int ret_val = -1;

        if (curr_size > 0)
        {
            ret_val = top->val;

            Node *tmp = top;
            top = top->prev;

            if (!(!top))
            {
                top->next = nullptr;
            }

            delete tmp;
            curr_size--;
        }

        return ret_val;
    }

    void increment(int k, int val)
    {
        Node *tmp = top;

        for (int i = 0; i < curr_size - k && !(!tmp); i++)
        {
            tmp = tmp->prev;
        }

        for (int i = 0; i < k && !(!tmp); i++)
        {
            tmp->val += val;
            tmp = tmp->prev;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
