// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
void nextPermutation(vector<int> &A){
    int pivot=-1,n=A.size();
    for(int i=n-1;i>=1;i--){
        if(A[i-1]<A[i]){
            pivot=i-1;
            break;
        }
    }
    if(pivot==-1){
        for(int i=0;i<n/2;i++){
            int temp=A[i];
            A[i]=A[n-1-i];
            A[n-1-i]=temp;
        }
    }
    for(int i=n-1;i>pivot;i++){
        if(A[pivot]<A[i]){
            int temp=A[pivot];
            A[pivot]=A[i];
            A[i]=temp;
            break;
        }
    }
    int i=pivot+1,j=n-1;
    while(i<=j){
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        i++;
        j--;
    }
}
int main() {
    vector<int> array={1,2,3,6,5,4};
    nextPermutation(array);
    for (int num : array) {
        cout << num << " ";
    }
    return 0;
}
