
#include <iostream>

using namespace std;

const int HASH = 5381;
const int MAX_STUDENTS = 10;
const int MAX_PROJECTS = 2;



class User {
protected:
    int id;
    string name;
    string* permissions;  
    int numPermissions;
    string email;
    int password;

public:
    User(int id, string name, int numPermissions, string email)
        : id(id), name(name), numPermissions(numPermissions), email(email) {
        permissions = new string[numPermissions];

        char c;
        cout << "Enter character (s=student, t=Assistant, p=professor) to set password: ";
        cin >> c;
        password = HASH * 33 + int(c);
    }

    virtual void display() {
        cout << "User: " << name << " (ID: " << id << ")\nEmail: " << email << "\n";
    }

    int authentication() {
        return password;
    }

    void labChecks() {
        for (int i = 0; i < numPermissions; i++) {
            if (permissions[i] == "full_lab_access") {
                cout << "Welcome Professor, you are allowed to access the lab." << endl;
                return;
            }
        }
        cout << "No access for Students and TAs." << endl;
    }

    virtual ~User() {
        delete[] permissions;
    }
};

int authenticateAndPerformAction(User* user, string action) {
	cout<<endl<<endl<<"*** "<<action<<" Authentication is being on check ***"<<endl;
    if (action == "Submission" && user->authentication() == (HASH * 33) + 's') {
    	cout<<"Pass the authentication"<<endl<<endl;
        return 1;
    }
    if ((action == "AddProject" || action == "manageStudents") && user->authentication() == (HASH * 33) + 't') {
    	cout<<"Pass the authentication"<<endl<<endl;
        return 1;
    }
    if ((action == "assignProjects" || action == "full_lab_access") && user->authentication() == (HASH * 33) + 'p') {
    	cout<<"Pass the authentication"<<endl<<endl;
        return 1;
    }
    cout<<"Authentication failed"<<endl<<endl;
    return 0;
}

class Students : public User {
private:
	int count=0;
    int* assignments;
    int numAssignments;

public:
	Students() : User(0, "", 0, ""), numAssignments(0), assignments(NULL) {}
    Students(int id, string name, int numPermissions, string email)
        : User(id, name, numPermissions, email), numAssignments(3), assignments(NULL) {
        permissions[0] = "Submission";

    }

    void numberOfAssignments() {
        cout << "Enter number of assignments: ";
        cin >> numAssignments;
        assignments = new int[numAssignments] ;
        for(int i=0;i<numAssignments;i++){
        	assignments[i]=0;
		}
    }

    void submitAssignment() {
        int i,track;
        for(i=0;i<numAssignments;i++){
        	if(assignments[i]==1){
        		count++;
			}
		}
		if(count<numAssignments){
			cout<<endl<< "Which assignment is this one: ";
	        cin >> track;
	        if(assignments[track-1]==1){
	        	cout<<"Assignment number "<<track<<" is already submitted"<<endl;
	        	return;
			}
	        if (track > 0 && track <= numAssignments) {
	            assignments[track - 1] = 1;
	            cout << "Assignment number-" << track << " submitted successfully!" << endl;
	        } else {
	            cout << "Invalid assignment number!" << endl;
	        }	
		}
    }

    void display() override {
        int count = 0;
        cout<<endl << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        for (int i = 0; i < numAssignments; i++) {
            if (assignments[i] == 1) count++;
        }
        cout << "Assignments Submitted: " << count << " out of " << numAssignments << endl;
    }

    ~Students() {
        delete[] assignments;
    }
};

class TA : public Students {
private:
    int* projects;
    int numProjects;
    Students* students;
    int numStudents;

public:
    TA(int id, string name, int numPermissions, string email)
        : Students(id, name, numPermissions, email), numProjects(0), numStudents(0), projects(NULL), students(NULL) {
        permissions[0] = "AddProject";
        permissions[1] = "manageStudents";
    }

	void addProject() {
    	if (numProjects >= MAX_PROJECTS) {
        	cout << "Project limit exceeded! No more projects can be added." << endl;
        	return;
    	}

    	int input;
    	cout << "Enter the number of tasks in project " << (numProjects + 1) << ": ";
    	cin >> input;

    	int* temp = new int[numProjects + 1];
    	for (int i = 0; i < numProjects; i++) {
        	temp[i] = projects[i];
    	}
    	temp[numProjects] = input;

    	delete[] projects;
    	projects = temp;
    	numProjects++;

    	cout << "Started work on new project." << endl;
	}


