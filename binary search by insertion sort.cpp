#include<iostream>
using namespace std;
void InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
         int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}
int BinarySearch(int arr[],int size, int key){
    int start=0;
    int end=size-1;
    int mid= start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(key>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;//if not found
}

int main(){
    int key=3;
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    InsertionSort(arr,n);
    cout<<"Sorted Array:"<<endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int Index=BinarySearch(arr,n,3);
    cout<<"Index of 3 is: "<<Index<<endl;
}