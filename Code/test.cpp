#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Contact {
    string firstName;
    string lastName;
    string address;
    string phoneNumber;
};

vector<Contact> contacts; // Store contacts in a vector

// Function prototypes
void addContact();
void viewContacts();


bool compareContacts(const Contact &a, const Contact &b) {
    return a.firstName < b.firstName;
}

int main() {
    system("cls");
    bool run = true;
    do {
        int option;
        cout << "-----------------User Address Book------------------------" << endl;
        cout << "\n";
        cout << "What would you like to do?" << endl;
        cout << "1.) Add Contact" << endl;
        cout << "2.) Edit Contact" << endl;
        cout << "3.) Delete Contact" << endl;
        cout << "4.) View All Contacts" << endl;
        cout << "5.) Search Address Book" << endl;
        cout << "6.) Exit" << endl
             << endl;
        cout << "Choose an option: ";
        cin >> option;
        cin.ignore();
        switch (option) {
            case 1:
                addContact();
                break;
            case 2:
          
                break;
            case 3:
          
                break;
            case 4:
                viewContacts();
                break;
            case 5:
            
                break;
            case 6:
                run = false;
                break;
            default:
                cout << "Please choose between 1 to 6" << endl;
        }
    } while (run);
    cout << "Program Terminated";
}

void addContact() {
    system("cls");
    Contact contact;
    cout << "----------------------Address Book-----------------------------" << endl << endl;
    cout << "Enter 'quit' at First name to quit" << endl << endl;
    cout << "Enter First Name: ";
    getline(cin, contact.firstName);
    if (contact.firstName == "quit") {
        return;
    }
    cout << "Enter Last Name: ";
    getline(cin, contact.lastName);
    cout << "Enter Address: ";
    getline(cin, contact.address);
    cout << "Enter Contact Number: ";
    getline(cin, contact.phoneNumber);

    contacts.push_back(contact); // Add the contact to the vector
    sort(contacts.begin(), contacts.end(), compareContacts); // Sort contacts by first name
    system("pause");
    system("cls");
}

void viewContacts() {
    system("cls");
    cout << "Entry #" << setw(17) << "First Name" << setw(23) << "Last Name" << setw(23) << "Address" << setw(29) << "Contact" << endl << endl;
    for (size_t i = 0; i < contacts.size(); ++i) 
    {
        cout << setw(3) << i + 1 << setw(18) << contacts[i].firstName << setw(25) << contacts[i].lastName << setw(25) << contacts[i].address << setw(30) << contacts[i].phoneNumber << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}

// Implement the remaining functions (searchContact, editContact, deleteContact) as needed.
