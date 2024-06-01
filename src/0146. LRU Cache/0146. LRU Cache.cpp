#include <stdio.h>

// #include <list> // list

// #include <map> // map
#include <algorithm> // unordered_map

using namespace std;

/*
class LRUCache
{
    // same complexity as implementation below

private:
    int capacity;
    list<pair<int, int>> node_list;
    // store key value pair

    unordered_map<int, list<pair<int, int>>::iterator> node_map;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (node_map.find(key) != node_map.end())
        {
            node_list.splice(node_list.begin(), node_list, node_map[key]);
            return node_map[key]->second;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (node_map.find(key) != node_map.end())
        {
            // found

            node_map[key]->second = value;
            node_list.splice(node_list.begin(), node_list, node_map[key]);
        }
        else
        {
            // not found

            if (capacity == node_list.size())
            {
                // reached maximum capacity

                node_map.erase(node_list.back().first);
                node_list.pop_back();
            }

            node_list.push_front({key, value});
            node_map.insert({key, node_list.begin()});
        }
    }
};
*/

struct Node
{
    // Doubly Linked List

    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
};

class LRUCache
{
    // Runtime: 446 ms (Beats 97.2 %), Memory: 164.9 MB (Beats 91.38 %).

private:
    int capacity;
    Node *head;
    Node *tail;

    // head <-> node <-> node <-> node <-> tail
    // guarantee if 1 then 2
    //   1. node->prev == head
    //   2. head->next == node

    unordered_map<int, Node *> node_map;
    // key <-> node

    void moveHead(Node *node)
    {
        if (node->prev != head && head->next != node)
        {
            Node *prev_node = node->prev;
            Node *next_node = node->next;
            Node *head_next_node = head->next;

            prev_node->next = next_node;
            next_node->prev = prev_node;

            head_next_node->prev = node;
            head->next = node;

            node->prev = head;
            node->next = head_next_node;
        }
    }

    void pushHead(Node *node)
    {
        Node *next_node = head->next;

        next_node->prev = node;
        head->next = node;

        node->next = next_node;
        node->prev = head;
    }

    int popTail()
    {
        if (head->next != tail && tail->prev != head)
        {
            int key;

            Node *prev_node = tail->prev; // need to free
            Node *prev_prev_node = prev_node->prev;

            key = prev_node->key;
            prev_prev_node->next = tail;
            tail->prev = prev_prev_node;

            delete prev_node;

            return key;
        }

        return -1;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1, 0);
        tail = new Node(-1, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (node_map.find(key) != node_map.end())
        {
            moveHead(node_map[key]);
            return node_map[key]->value;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (node_map.find(key) != node_map.end())
        {
            // found

            moveHead(node_map[key]);
            node_map[key]->value = value;
        }
        else
        {
            // not found

            if (capacity == node_map.size())
            {
                // reached maximum capacity

                int key = popTail();
                node_map.erase(key);
            }

            Node *node = new Node(key, value);
            pushHead(node);
            node_map.insert({key, node});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    int capacity;
    LRUCache *obj;

    int param;

    capacity = 2;

    obj = new LRUCache(capacity);
    obj->put(1, 1);

    obj->put(2, 2);

    param = obj->get(1);
    printf("%d\n", param);

    obj->put(3, 3);

    param = obj->get(2);
    printf("%d\n", param);

    obj->put(4, 4);

    param = obj->get(1);
    printf("%d\n", param);

    param = obj->get(3);
    printf("%d\n", param);

    param = obj->get(4);
    printf("%d\n", param);

    return 0;
}
