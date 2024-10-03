#include<iostream>
using namespace std;
class node
{
    public:
    string text;
    node* next = NULL;
    node* prev = NULL;
    node()
    {
        text = "NA";
        next = NULL;
        prev = NULL;
    }
    node(string d)
    {
        text = d;
        next = NULL;
        prev = NULL;
    }
};
class LL
{
    public:
    node* head; 
    LL()
    {   
        head = NULL;
    }
    void insert_start(string d)
    {
        node* temp = new node(d);
        if(head == NULL)
        {
            head = temp;
        }else{
        head->prev = temp;
        temp->next = head;
        head = temp;
        }
    }
    void insert_end(string d)
    {
        node* temp = head;
        node* new_node = new node(d);
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = NULL;
    }
    void insert_pos(string d, int pos)
    {
    node* temp = head;
    node* new_node = new node(d);
    int count = 0;
    if (pos == 0) {
        insert_start(d);
    } else {
        while (count != pos - 2) {
            temp = temp->next;
            count++;
        }
        new_node->next = temp->next;
        new_node->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
        }
    }
    void delete_start()
    {
        if(head == NULL)
        {
            cout<<"Linked list is Empty";
        }else{
            head = head->next;
            head->prev = NULL;
        }
    }
    void delete_end()
    {
        if(head == NULL)
        {
            cout<<"LL is Empty";
        }else{
            node* temp = head;
            while(temp->next->next !=NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }
    void delete_between(int pos)
    {
        if(pos == 0)
        {
            delete_start();
        }else
        {
            int count = 0;
            node* temp = head;
            while(count != pos-1)
            {
                count ++;
                temp = temp->next;
            }
            temp->next = temp->next->next;
            temp->next->next->prev = temp;
        }
    }
    void find(string key)
    {
        node* temp = head;
        int found = 0;
        while(temp != NULL)
        {
            if(temp->text == key)
            {
                cout<<"Text is Found";
                found++;
            }
            temp = temp->next;
        }
        if(found == 0)
        {
            cout<<"text is not found";
        }
    }
    void reversal()
    {
        node* temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
        }
    }
    void print() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->text << " ";
        temp = temp->next;
    }
    cout << endl;
}
};
int main()
{
    LL list;
    int flip = 0;
    while (flip == 0) {
        int choice;
        cout << "\n1.Add Text at the start\n2.Add Text at the end\n3.Add Text at a position\n4.Print all\n5.Delete Starting text\n6.Delete text at the end.\n7.Delete Text at position.\n8.Find text in the playlist.\n9.Exit Text writer\n";
        cout << "Enter your choice:";
        cin >> choice;
        string temp;
        switch (choice) 
        {
        case 1:  
            cout << "Enter the text you want to insert at start:";
            cin >> temp;
            list.insert_start(temp);
            break;
        case 2:
            cout << "Enter the text to add at the end:";
            cin >> temp;
            list.insert_end(temp);
            break;
        case 3:
            int pos;
            cout << "Enter the text to add at a position:";
            cin >> temp;
            cout << "Enter the position:";
            cin >> pos;
            list.insert_pos(temp, pos);
            break;
        case 4:
            list.print();
            break;
        case 5:
            list.delete_start();
            break;
        case 6:
            list.delete_end();
            break;
        case 7:
            cout<<"Enter the position at which you have to delete text:";
            cin>>pos;
            list.delete_between(pos);
            break;
        case 8:
            cout<<"Enter the text you wish to find: ";
            cin>>temp;
            list.find(temp);
            break;
        case 9:
            flip = 1;
            break;
        default:
            cout << "Enter a valid number:";
        }
    }
}