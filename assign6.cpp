#include<iostream>
using namespace std;

class Node
{
    public:
        Node *next;
        int power;
        int coeff;
        Node(int c = 0, int p = 0, Node *n = NULL) //initializing values using a contructor
        {
            power = p;
            coeff = c;
            next = n;
        }
   };

class LL
{
    public:
    Node *head;

    LL() //initializing head as NULL
    {
        head = NULL;
    }

    void create_node(int x, int y) //function to create a node
    {
        Node *nn = new Node(); //initializing nn

        nn->coeff = x; //new node's coefficient will point to the x value, given by the user
        nn->power = y; //new node's power will point to the y value, again given by the user
        if(head == NULL) //the list is empty and head = new node, which is nn
        { 
            head = nn;
        }
        else{ //if the list is not empty, traverse to the last node; adding values till the end
            Node *temp = new Node();
            temp = head;
            while(temp->next!= NULL)
            {
                temp = temp->next;
            }
        }
    }

    void print_poly()
    {
        if(head != NULL)
        {
            Node *temp = head;
            while(temp->next != NULL) //to print the values till the end
            {
                cout << temp->coeff << "x^" << temp->power << "+";
                temp = temp->next;
            }
            cout<<temp->coeff<<"x^"<<temp->power;
        }
    }

    void polyadd(LL l1, LL l2) // here the two objects resembble the two linked lists
    {
        Node *p1 = l1.head;
        Node *p2 = l2.head;
        Node *result = new Node();
        Node *curr = result;


        while(p1->next != NULL && p2->next != NULL)
        {
            Node *nn = new Node();
            if(p1->power > p2->power)
            {
                nn->power = p1->power;
                nn->coeff = p1->coeff;
                p1 = p1->next;
            }
            else if(p1->power < p2->power)
            {
                nn->power = p2->power;
                nn->coeff = p2->coeff;
                p1 = p1->next;
            }
            else
            {
                nn->power = p1->power;
                nn->coeff = p1->coeff + p2->coeff;
                p1 = p1->next;
                p2 = p2->next;
            }

            curr->next = nn;
            curr = curr->next;
        }

        while(p1 != NULL && p2 != NULL)
        {
            Node *nn = new Node();
            if(p1->power > p2->power)
            {
                curr->next = p1;
                curr = curr->next;
                p1 = p1->next;
            }
            else if (p1->power < p2->power)
            {
                curr->next = p2;
                curr = curr->next;
                p2 = p2->next;
            }
            else
            {
                nn->power = p1->power;
                nn->coeff = p1->coeff + p2->coeff;
                p1 = p1->next;
                p2 = p2->next;
            }

            curr->next = nn;
            curr = curr->next;
        }

        while(p1 != NULL)
        {
            curr->next = p1;
            curr = curr->next;
            p1 = p1->next;  
        }

        while(p2 != NULL)
        {
            curr->next = p2;
            curr = curr->next;
            p2 = p2->next;
        }

        head = result->next;
    }
};

int main()
{
    LL l1, l2, l3;
    int choice;
    int m1, m2, n1, n2;
    while(true)
    {
        cout<<"Choose an option: \n";
        cout<<"1) Input the polynomials.\n";
        cout<<"2) Add the two polynomials.\n";
        cout<<"3) Print the addition. \n";
        cout<<"4) Exit.\n";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"First polynomial: \n";
                cout<<"Constant value: ";
                cin>>m1;
                cout<<"Power: ";
                cin>>m2;

                cout<<"Second polynomial: \n";
                cout<<"Constant value: ";
                cin>>n1;
                cout<<"Power: ";
                cin>>n2;

                l1.create_node(m1, m2);
                l2.create_node(n1, n2);
                break;

            case 2:
                l3.polyadd(l1, l2);
                cout<<"Polynomial added"<<endl;
                break;

            case 3:
                cout<<"Printing the addition: \n";
                l3.print_poly();
                cout<<"\n";
                break;

            case 4:
                cout<<"Exiting..."<<endl;
                return 0;
                break;

            default:
                cout<<"Invalid choice, please try again."<<endl;
        }
    }
    return 0;
}
