#include<iostream>
using namespace std;

class song {
public:
    string song_title;
    song* next;
    song() {
        song_title = "NA";
        next = NULL;
    } 
    song(string d) {
        song_title = d;
        next = NULL;
    }
};
class playlist {
    song* head;
public:
    playlist() {
        head = NULL; 
    }
    void insert_start(string d);
    void insert_end(string d);
    void insert_at_position(string d, int pos);
    void delete_start();
    void delete_end();
    void delete_at_position(int pos);
    void find(string key);
    void print();
};

void playlist::insert_start(string d) {
    song* nn = new song(d);
    if (head == NULL) {
        head = nn;
    } else {
        nn->next = head;
        head = nn;
    }
}
void playlist::insert_end(string d) {
    song* nn = new song(d);
    song* temp = head;
    if (head == NULL) {
        head = nn;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }
}
void playlist::insert_at_position(string d, int pos) {
    song* nn = new song(d);
    if (pos == 0) {
        insert_start(d);
        return;
    }
    song* temp = head;
    int current_pos = 0;
    while (temp != NULL && current_pos < pos - 1) {
        temp = temp->next;
        current_pos++;
    }
    if (temp == NULL) {
        cout << "Position out of range." << endl;
        return;
    }
    nn->next = temp->next;
    temp->next = nn;
}
void playlist::delete_start()
{
    if(head == NULL)
    {
        cout<<"Linked list is Empty";
    }else{
        song * temp = head;
        head = head->next;
        delete temp;
    }
}
void playlist::delete_end()
{
    if(head==NULL)
    {
        cout<<"Linked List is Empty";
    }else if(head->next == NULL){
        delete head;
        head = NULL;
    }else
    {
        song *temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}
void playlist::delete_at_position(int pos)
{
    if(head == NULL)
    {
        cout<<"Linked list is Empty";
    }else{
        song* temp = head;
        song *curr = new song();
        int count = 0;
        while(count!=pos-1)
        {
            count ++;
            temp = temp->next;
        }
        curr = temp->next;
        temp->next = temp->next->next;
        delete curr;
    }
}
void playlist::find(string key)
{
    song *temp = head;
    int found = 0;
    if(head == NULL)
    {
        cout<<"Playlist is Empty";
    }else
    {
        while(temp->next != NULL)
        {
            if(temp->song_title == key)
            {
                cout<<"Song is found\n";
                found++;
            }
            temp=temp->next;
        }
        if(!found)
        {
            cout<<"Song is not present in the playlist\n";
        }
    }
}
void playlist::print() {
    song* temp = head;
    while (temp != NULL) {
        cout << temp->song_title << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    playlist list;
    int flip = 0;
    while (flip == 0) {
        int choice;
        cout << "\n1.Add Song at the start\n2.Add song at the end\n3.Add song at a position\n4.Print all the songs\n5.Delete Starting song\n6.Delete song at the end.\n7.Delete at position.\n8.Find song in the playlist.\n9.Exit playlist\n";
        cout << "Enter your choice:";
        cin >> choice;
        string temp;
        switch (choice) 
        {
        case 1:  
            cout << "Enter the song you want to insert at start:";
            cin >> temp;
            list.insert_start(temp);
            break;
        case 2:
            cout << "Enter the song to add at the end:";
            cin >> temp;
            list.insert_end(temp);
            break;
        case 3:
            int pos;
            cout << "Enter the song to add at a position:";
            cin >> temp;
            cout << "Enter the position:";
            cin >> pos;
            list.insert_at_position(temp, pos);
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
            cout<<"Enter the position at which you have to delete node:";
            cin>>pos;
            list.delete_at_position(pos);
            break;
        case 8:
            cout<<"Enter the song title you wish to find: ";
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
    return 0;
}
