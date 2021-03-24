// Using DoulbeLinkedList to implement a Queue
#include <iostream>
using namespace std;

// forward declaration of class Queue
template<typename NODETYPE> class Queue; 

template<typename NODETYPE>
class Node
{
    friend class Queue<NODETYPE>; 
    /*
    two reasons:
    1. let class Queue being able to specialize its member funcitons based on the template 
    2. allow class Queue access the priviate members of the class Node
    */
private:
    NODETYPE item;
    Node<NODETYPE>* prev;
    Node<NODETYPE>* next;

public:
    explicit Node(const NODETYPE& item)
        : item(item), prev(nullptr), next(nullptr) 
    {}
};

template<typename NODETYPE>
class Queue
{
private:
    size_t q_size;
    Node<NODETYPE>* head;
    Node<NODETYPE>* tail;

public:
    Queue(): head(nullptr), tail(nullptr), q_size(0) {}
    
    ~Queue()
    {
        if (!empty())
        {
            Node<NODETYPE>* curr = head;
            Node<NODETYPE>* temp;
            while (curr != nullptr)
            {
                temp = curr;
                curr = curr->next;
                delete temp;
            }            
        }
    }

    bool empty() const { return head == nullptr; }

    NODETYPE top() const { return head->item; }

    size_t size() const { return q_size; }

    void enqueue(const NODETYPE& item)
    {
        Node<NODETYPE>* pnode = new Node<NODETYPE>(item);
        if (empty())
            head = tail = pnode;
        else
        {
            tail->next = pnode; // link the current last node to the new last node
            pnode->prev = tail; // link the new last node back to the current last node
            tail = pnode; // update tail pointer
        }
        q_size++;
    }

    NODETYPE dequeue()
    {
        NODETYPE item;
        if (!empty())
        {
            item = head->item;
            if (head == tail) // only one element in the queue
                head = tail = nullptr;
            else
            {
                Node<NODETYPE>* temp = head; // hold node to delete
                head = head->next; // update head pointer
                head->prev = nullptr; // break 
                delete temp;
            }
            q_size--;
        }
        return item;
    }

    void print() const
    {
        if (empty())
            cout << "Queue is empty\n\n";
        else
        {
            Node<NODETYPE>* curr = head;
            cout << "{ ";
            while (curr)
            {
                cout << curr->item << " ";
                curr = curr->next;
            }
            cout << "}\n\n";
        }
    }
};


int main()
{
    Queue<int> q;
    cout << "q.empty()? " << q.empty() << endl;
    for (int i = 0; i < 4; i++)
        q.enqueue(i);
    cout << "q.empty()? " << q.empty() << endl;
    cout << "q.size() = " << q.size() << endl;
    cout << "q.top() = " << q.top() << endl;
    cout << "q = "; q.print();

    auto first_item = q.dequeue();
    cout << "first_item = " << first_item << endl;
    cout << "q.empty()? " << q.empty() << endl;
    cout << "q.size() = " << q.size() << endl;
    cout << "q.top() = " << q.top() << endl;    
    cout << "q = "; q.print();
}