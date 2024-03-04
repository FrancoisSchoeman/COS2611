#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class singlelist
{
    // class with the functions to handle the nodes
    // 2 constructors:  head and tail
private:
    node *head, *tail;

public:
    singlelist()
    {
        // initialised as NULL to avoid junk data
        head = NULL;
        tail = NULL;
    }

    void createNode(int nodevalue)
    // function to create nodes with
    {
        node *temp = new node;
        temp->data = nodevalue;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    } // createNode

    void insert_head(int nodevalue)
    // function to insert node at the start of the list
    // same function for inserting node at the end
    {
        node *temp = new node;
        temp->data = nodevalue;
        temp->next = head;
        head = temp;
    } // insert_head

    void insert_position(int pos, int nodevalue)
    // function to insert a node at a specific position in the list
    {
        node *previous = new node;
        node *current = new node;
        node *temp = new node;
        current = head;
        for (int i = 1; i < pos; i++)
        {
            previous = current;
            current = current->next;
        } // for
        temp->data = nodevalue;
        previous->next = temp;
        temp->next = current;
    } // insert_position

    void delete_head()
    // function to remove the first node (head)
    {
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    } // delete_head

    void delete_tail()
    // function to remove the tail - remember you need to know the node before the last before you can delete the last
    {
        node *current = new node;
        node *previous = new node;
        current = head;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        tail = previous;
        previous->next = NULL;
        delete current;
    } // delete_tail

    void remove_position(int pos)
    // function to remove node at a specific position
    {
        node *current = new node;
        node *previous = new node;
        current = head;
        for (int i = 1; i < pos; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
    } // remove_position

    void displayList()
    // code to display the nodes of the linked list
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    } // displayList
};

int main()
{
    cout << "Single linked lists" << endl;
    singlelist list;
    // add elements to the list
    list.createNode(10); // create the first element of the list
    list.createNode(38);
    list.createNode(88);
    list.createNode(25);
    // display the initial list of data
    list.displayList();
    cout << " " << endl;
    cout << "New Single linked lists:  66 added after 38" << endl;
    // add an element 66 after 38
    list.insert_position(3, 66); // element 38 is in position 2, thus 66 should be inserted in postion 3
    list.displayList();
    cout << " " << endl;
    cout << "New Single linked lists:  38 removed" << endl;
    // remove element 38
    list.remove_position(2); // element 38 is in position 2
    list.displayList();
    return 0;
} // main