



#include<iostream>
#include<string>
using namespace std;

class Student;
class Mentor;
class Sport;
class Skill;

class Student{
	public:
    int studentId;
	string name;
	int age;
	string *sportsInterest;
	string mentorAssigned;
	int sportNum;
	Student(int i,string n,int ag,int sport):studentId(i),name(n),age(ag),sportNum(sport){
	    sportsInterest=new string[sportNum];
	}
	~Student(){
	    delete[] sportsInterest;
	}
    void setInterest() {
        for (int i = 0; i < sportNum; i++) {
            cout << "Interest " << i + 1 << ": ";
            getline(cin, sportsInterest[i]);  
        }
    }
	void viewMentorDetails(Mentor &n);
	void updateSportsInterest(Sport &s);
};

class Mentor{
    public:
    int mentorId;
	string name;
	string *sportsExpertise;
	int expertNum;
	int maxLearners;
	int assignedlearners;
	    Mentor(int id,string n,int e,int max):mentorId(id),name(n),expertNum(e),maxLearners(max){
	        sportsExpertise=new string[expertNum];
	        assignedlearners=0;
	    }
	    ~Mentor(){
	        delete[] sportsExpertise;
	    	sportsExpertise=NULL;
	    }
	    void setExpertise(){
	         
            for (int i = 0; i < expertNum; i++) {
                cout << "Expertise " << i + 1 << ": ";
                getline(cin, sportsExpertise[i]);  
            }
	    }
		void assignLearner(Student &s){
			if(assignedlearners>=maxLearners){
				cout<<"Insuffient space :("<<endl;
				return ;
			}
			else{
				int flag=0;
				for(int i=0;i<s.sportNum;i++){
					for(int j=0;j<expertNum;j++){
			
					if(s.sportsInterest[i]==sportsExpertise[j]){
						cout<<"Successfully registered */"<<s.sportsInterest[i]<<"*/"<<endl<<endl;
						assignedlearners+=1;
						s.mentorAssigned=name;
					}
					}
				}
			}
		}
		void removeLearner(Student &s){
			cout<<"The Student "<<s.name<<" is removed."<<endl;
			assignedlearners-=1;
		}
		void viewLearners(Student &s){
			cout<<"Name : "<<s.name<<endl;
			cout<<"Id : "<<s.studentId<<endl;
			cout<<"Age : "<<s.age<<endl;
			cout<<"Mentor Assigned : "<<s.mentorAssigned<<endl;
			cout<<"Sport interest : ";
			for(int i=0;i<s.sportNum;i++){
				cout<<s.sportsInterest[i]<<",";
			}
			cout<<endl;
		
		}
		void provideGuidance(){
			string text;
			cin.ignore();
			cout<<"Enter Guidance: ";
			getline(cin,text);
		}
};

void Student::viewMentorDetails(Mentor &n) {
    cout << "Name : " << n.name << endl;
    cout << "ID : " << n.mentorId << endl;
    cout<<"Assigned learners : "<<n.assignedlearners<<endl;
    cout<<"Max Learners : "<<n.maxLearners<<endl;
    cout << "Sports Expertise : ";
    for (int i = 0; i < n.expertNum; i++) {
        cout << n.sportsExpertise[i] << " ";
    }
    cout << endl;
}

class Skill{
	public:
	int skillId;
	string skillName;
	string description;
	
	void showSkillDetails(){
		cout<<"Skill ID : "<<skillId<<endl;
		cout<<"Skill Name : "<<skillName<<endl;
		cout<<"Description : "<<description<<endl;
	}
	void updateSkillDescription(string newDescription){
		description=newDescription;
	}
	
};

class Sport{
	public:
	int sportId;
	string name;
	string description;
	Skill* requiredSkills; 
	int skillNum;
	    Sport(int id,string n,string dis):sportId(id),name(n),description(dis),skillNum(0){
	        requiredSkills = NULL;
	    }
	    ~Sport(){
	    	if (requiredSkills) {  
        	delete[] requiredSkills;
        	requiredSkills = NULL;  
    		}
	    }
	    void showSkillDetails();
	    void addSkill();
	    void removeSkill();
};

void Student::updateSportsInterest(Sport &s){
		
		cout<<"Enter Id : ";
		cin>>s.sportId;
		
		cout<<"Enter name : ";
		cin.ignore();
		getline(cin,s.name);
		
		cout<<"Enter description : ";
		getline(cin,s.description);
		

	}


