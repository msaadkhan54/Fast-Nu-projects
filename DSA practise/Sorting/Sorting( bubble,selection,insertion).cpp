// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void print(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<",";
    }
}

void BubbleSort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void selectionSort(int *arr,int n){
    bool small=false;
    for(int i=0;i<n-1;i++){
        int smallest=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallest]){
                small=true;
                smallest=j;
            }
        }
        if(small){
            int temp=arr[i];
            arr[i]=arr[smallest];
            arr[smallest]=temp;
        }
    }
}

void insertionSort(int *arr,int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && curr<arr[prev]){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
}
int main() {
    int array[5]={4,1,5,2,3};
    int size=5;

    insertionSort(array,size);
    print(array,size);
    return 0;
}
