#include<iostream>
using namespace std;
void InsertionSort(int arr[],int n){
    int i,temp,j;
    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        
    }
}
int main(){
int arr[] = {10, 7, 8, 9, 1, 5}; 
int n= sizeof(arr)/sizeof(arr[0]);
//cout<<" n i"<<n<<endl;
InsertionSort(arr,n);
for(auto i:arr){
    cout<<i<<" ";
}
}