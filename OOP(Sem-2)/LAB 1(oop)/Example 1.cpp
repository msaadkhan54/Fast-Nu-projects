#include<iostream>
#include<limits>
#include<cmath>
using namespace std;

void greet(){
	cout <<"Hello, world" <<endl;
}

int add(int a,int b){
	return (a+b);
}
void array1(int *arr){
	int i;
	for(i=0;i<5;i++){
		cout << "Enter element "<<i+1<<" :";
		cin>>arr[i];
	}
	for(i=0;i<5;i++){
		cout <<"The element "<<i+1<<" is: "<<arr[i]<<endl;
	}
}
#include <iostream>
using namespace std;

void dArray(int arr[][2]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << "Enter row " << i + 1 << " and column " << j + 1 << " :";
            cin >> arr[i][j];
        }    
    }
    
    for(int i = 0; i < 2; i++) {
        int sum = 0;
        for(int j = 0; j < 2; j++) {
            sum += arr[i][j];
        }
        cout << "The sum of row " << i + 1 << " is " << sum << endl;
    }
}


int main(){
	int num;
	int arr[5];
	int array[2][2];
	cout << "Enter the input: ";
	cin>>num;
	cout << "the number you have input is: " << num <<endl;
	cout << "the size of integer is: " << sizeof(int) <<endl;
	cout << "Int min: " << std::numeric_limits<int>::min() <<endl;
	greet();
	int sum;
	sum=add(5,6);
	cout << "The sum is: "<< sum<<endl;
	int b=4;
	int c=sqrt(b);
	cout << "the square root of "<<b<< " is " <<c<<endl;
	array1(arr);
	dArray(array);
}
