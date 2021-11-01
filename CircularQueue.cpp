#include<iostream>
using namespace std;
class data{
     public :
    int arr[5];
    int front,rear;
    int n1;
   
   // data(){}
    data(){
       // arr= new int[n];
        front =rear=-1;
        n1 =5;
    }
    void ienqueue(){
        if(front==-1){
            rear=0;
            front=0;
            int x;
            cout<<"Enter the elem :";
            cin>>x;
            arr[rear]=x;
        }
        else{
            
            if(( (rear +1)%n1 )!= front){
                rear=( (rear +1)%n1 );
                int x;
                cin>>x;
                arr[rear]=x;
            }
            else{
                cout<<"Full "<<endl;
            }
        }
    }
    void dequeue(){
        if(front ==-1){
            cout<<"EMpty"<<endl;
        }
        if(  (front+1)%n1 != rear){
            cout<<arr[front]<<" ";
            front=(front+1)%n1;
        }
        if(front==rear){
            front=rear=-1;
        }
    }
    void display(){
        int i=front;
        cout<<front<<" "<<rear<<endl;
      //  cout<<arr[i]<<endl;
        // while( i != rear){
        //     cout<<arr[i]<<" ";
        //     i=(i+1)%n1;
        // }
        for(int i=front ;i != rear;i = (i+1)%n1){
            cout<<arr[i]<<" ";
        }
        cout<<arr[rear]<<endl;
    }
};
int main(){
    data a;
  while(true){
      int ch;
      cout<<"Enter Choice :";
      cin>>ch;
      if(ch==1){
        a.ienqueue();  
      }
      if(ch==2){
          a.dequeue();
      }
      if(ch==3){
          a.display();
      }
  }
    }
