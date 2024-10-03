#include <iostream>
using namespace std;

// Node class for the circular linked list
class Node {
public:
    string route;
    Node* next;
    Node(string value) {
        route = value;
        next = nullptr;
    }
};

// NavigationSystem class to manage the circular linked list
class NavigationSystem {
private:
    Node* last;

public:
    NavigationSystem() {
        last = nullptr;
    }

    // Function to add a route to the circular linked list
    void addRoute(string route) {
        Node* newNode = new Node(route);

        if (last == nullptr) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    // Function to remove a route from the circular linked list
    void removeRoute(string route) {
        if (last == nullptr) {
            return;
        }

        if (last->next == last && last->route == route) {
            delete last;
            last = nullptr;
            return;
        }

        Node* curr = last->next;
        while (curr != last) {
            if (curr->route == route) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }

        if (last->route == route) {
            Node* temp = last;
            last = last->next;
            delete temp;
        }
    }

    // Function to display the routes in the circular linked list
    void displayRoutes() {
        if (last == nullptr) {
            cout << "No routes available." << endl;
            return;
        }

        Node* head = last->next;
        while (true) {
            cout << head->route << " -> ";
            head = head->next;
            if (head == last->next) {
                break;
            }
        }
        cout << endl;
    }
};

int main() {
    NavigationSystem navSystem;

    int choice;
    string route;

    while (true) {
        cout << "Navigation System Menu:" << endl;
        cout << "1. Add Route" << endl;
        cout << "2. Remove Route" << endl;
        cout << "3. Display Routes" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter route to add: ";
                cin >> route;
                navSystem.addRoute(route);
                break;
            case 2:
                cout << "Enter route to remove: ";
                cin >> route;
                navSystem.removeRoute(route);
                break;
            case 3:
                cout << "Routes: ";
                navSystem.displayRoutes();
                break;
            case 4:
                cout<<"Exiting.."<<endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
