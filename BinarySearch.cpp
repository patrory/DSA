#include<bits/stdc++.h>
using namespace std;
int i123=0;
void binarySearch(int arr[],int key ,int s,int e){
    if(s==e && key != arr[s]){
      //  cout<<-1;
        i123=-1;
        return;}
    int mid = (e+s)/2;
    if(key==arr[mid]){
       // cout<<mid ;
        i123=mid;
        return;}
    if( arr[mid]>key)binarySearch(arr,key,s,mid);
    if( arr[mid]<key)binarySearch(arr,key,mid,e);
    
}
int main(){
int arr[]={ 2, 3, 4, 10, 40 };
int n = sizeof(arr)/sizeof(arr[0]);
int key =10;
binarySearch(arr,key ,0,n-1);
cout<<"index :: "<<i123;
return 0 ;
}