void Sport::addSkill() {
    Skill* newSkills = new Skill[skillNum + 1];  
    for (int i=0; i <skillNum;i++) {
        newSkills[i] =requiredSkills[i]; 
    }

    cout << "Enter skill ID: ";
    cin >> newSkills[skillNum].skillId;
    cin.ignore();
    cout << "Enter skill name: ";
    getline(cin, newSkills[skillNum].skillName);
    cout << "Enter description: ";
    getline(cin, newSkills[skillNum].description);

    delete[] requiredSkills;  
    requiredSkills = newSkills;  //Here requiredSkills takes ownership of the allocated memory.
    skillNum++;
}




void Sport::showSkillDetails() {
    if (skillNum == 0 || requiredSkills == NULL) {
        cout << "No skills available." << endl;
        return;
    }

    cout << "Skills for sport: " << name << endl;
    for (int i = 0; i < skillNum; i++) {
        cout << "Skill ID: " << requiredSkills[i].skillId << endl;
        cout << "Skill Name: " << requiredSkills[i].skillName << endl;
        cout << "Description: " << requiredSkills[i].description << endl;
        cout << "--------------------------------------" << endl;
    }
}



void Sport::removeSkill() {
        if (skillNum == 0) {
            cout << "No skills to remove." << endl;
            return;
        }
        
        int id;
        cout << "Enter skill ID to remove: ";
        cin >> id;
        
        int index = -1;
        for (int i = 0; i < skillNum; i++) {
            if (requiredSkills[i].skillId == id) {
                index = i;
                break;
            }
        }
        
        if (index == -1) {
            cout << "Skill ID not found." << endl;
            return;
        }
        
        Skill* newSkills = new Skill[skillNum - 1];
        for (int i = 0, j = 0; i < skillNum; i++) {
            if (i != index) {
                newSkills[j++] = requiredSkills[i];
            }
        }
        
        delete[] requiredSkills;
        requiredSkills = newSkills;
        skillNum--;
        cout << "Skill removed successfully!" << endl;
    }

int main(){
	int choice;
	string text;
	Mentor m1(321,"Ali",2,3);
	cout<<"Enter expertise of MENTOR:"<<endl;
	m1.setExpertise();

    Student student1(1,"Saad",18,3);
    cout<<"Enter Sports Interest of Student:"<<endl;
    student1.setInterest();
    
    Skill skill1;
    
    Sport s1(1,"Tennis","Have perfect Grip");

    
	cout<<"      -------------------------------------------------MENU---------------------------------------------"<<endl;
	cout<<"        1: View Mentor"<<endl;
	cout<<"        2: Assigning Mentor"<<endl;
	cout<<"        3: Update the sport intrest"<<endl;
	cout<<"        4: View Mentors Learners"<<endl;
	cout<<"        5: Adding skill"<<endl;
	cout<<"        6: Update description"<<endl;
	cout<<"        7: Provide Guidance"<<endl;
	cout<<"        8: Skill details"<<endl;
	cout<<"        9: Skill Removed"<<endl;
	cout<<"        10:Remove Learner"<<endl;
	cout<<"        0: EXIT"<<endl;
	do{
	cout<<"        Enter the number : ";
	cin>>choice;
	
	switch(choice){

	case 1:
	cout<<"View Mentor->"<<endl;
    student1.viewMentorDetails(m1);  
    cout << endl;
    break;
    
    case 2:
    cout<<"Assigning learner->"<<endl;
    m1.assignLearner(student1); 
    cout<<endl;
    break;
    
    case 3:
    cout<<endl<<"Now Update the sport intrest->"<<endl;
    student1.updateSportsInterest(s1);
    cout<<endl;
    break;
    
    case 4:
    cout<<"View Mentors Learner->"<<endl;
    m1.viewLearners(student1);
    cout<<endl;
	break;
	
	case 5:
	cout<<"Adding skill->"<<endl;
	s1.addSkill();
	cout<<endl;
	break;
	
	case 6:
	cout<<"Update discription : ";
	cin.ignore();
	getline(cin,text);
	skill1.updateSkillDescription(text);
	cout<<endl;
	break;
	
	case 7:
    m1.provideGuidance();
    cout<<endl;
    break;
	
	case 8:
	cout<<"Skill details"<<endl;
	s1.showSkillDetails();
	cout<<endl;
	break;
	
	case 9:
	s1.removeSkill();
	cout<<"Skill REMOVED"<<endl;
	cout<<endl;
	break;
	
	case 10:
	m1.removeLearner(student1);
	cout<<endl;
	break;
	case 0:
		return 0;
}}while(1);

}


