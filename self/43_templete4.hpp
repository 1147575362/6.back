#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class LinkList
{

public:
    class Node
    {
    public:
        T data;
        Node *next;
        Node(T x) : data(x), next(nullptr) {}
        // ~Node(){}
    };

public:
    LinkList() : size(0), head(nullptr){};
    // ~LinkList();

    void rear_push(T x)
    {
        Node *pnew = new Node(x);
        pnew->next = nullptr;
        if (!size)
            head = pnew;
        else
        {
            Node *p = head;
            while (p->next)
            {
                p = p->next;
            }
            p->next = pnew;
        }
        size++;
    }
    T front_pop()
    {
        if (!size)
            throw std::runtime_error("pop error");
        Node *p = head;
        head = head->next;
        T x = p->data;
        delete p;
        p = nullptr;
        return x;
    }
    void print()
    {
        Node *p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    bool empty()
    {
        return (size == 0) ? true : false;
    }

private:
    Node *head;
    int size;
};
