#include<iostream>
using namespace std;
void SelectionSort(int arr[], int n){
    for(int i=0; i<n-1;i++){
        int min=i;
        for(int j=i+1; j<n;j++){
            if(arr[j]<=arr[min]){
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
}
int main(){
    int n;
    cout<<"Enter the value size of array: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element "<<i<<" of array: "<<endl;
        cin>>arr[i];
    }
    cout<<"Sorted array: "<<endl;
    SelectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}