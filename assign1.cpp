#include<iostream>
using namespace std;

class Stud
{
    int roll;
    string name;
    public: 
       void input(Stud s[], int n);
       void insertion_sort(Stud s[], int n);
       void shell_sort(Stud s[], int n);
       void display(Stud s[], int n);
};
 
    void Stud::input(Stud s[], int n)
        {
            cout<<"Enter the roll numbers with names: \n";
            for(int i=0; i<5; i++)
            {
                cin>>s[i].roll>>s[i].name;
                cout<<"\n";
            }
        }
        
        void Stud::insertion_sort(Stud s[], int n)
        {
            for(int i=1; i<5; i++)
            {
                int j= i-1;
                Stud val= s[i]; //object cannot be diectly passed by an int data type, use another object only

                while(j>=0 && s[j].roll > val.roll)
                {
                    s[j+1]= s[j];
                    j--;
                }

                s[j+1]=val;
            }
        }
        
        void Stud::shell_sort(Stud s[], int n)
        {
            int gap=n/2; //n = number of elemnets
            while(gap>=1)
            {
                for(int j=gap; j<n; j++)
                {
                    for(int i=j-gap; i>=0; i=i-gap)
                    {
                        if(s[i+gap].name>s[i].name)
                        {
                            break;
                        }

                        else //swapping of a[i] with a[i+gap]. Here a[i+gap] means a[j]
                        {
                            Stud temp;
                            temp=s[i+gap];
                            s[i+gap]=s[i];
                            s[i]=temp;
                        }
                    } //end of for i loop
                } //end of for j loop
                gap=gap/2; //recalculating the gap
            }
        }
        
        void Stud::display(Stud s[], int n)
        {
            cout<<"Sorted database according to roll number: \n";
            for(int i=0; i<5; i++)
            {
                cout<<s[i].roll<<"\t"<<s[i].name;
                cout<<"\n";
            }
        }

int main()
{
    Stud s[5], x;
    int k= sizeof(s)/sizeof(s[0]);
    char ch;
    int choice;

    do
    {
        cout<<"Enter your choice: \n";
        cout<<"1.Input the data.\n";
        cout<<"2.Sort using insertion sort.\n";
        cout<<"3.Sort using shell sort.\n";
        cout<<"4.Display the data. \n";

        cin>>choice;

        switch(choice)
        {
            case 1:
                x.input(s,k);
                break;

            case 2:
                x.insertion_sort(s,k);
                break;
            case 3:
                x.shell_sort(s,k);
                break;
            case 4:
                x.display(s,k);
                break;
            default:
                break; 
        }
        cout<<"do u want to continue....";
        cin>>ch;
    } while(ch=='y');
    
    return 0;
}