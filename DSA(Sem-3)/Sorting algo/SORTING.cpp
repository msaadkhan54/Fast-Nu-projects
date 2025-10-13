//// Online C++ compiler to run C++ program online
//#include <iostream>
//using namespace std;
//void bubbleSort(int *arr,int n){
//    bool swapped=false;
//    for(int i=0;i<n-1;i++){
//        
//        for(int j=0;j<n-1-i;j++){
//            if(arr[j]>arr[j+1]){
//                int temp=arr[j];
//                arr[j]=arr[j+1];
//                arr[j+1]=temp;
//                swapped=true;
//            }
//        }
//        if(!swapped){
//            break;
//        }
//    }
//}
//
//void insertionSort(int *arr,int n){
//    for(int i=1;i<n;i++){
//        int curr=arr[i];
//        int prev=i-1;
//        while(prev>=0){
//            if(curr<arr[prev]){
//                arr[prev+1]=arr[prev];
//                prev--;
//            }
//            else{
//            	break;
//			}
//        }
//        arr[prev+1]=curr;
//    }
//}
//
//void selectionSort(int *arr,int n){
//	for(int i=0;i<n;i++){
//		int min=i;
//		for(int j=i+1;j<n;j++){
//			if(arr[min]>arr[j]){
//				min=j;
//			}
//		}
//		int temp=arr[i];
//		arr[i]=arr[min];
//		arr[min]=temp;
//	}
//}
//
//int main() {
//    int arr[6]={12,43,23,65,90,32};
//    cout<<"Before Sorting: "<<endl;
//    for(int i=0;i<6;i++){
//        cout<<arr[i]<<" ";
//    }
////  bubbleSort(arr,6);
////  insertionSort(arr,6);
//	selectionSort(arr,6);
//    cout<<endl<<"After Sorting: "<<endl;
//    for(int i=0;i<6;i++){
//        cout<<arr[i]<<" ";
//    }
//
//    return 0;
//}
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void bubbleSort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void shellSort(int *arr,int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=arr[i];
            int j;
            for( j=i;j>=gap && temp<arr[j-gap];j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
}

void combSort(int *arr,int n){
    float shrink=1.3;
    bool swapped=true;
    int gap=n;
    while(gap>1 || swapped){
         gap=gap/shrink;
        swapped=false;
        if(gap<1){
            gap=1;
        }
        for(int i=0;i+gap<n;i++){
            if(arr[i]>arr[i+gap]){
                int temp=arr[i];
                arr[i]=arr[i+gap];
                arr[i+gap]=temp;
                swapped =true;
            }
        }
    }
}

void selectionSort(int *arr,int n){
    for(int i=0;i<n;i++){
        int smallest=i;
        for(int j=i+1;j<n;j++){
            if(arr[smallest]>arr[j]){
                smallest=j;
            }
        }
        int temp=arr[smallest];
        arr[smallest]=arr[i];
        arr[i]=temp;
    }
}

void insertionSort(int *arr,int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int prev=i-1;
        while(prev>=0 && temp<arr[prev]){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=temp;
    }
}

int binarySearch(int *arr,int target,int n){
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            right=mid-1;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
    }
    return -1;
}

int interpolationSearch(int *arr,int target,int n){
    int low=0;
    int high=n-1;
    while(low<=high && arr[low]<=target && arr[high]>=target){
        int pos=low+((target-arr[low])*(high-low))/(arr[high]-arr[low]);
        if(arr[pos]==target){
            return pos;
        }
        else if(arr[pos]>target){
            high=pos-1;
        }
        else if(arr[pos]<target){
            low=pos+1;
        }
    }
    return -1;
}
int main() {
int arr[7]={32,43,23,11,44,98,3};
cout<<"Sorted: "<<endl;
// bubbleSort(arr,7);
// selectionSort(arr,7);
// insertionSort(arr,7);
combSort(arr,7);
for(int i=0;i<7;i++){
    cout<<arr[i]<<" ";
}
cout<<endl<<"The number 11 is at index: "<<interpolationSearch(arr,23,7);
}
