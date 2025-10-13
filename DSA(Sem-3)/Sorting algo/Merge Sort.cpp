// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void merge(int *arr,int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int temp[right+1];
    int index=0;
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            temp[index]=arr[i];
            index++;
            i++;
        }
        else{
            temp[index]=arr[j];
            index++;
            j++;
        }
    }
    while(i<=mid){
        temp[index]=arr[i];
        i++;
        index++;
    }
    while(j<=right){
        temp[index]=arr[j];
        j++;
        index++;
    }
    for(int i=0;i<index;i++){
        arr[i+left]=temp[i];
    }
}

void mergeSort(int *arr,int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main() {
    int arr[6]={12,31,35,8,32,17};
    mergeSort(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
