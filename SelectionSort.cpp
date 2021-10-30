#include<bits/stdc++.h>
using namespace std;
int main(){
int arr[] = { 64, 25, 12, 22, 11 };
int n = sizeof(arr) / sizeof(arr[0]);
for(int i=0;i<(n-1);i++){
    int mini=i; // we assume that first element is minimum
    for(int j=i+1;j<n;j++){          // find smallest element from Array
        if( arr[mini] > arr[j])mini=j;
    }
    swap(arr[i],arr[mini]);
    mini=0;
}
for(auto i:arr){
    cout<<i<<" ";
}
return 0 ;
}