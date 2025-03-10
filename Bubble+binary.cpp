#include<iostream>
using namespace std;
void BubbleSort(int arr[],int n){
    for(int i=1; i<n; i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int BinarySearch(int arr[],int n, int key){
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i<<" of array: ";
        cin>>arr[i];
    }
    BubbleSort(arr,n);
    cout<<"Array after sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    int key;
    cout<<"Enter the value to be found: "<<endl;
    cin>>key;
    int index=BinarySearch(arr,n,key);
    cout<<"Element found at index "<<index<<" of array"<<endl;
    
}