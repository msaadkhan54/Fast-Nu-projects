#include<iostream>
using namespace std;

class Library {
private:
    string title;
    string author;
    bool availability;

public:
    int flag;

    void setTitle() {
        if (flag == 1) {
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
        } else {
            title = "";
        }
    }

    void setAuthor() {
        if (flag == 1) {
            cout << "Enter author: ";
            getline(cin, author);
        } else {
            author = "";
        }
    }

    void setAvail() {
        if (flag == 1) {
            int status;
            cout << "If available press '1' or if not then press '0': ";
            cin >> status;
            availability = (status == 1);
        }
    }

    string getTitle() {
        return title;
    }

    bool getAvailable() {
        return availability;
    }

    virtual void add() = 0;
    virtual void remove() = 0;
    virtual void borrow() = 0;
};

class Librarian : public Library {
public:
    void add() {
        flag = 1;
        setTitle();
        setAuthor();
        setAvail();
        cout << "Book added successfully." << endl;
    }

    void remove() {
        flag = 0;
        setTitle();
        setAuthor();
        setAvail();
        cout << "Book removed." << endl;
    }

    void borrow() {}
};

class User : public Library {
public:
    void add() {}
    void remove() {}

    void borrow() {
        string choice;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, choice);

        if (getTitle() == choice) {
            if (getAvailable()) {
                cout << "Book is issued." << endl;
            } else {
                cout << "Book is not available." << endl;
            }
        } else {
            cout << "Book not found." << endl;
        }
    }
};

int main() {
    Library* lib1;
    Library* lib2;
    Librarian l1;
    User u1;

    lib1 = &l1;
    lib2 = &u1;

    lib1->add();
    lib2->borrow();
    lib1->remove();
    lib2->borrow();

    return 0;
}

