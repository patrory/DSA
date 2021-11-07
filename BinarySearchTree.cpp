#include<iostream>
#include<queue>
using namespace std;
#define globalspace 5
class node{
int data;
node *left;
node *right;
public:
node (int val){
    data=val;
    left=right=NULL;
}
friend class tree;
};
class tree{
    public:
    node*root;
    tree(){
        root=NULL;
    }
    void insert();
    void print(node *temp);
    void search();
    void print2d(node *root,int space);
    void deletei(node *temp,int key);
    void mirror(node *temp);
    void displayLeafnode(node *temp);
    void parentchild(node *temp);
    int  heightoftree(node *temp);
    void levelorder(node *temp);
};
void tree::insert(){
        cout<<"Enter the Element to be inserted : ";
        int x;
        cin>>x;
        node *new1=new node(x);
        if(root==NULL){
            root=new1;
            cout<<"Inserted At head"<<endl;
        }
        else{
            node*temp=root;
            while(temp != NULL){
                if( (x)==(temp->data)){
                   cout<<"Duplicate Element not Accepted \n";
                    break;
                }
                else if((x < (temp->data))&&(temp->left==NULL)) {
                    // node linking at left 
                    temp->left=new1;
                    break;
                }
                else if(x < (temp->data) ){
                    temp=temp->left;
                }
                else if((x>(temp->data))&&(temp->right==NULL)){
                     // node linking at right
                    temp->right=new1;
                    break;
                }
                else{
                    temp=temp->right;
                }
            }
        }
    }
void tree::print(node *temp){
    if(temp==NULL){
        return;
    }
    print(temp->left);
    cout<<temp->data<<" ";
    print(temp->right);

    }
void tree::search(){
    node *temp=root;
    cout<<"which element to search :: ";
    int x;
    cin>>x;
    while(temp !=NULL){
        if(temp->data == x){
            cout<<"YES , WE found the element in tree "<<endl;
            break;
        }
        if( x > temp->data){
            temp=temp->right;
        }
        if(x < temp->data){
            temp=temp->left;
        }
    }
    if (temp==NULL){
        cout<<"element not found "<<endl;
    }
}
void tree::print2d(node *r,int space){
    if(r==NULL)return;
    space +=globalspace;
    print2d(r->right,space);
    cout<<endl;
    for(int i=globalspace;i<space;i++){
        cout<<" ";
    }
    cout<<r->data;
    print2d(r=r->left,space);
    
}
void tree::deletei(node *temp,int key){
    node *prev = NULL;
    if(temp==NULL){
        cout<<"tree is empty "<<endl;
        return;
    }
    while( temp != NULL  || temp->data != key){
        
        if( temp->data==key){
            break;
        }
        if(temp->data < key){
            prev = temp;
            temp=temp->right;
        }
        else{
            prev = temp;
            temp=temp->left;
        }
    }
    if(temp->data != key){
        cout<<"data not found"<<endl;
        return;
    }
    if(temp->left == NULL && temp->right==NULL){
        if(prev->data > key){
            prev->left=NULL;
        }
        else{
            prev->right=NULL;
        }
    }
    else if(temp->left == NULL || temp->right==NULL ){
        if(prev==NULL){
            if(temp->left != NULL){
                root=temp->left;
            }else root=temp->right;

            return;
        }
       if( prev->data < key){
           if(temp->right){
               prev->right=temp->right;
           }else prev->right=temp->left;
       }else{
           if(temp->right)prev->left=temp->left;
           else prev->right=temp->right;
       }
    }else if(temp->left != NULL && temp->right !=NULL ){
       node *t1=temp->right;
       node *t2;
       while(t1->left != NULL){
           t2= t1;
           t1= t1->left;
       }
       t2->left=NULL;
       temp->data=t1->data;
    }
    cout<<"temp ata "<<temp->data<<" prev data izz :"<<prev->data;
}
void tree::displayLeafnode(node* temp){
    if(temp==NULL)return;
    displayLeafnode(temp->left);
    if(temp->left==NULL && temp->right==NULL){
        cout<<temp->data<<" ";
    }
    displayLeafnode(temp->right);
}
void tree::parentchild(node *temp){
    if(temp==NULL)return;
    cout<<"        Parent ::         "<<temp->data<<endl;
    if(temp->left != NULL)cout<<"Left child izz : "<<temp->left->data;
    if(temp->right !=NULL)cout<<"                   Right child izz :"<<temp->right->data;
    cout<<endl;
    parentchild(temp->left);
    parentchild(temp->right);
}
void tree::mirror(node *temp){
    if(temp==NULL)return;
    mirror(temp->left);
    mirror(temp->right);
    swap(temp->left,temp->right);
}
int tree::heightoftree(node *temp){
    if(temp==NULL)return 0;
    int hl= heightoftree(temp->left);
    int hr=heightoftree(temp->right);
    return hl>hr?hl+1:hr+1;

}
void tree::levelorder(node *temp){
    if(temp==NULL)return;
    queue<node *>q;
    q.push(temp);
    q.push(NULL);
    while( !q.empty()){
        node *t1= q.front();
        q.pop();
        if(t1 !=NULL){
            cout<<"  "<<t1->data<<"  ";
            if(t1->left !=NULL){q.push(t1->left);}
            if(t1->right != NULL)q.push(t1->right);
        }else if( ! q.empty()){
            q.push(NULL);
        }
        if(t1==NULL){
            cout<<endl;
        }
    }
}
int main(){
  //object of tree class created
    tree o;
  // menu driven code
    while(true){
        cout<<"0 Exit\n1 Insert\n2 Delete \n3 Search\n4 Print bst\n5 print2D\n6 display leaf node\n7 Parent-child\n8 mirror\n9 height of tree\n10 level order"<<endl;
        int choice;
        cout<<"Choose Input:: ";
        cin>>choice;
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
           o.insert(); 
            break;
        case 2:
        int key;
        cout<<"Enter the key to be deleted : ";
        cin>>key;
            o.deletei(o.root,key);
            cout<<endl;
            break;
        case 3:
            o.search();
            break;
        case 4:
            o.print(o.root);
             cout<<endl;
            break;
        case 5:
        o.print2d(o.root,5);
        cout<<endl;
        break;
        case 6:
        o.displayLeafnode(o.root);
        cout<<endl;
        break;
        case 7:
            o.parentchild(o.root);
            cout<<endl;
            break;
        case 8:
             o.mirror(o.root);
            cout<<endl;
        break;
        case 9:
            cout<<o.heightoftree(o.root);
            cout<<endl;
            break;
        case 10:
            o.levelorder(o.root);
            cout<<endl;
        default:
            break;
        }

    }

}
