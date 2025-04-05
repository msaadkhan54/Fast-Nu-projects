
#include <iostream>
#include <cstring>
using namespace std;
class Attendance {
    int check;
    int count;

public:
    Attendance() : check(0), count(0) {}

    void setCheck(int c) { check = c; }

    void markAttendance() {
        if (check == 0) {
            cout << "Attendance not marked. Fees not paid.\n";
        } else {
            count++;
            cout << "Attendance marked. Current count: " << count << "\n";
        }
    }
};

class Route {
public:
    string pick[10];
    string drop[10];
    int pickCount;
    int dropCount;

    Route() : pickCount(0), dropCount(0) {}

    void setRoute() {
        cout << "Enter number of pick locations (max 10): ";
        cin >> pickCount;
        for (int i=0;i<pickCount;++i) {
            cout << "Enter pick location " << i + 1 << ": ";
            cin >> pick[i];
        }

        cout << "Enter number of drop locations (max 10): ";
        cin >> dropCount;
        for (int i=0;i<dropCount;++i) {
            cout << "Enter drop location " << i + 1 << ": ";
            cin >> drop[i];
        }
    }

    void displayRoute() {
        cout << "Pick Locations: ";
        for (int i=0;i<pickCount;++i) cout << pick[i] << " ";
        cout << "\nDrop Locations: ";
        for (int i=0;i<dropCount;++i) cout << drop[i] << " ";
        cout << endl;
    }

};

class Bus {
public:
    int id;
    Route busRoute;

    Bus() : id(0) {}

    void setBus() {
        cout << "Enter bus ID: ";
        cin >> id;
        busRoute.setRoute();
    }

    void displayBus() {
        cout << "\nBus ID: " << id << endl;
        busRoute.displayRoute();
    }
    void operator==(const Bus &obj){
    	cout<<"\n*****Comparison between BUS - "<<id<<" and BUS - "<<obj.id<<" *****"<<endl;
    	cout<<"Picks: "<<endl;
    	
    	for(int i=0;i<busRoute.pickCount;i++){
    		for(int j=0;j<obj.busRoute.pickCount;j++){	
	    		if(busRoute.pick[i]==obj.busRoute.pick[j]){
	    			cout<<"Same route to: "<<obj.busRoute.pick[j]<<endl;
				}
			}
		}
		cout<<"\nDrops: "<<endl;
		for(int i=0;i<busRoute.dropCount;i++){
			for(int j=0;j<obj.busRoute.dropCount;j++){
	    		if(busRoute.drop[i]==obj.busRoute.drop[j]){
	    			cout<<"Same route to: "<<obj.busRoute.drop[j]<<endl;
				}
		    }
		}
	}
};

class User {
public:
    int id;
    string name;
    string fees;
    string pick;
    string drop;
    Attendance att;
    Bus* assignedBus;

    User(int i, string n, string f, string p, string d) : id(i), name(n), fees(f), pick(p), drop(d), assignedBus(NULL) {
        if (fees == "yes")
            att.setCheck(1);
    }

    void assignBus(Bus& b) {
        bool pickMatch = false, dropMatch = false;

        for(int i=0;i< b.busRoute.pickCount;++i) {
            if (pick == b.busRoute.pick[i]) pickMatch = true;
        }

        for(int i=0;i<b.busRoute.dropCount;++i) {
            if (drop == b.busRoute.drop[i]) dropMatch = true;
        }

        if (pickMatch && dropMatch) {
            assignedBus = &b;
            cout << "Bus assigned successfully!\n";
        } else {
            cout << "No suitable bus found for the given pick/drop.\n";
        }
    }

    void viewAssignedBus() {
        if (assignedBus) {
            cout << "Assigned Bus ID: " << assignedBus->id << endl;
            assignedBus->busRoute.displayRoute();
        } else {
            cout << "No bus assigned.\n";
        }
    }
    void markAttendance() {
        att.markAttendance();
    }
};

class Student:public User {
	string paymentMethod;
public:
    Student(int i, string n, string f, string p, string d,string s) :User(i,n,f,p,d),paymentMethod(s) {}
    Student(int i, string n, string f, string p, string d) :User(i,n,f,p,d) {}
	void payFees(){
		cout<<"Fees is paid semester by semester"<<endl;
	}
	void payFees(string s){
		cout<<"Fees is paid "<<s<<endl;
	}
};

class Teacher:public User{
	public:
	string paymentMethod;
    Teacher(int i, string n, string f, string p, string d,string s) :User(i,n,f,p,d),paymentMethod(s) {}
    Teacher(int i, string n, string f, string p, string d) :User(i,n,f,p,d) {}
	void payFees(){
		cout<<"Fees is paid on monthly basis"<<endl;
	}
	void payFees(string s){
		cout<<"Fees is paid "<<s<<endl;
	}
};

class Staff:public User{
		public:
	string paymentMethod;
    Staff(int i, string n, string f, string p, string d,string s) :User(i,n,f,p,d),paymentMethod(s) {}
    Staff(int i, string n, string f, string p, string d) :User(i,n,f,p,d) {}
	void payFees(){
		cout<<"Fees is paid on weekly basis "<<endl;
	}
	void payFees(string s){
		cout<<"Fees is paid "<<s<<endl;
	}
};

int main() {
    int num;
    cout<<"********** Muhammad Saad Khan 24K-0680 **************"<<endl<<endl;
    
    cout << "Enter the number of buses: ";
    cin >> num;

    Bus* buses = new Bus[num];
    for(int i=0;i<num;++i) {
        buses[i].setBus();
    }

    Student s1(123, "Saad Khan", "yes", "Nazimabad", "Fast");
	Teacher t1(321,"Javaid ","no","Gulshan","Fast","monthly basis");
	Staff st1(453,"leonard","yes","Gharo","Fast");
    int choice;
    string input;
        cout << "\nMenu:\n";
        cout << "1. Assign Bus to Student\n";
        cout << "2. Mark Attendance\n";
        cout << "3. View Assigned Bus\n";
        cout << "4. Display All Bus Details\n";
        cout << "5. View payement method\n";
        cout << "6. Exit\n";
        cout<<" \n\nFor is your role:(student,teacher,staff): ";
    	cin>>input;
    do {
        cout << "Enter your choice: ";
        cin >> choice;
		if(input=="student"){
			        switch (choice) {
            case 1:
                for(int i=0;i<num;++i) s1.assignBus(buses[i]);
                break;
            case 2:
                s1.markAttendance();
                break;
            case 3:
                s1.viewAssignedBus();
                break;
            case 4:
                for(int i=0;i<num;++i) buses[i].displayBus();
                break;
            case 5:
				s1.payFees();
				break;    
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
	}
			if(input=="teacher"){
			        switch (choice) {
            case 1:
                for(int i=0;i<num;++i) t1.assignBus(buses[i]);
                break;
            case 2:
                t1.markAttendance();
                break;
            case 3:
                t1.viewAssignedBus();
                break;
            case 4:
                for(int i=0;i<num;++i) buses[i].displayBus();
                break;
            case 5:
				t1.payFees(t1.paymentMethod);
				break;    
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
	}
			if(input=="staff"){
			        switch (choice) {
            case 1:
                for(int i=0;i<num;++i) st1.assignBus(buses[i]);
                break;
            case 2:
                st1.markAttendance();
                break;
            case 3:
                st1.viewAssignedBus();
                break;
            case 4:
                for(int i=0;i<num;++i) buses[i].displayBus();
                break;
            case 5:
				st1.payFees();
				break;    
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
	}
	
	
    } while (choice != 6);
	buses[0]==buses[1];
    delete[] buses;
    return 1;
}
