#include<iostream>
#include<string>
using namespace std;

class BHistory
{

    string stk1[7];
    string stk2[7];
    int top;

    public:

        BHistory()
        {
            top = -1;
        }

        void push(string website)
        {
            if(top<7)
            {
                top++;
                stk1[top] = website;
            }
        }

        void pop()
        {
            if(top>=0)
            {
                stk2[top] = stk1[top]; //puts the top element into stack 2
                top--; //decrements the top
            }

            for(int i = top; i>=0; i--)
            {
                cout<<stk1[i]<<"\n";
            }
        }

        void current()
        {
            if(top>=0)
            {
                cout<<stk1[top]<<endl;
            }    
        }

        void check()
        {
            if(top<0)
            {
                cout<<"History is empty"<<endl;
            }
            else
            {
                cout<<"History is not empty";
            }
        }
};

int main()
{
    BHistory bh;
    string web;
    int choice;

    cout<<"Add 7 websites: \n";
    for(int i=0; i<7; i++)
    {
        cin>>web;
        bh.push(web);
    }

    while(true)
    {
        cout<<"\nChoose an option:\n";
        cout<<"1. View current page\n";
        cout<<"2. Go back\n";
        cout<<"3. Check if history is empty\n";
        cout<<"4. Exit\n";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"- The current page: ";
                bh.current();
                break;
            case 2:
                cout<<"- Viewing back page: \n";
                bh.pop();
                break;
            case 3:
                cout<<"- Checking if the history is empty or not \n";
                bh.check();
                break;
            case 4:
                cout<<"Exiting...\n";
                return 0;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    }

    return 0;
}