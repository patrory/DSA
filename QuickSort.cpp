#include <bits/stdc++.h>

using namespace std;
int partition(int arr[],int s,int l){
    int pivot=arr[s];
    int i=s,j=l;
    while(i<j){
        while(pivot >= arr[i] && i<=l)i++;
        while(pivot <arr[j] && j>=0)j--;
        if(i<j)swap(arr[i],arr[j]);
    }
    if(i>j)swap(arr[j],arr[s]);
    return j;
}
void quicksort(int arr[],int s,int l){
    if(s<=l){
        int p= partition(arr,s,l);
        quicksort(arr,s,p-1);
        quicksort(arr,p+1,l);
    }
}
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n= sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,5);
    for (auto ie :arr){
    cout<<ie<<" ";
}
}
