#include<iostream>
using namespace std;

class Weather{
	double *temp;
	public:
		Weather(){
			temp=new double[7];
		}
		Weather(const Weather& obj){
			temp=new double[7];
			for(int i=0;i<7;i++){
				temp[i]=obj.temp[i];
			}
		}
		
		void operator=(const Weather &obj){
			temp=new double[7];
			for(int i=0;i<7;i++){
				temp[i]=obj.temp[i];
			}
		}
		void display(){
			float avg=0;
			for(int i=0;i<7;i++){
				cout<<"Day "<<i+1<<": "<<temp[i]<<" ";
				avg+=temp[i];
			}
			avg/=7;
			cout<<endl<<"Average temprature: "<<avg;
		}
		void add(){
			for(int i=0;i<7;i++){
				cout<<i+1<<":";
				cin>>temp[i];
			}
		}
		~Weather(){
			delete temp;
		}
};

int main(){
	Weather w1;
	w1.add();
	w1.display();
}
