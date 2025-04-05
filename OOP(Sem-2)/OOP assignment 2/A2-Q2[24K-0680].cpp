#include<iostream>
#include<cstring>
using namespace std;
const int MAX=7;

class HauntedHouse;

class Ghost{
	string workerName;
	int range;
	public:
		Ghost(){}
		Ghost(string name,int range):workerName(name),range(range){}
		virtual void haunting(){
			cout<<"Each ghost has different abilities"<<endl;
		}
		string get_range(){
    		if (range >= 1 && range <= 4) return "Cowardly";
    		if (range>= 5 && range <= 7) return "Average";
    		return "Fearless";
		}
		Ghost operator+(const Ghost &obj) const{
			return Ghost(workerName + "-" + obj.workerName,range + obj.range);
		}
		
		string get_name(){ return workerName; }
    	int get_range_value(){ return range; }
		friend ostream& operator<<(ostream &out, const Ghost &g);	
};

class Poltergeists:public Ghost{
	public:
		Poltergeists(string name,int range):Ghost(name,range){}
		void haunting() override{
			cout<<"Poltergeists : Moves object"<<endl;
		}
};

class Banshees:public Ghost{
	public:
		Banshees():Ghost("saad",5){
		}
		Banshees(string name,int range):Ghost(name,range){}
		void haunting() override{
			cout<<"Banshees : Screams Loudly"<<endl;
		}
};

class ShadowGhost:public Ghost{
	public:
		ShadowGhost(string name,int range):Ghost(name,range){}
		void haunting() override{
			cout<<"ShadowGhost : Whispers Creeply"<<endl;
		}	
};

class ShadowPoltergeist:public Ghost{
	public:
		ShadowPoltergeist(string name,int range):Ghost(name,range){}
		void haunting() override{
			cout<<"ShadowPoltergeist : Whispers Creeply and Screams Loudly"<<endl;
		}
};

class Visitor{
	string name;
	int bravery;
	public:
		Visitor(string name,int bravery):name(name),bravery(bravery){}
		string get_bravery(){
    		if (bravery >= 1 && bravery <= 4) return "Cowardly";
    		if (bravery >= 5 && bravery <= 7) return "Average";
    		return "Fearless";
		}
		string get_name(){
			return name;
		}
		friend void visit(Visitor *arr,HauntedHouse h1,int numVisitor);
};

class HauntedHouse{
	string name;
	Ghost *ghost[MAX];
	int count;
	public:
		HauntedHouse(string name):name(name),count(0){}
		
		void addGhost(Ghost *ptr){
			if(count<MAX){
				ghost[count]=ptr;
				cout<<"Ghost added successfully"<<endl;
				count++;
			}
			else{
				cout<<"No more space for ghost"<<endl;
			}
		}
		
		void play(Visitor v1){
			for(int i=0;i<count;i++){
				ghost[i]->haunting();
				if( v1.get_bravery()==ghost[i]->get_range() ) {
					cout<<v1.get_name()<<" got a shaky voice"<<endl<<endl;
				}
				if((v1.get_bravery()=="Fearless" && ghost[i]->get_range()=="Cowardly")  ||  
				  (v1.get_bravery()=="Fearless" && ghost[i]->get_range()=="Average") ||
				  (v1.get_bravery()=="Average" && ghost[i]->get_range()=="Cowardly")){
				  	cout<<v1.get_name()<<" laughed and taunt ghost "<<endl<<endl;
				  }
				  
				if((v1.get_bravery()=="Cowardly" && ghost[i]->get_range()=="Fearless")  ||  
				  (v1.get_bravery()=="Average" && ghost[i]->get_range()=="Fearless")){
				  	cout<<v1.get_name()<<" screams and run away "<<endl<<endl;
				  }
			}
		}
		friend void visit(Visitor *arr,HauntedHouse h1,int numVisitor);
		~HauntedHouse(){
			for(int i=0;i<count;i++){
				delete ghost[i];
			}
		}
};

void visit(Visitor *arr,HauntedHouse h1,int numVisitor){
	cout<<endl<<endl;
	for(int i=0;i<numVisitor;i++){
		cout<<arr[i].name<<" Enters "<<h1.name<<" : "<<endl;
		h1.play(arr[i]);
	}
}

ostream& operator<<(ostream &out, const Ghost &g) {
        out << "Ghost Name: " << g.workerName << ", Range: " << g.range;
        return out;
}

int main(){
	cout<<"********** Muhammad Saad Khan 24K-0680 **************"<<endl<<endl;
	HauntedHouse h1("Jagaar Boom");
	
	Poltergeists *p1=new Poltergeists("jhon",4);
	ShadowPoltergeist *s1=new ShadowPoltergeist("Saima",9);
	Ghost temp = *s1 + *p1;  
    Banshees *b1 = new Banshees(temp.get_name(), temp.get_range_value());
    cout << "Combined Ghost: " << *b1 << endl;
    
	h1.addGhost(p1);
	h1.addGhost(s1);
	h1.addGhost(b1);
	
	Visitor v1[3]={
		Visitor("Saad",9),
		Visitor("Ali",6),
		Visitor("Yousuf",2)
	};
	visit(v1,h1,3);
	
	HauntedHouse h2("Khoof naak");
	h2.addGhost(new Poltergeists("jhon",10));
	h2.addGhost(new ShadowPoltergeist("Saima",2));
	h2.addGhost(new Banshees("tobo",4));
	Visitor v2[1]=Visitor("Zain",8);
	visit(v2,h2,1);
}
