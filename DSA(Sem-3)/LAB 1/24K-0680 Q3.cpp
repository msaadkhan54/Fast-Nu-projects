#include<iostream>
using namespace std;
class Inventory{
	float *price;
	int size;
	public:
		Inventory(int siz){
			size=siz;
			price=new float[size];
		}
		void AddPrice(){
			for(int i=0;i<size;i++){
				cout<<"Enter Price "<<i+1<<": ";
				cin>>price[i];
			}
		}
		Inventory(const Inventory &obj){
			price=new float[obj.size];
			size=obj.size;
			for(int i=0;i<obj.size;i++){
				price[i]=obj.price[i];
			}
		}
		void operator=(const Inventory &obj){
			price=new float[obj.size];
			size=obj.size;
			for(int i=0;i<obj.size;i++){
				price[i]=obj.price[i];
			}
		}
		void print(){
			for(int i=0;i<size;i++){
				cout<<"Price "<<i+1<<" : "<<price[i]<<endl;
			}
			cout<<endl;
		}
		~Inventory(){
			delete price;
		}
};

int main(){
	Inventory i1(5);
	i1.AddPrice();
	Inventory i2(i1);
	i2.AddPrice();
	i1.print();
	i2.print();
}
