// Runtime: 11 ms (Beats 98.96 %), Memory: 22.89 MB (Beats 17.67 %).

struct Node
{
    int val;
    Node *prev, *next;

    Node(int val) : val(val), prev(nullptr), next(nullptr) {};
    Node(int val, Node *prev, Node *next) : val(val), prev(prev), next(next) {};
};

class MyCircularDeque
{
private:
    int max_size, curr_size;
    Node *front, *rear;

public:
    MyCircularDeque(int k)
    {
        this->max_size = k;

        this->curr_size = 0;
        this->front = this->rear = nullptr;
    }

    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }

        if (isEmpty())
        {
            Node *tmp = new Node(value, nullptr, nullptr);
            this->front = this->rear = tmp;
        }
        else
        {
            Node *tmp = new Node(value, nullptr, this->front);
            this->front->prev = tmp;
            this->front = tmp;
        }

        this->curr_size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }

        if (isEmpty())
        {
            Node *tmp = new Node(value, nullptr, nullptr);
            this->front = this->rear = tmp;
        }
        else
        {
            Node *tmp = new Node(value, this->rear, nullptr);
            this->rear->next = tmp;
            this->rear = tmp;
        }

        this->curr_size++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
        {
            return false;
        }

        if (this->curr_size == 1)
        {
            delete this->front;

            this->front = this->rear = nullptr;
        }
        else
        {
            Node *tmp;
            tmp = this->front->next;
            delete this->front;

            tmp->prev = nullptr;
            this->front = tmp;
        }

        this->curr_size--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }

        if (this->curr_size == 1)
        {
            delete this->rear;

            this->front = this->rear = nullptr;
        }
        else
        {
            Node *tmp;
            tmp = this->rear->prev;
            delete this->rear;

            tmp->next = nullptr;
            this->rear = tmp;
        }

        this->curr_size--;
        return true;
    }

    int getFront()
    {
        return isEmpty() ? -1 : this->front->val;
    }

    int getRear()
    {
        return isEmpty() ? -1 : this->rear->val;
    }

    bool isEmpty()
    {
        return this->curr_size == 0;
    }

    bool isFull()
    {
        return this->curr_size == this->max_size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
