 #include<bits/stdc++.h>
 using namespace std;
 int main(){
 int arr[]= { 2, 3, 1000, 10, 40 };
 //Bubble sort
 int n= sizeof(arr)/sizeof(arr[0]);
 for(int i=0;i<(n-1);i++){
     for(int j=i+1;j<(n);j++){
         if (arr[i]>arr[j]) swap(arr[i],arr[j]);
     }
 }
 for(auto i : arr){
     cout<<i<<" ";
 }
 return 0 ;
 }