    void addStudent(Students &s) {
        if (numStudents < MAX_STUDENTS) {
            Students *temp = new Students[numStudents + 1];
            for (int i = 0; i < numStudents; i++) {
                temp[i] = students[i];
            }
            temp[numStudents] = s;

            delete[] students;
            students = temp;
            numStudents++;

            cout << "Student added successfully." << endl;
        } else {
            cout << "Student limit exceeded!" << endl;
        }
    }

    void display() override {
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout<<"Number of student assigned: "<<numStudents<<endl;
        cout << "Projects Assigned: " << numProjects << endl;
        for (int i = 0; i < numProjects; i++) {
            cout << "Project " << (i + 1) << " has " << projects[i] << " tasks." << endl;
        }
    }

    ~TA() {
        delete[] projects;
        delete[] students;
    }
};

class Professor : public User {
	int count;
public:
    Professor(int id, string name, int numPermissions, string email)
        : User(id, name, numPermissions, email),count(1) {
        permissions[0] = "assignProjects";
        permissions[1] = "full_lab_access";
    }

    void display() override {
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
    }
    
    void workWithTA(){
    	if(count){
    		cout<<"Professor "<<name<<" working with 1 TA currently"<<endl;
			count++;
			return ;	
		}
		cout<<"Professor "<<name<<" working with 2 TA currently"<<endl;
	}
	
	void assigningProject(TA& t, User* u) {
    if (authenticateAndPerformAction(u,"AddProject")) {
        t.addProject();
    } else {
        cout << "You do not have permission to assign projects!" << endl;
    }
	}
};
int main(){
	cout<<"********** Muhammad Saad Khan 24K-0680 **************"<<endl<<endl;
	
	User *u1;
	User *u2;
	User *u3;
	cout<<"___FOR STUDENT___"<<endl;
	Students s1(680,"Saad Khan",1,"apexsaad54@gmail.com");
	cout<<endl<<"___FOR TEACHER ASSITANT___"<<endl;
	TA t1(321,"Yousuf khan",2,"k240680@gmail.com");
	cout<<endl<<"___FOR PROFESSOR___"<<endl;
	Professor p1(213,"Ali",2,"adada@gmail.com");
	
	u1=&s1;
	u2=&t1;
	u3=&p1;

	cout<<"                --------------_______MENU______-----------"<<endl<<endl;
	cout<<"     1:Input number of assignments"<<endl;
	cout<<"     2:Submit Assignment"<<endl;
	cout<<"     3:Display Student information"<<endl;
	cout<<"     4:Add Project"<<endl;
	cout<<"     5:Add Student"<<endl;
	cout<<"     6:Display Assistant information"<<endl;
	cout<<"     7:Assign Project to TA"<<endl;
	cout<<"     8:Want to work with TA"<<endl;        
	cout<<"     9:Lab access"<<endl;
	cout<<"    10:Display Professor information"<<endl;            
	cout<<"    11:Exit"<<endl;
	
	int ch;
	do{
		cout<<endl<<"Enter choice: ";
		cin>>ch;
		switch(ch){
			case 1:
				s1.numberOfAssignments();
				break;
			case 2:
				if(authenticateAndPerformAction(u1,"Submission")){
					s1.submitAssignment();
				}
				break;
			case 3:
				u1->display();
				break;
			case 4:
				if(authenticateAndPerformAction(u2,"AddProject")){
					t1.addProject();
				}
				break;
			case 5:
				if(authenticateAndPerformAction(u2,"manageStudents")){
					t1.addStudent(s1);
				}
				break;
			case 6:
				u2->display();
				break;
			case 7:			
				if(authenticateAndPerformAction(u2,"assignProjects")){
					p1.assigningProject(t1,u2);
				}
				break;
			case 8:
				p1.workWithTA();
				break;
			case 9:
				if(authenticateAndPerformAction(u3,"full_lab_access")){
					p1.labChecks();
				}
				break;
			case 10:
				u3->display();
				break;
		}
	}while(ch!=11);

}
