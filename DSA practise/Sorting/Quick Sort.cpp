// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int partition(int*arr ,int st,int end){
    int pivot=arr[end];
    int idx=st;
    int j=st;
    while(j<end){
        if(arr[j]<pivot){
            int temp=arr[idx];
            arr[idx]=arr[j];
            arr[j]=temp;
            idx++;
        }
        j++;
    }
    int temp=arr[end];
    arr[end]=arr[idx];
    arr[idx]=temp;
    return idx;
}

void quickSort(int *arr,int st,int end){
    if(st<end){
        int pivotIdx=partition(arr,st,end);
        quickSort(arr,st,pivotIdx-1);
        quickSort(arr,pivotIdx+1,end);
    }
}

int main() {
    int arr[6]={12,31,35,8,32,17};
    quickSort(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
