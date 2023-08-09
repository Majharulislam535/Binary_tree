#include<bits/stdc++.h>

using namespace std;

class Node{
public:
   int value;
   Node *left;
   Node *right;

   Node(int value){
       this->value = value;
       this->left=NULL;
       this->right = NULL;
    }

};

Node* inputLevel(){
 int vla;
 cin>>vla;
 Node*root;

 if(vla==-1)
    root=NULL;
 else
  root=new Node(vla);

 queue<Node*>q;
 if(root)
    q.push(root);

 while(!q.empty()){
    Node *p=q.front();
    q.pop();


    int l,r;
    cin>>l>>r;
    Node *left;
    Node *right;

    if(l== -1){
        left=NULL;
    }
    else{
        left = new Node(l);
    }

    if(r== -1){
        right=NULL;
    }
    else{
        right = new Node(r);
    }


    p->left = left;
    p->right = right;


    if(p->left) q.push(p->left);
    if(p->right) q.push(p->right);





 }

return root;

}


void levelOrder(Node * root){

  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
     Node * f = q.front();
     q.pop();

     cout<<f->value<<" ";

     if(f->left)
        q.push(f->left);
     if(f->right)
        q.push(f->right);
  }


}


int counter(Node * root){
    if(root==NULL) return 0;
    int l= counter(root->left);
    int r = counter(root->right);
    return l+r+1;
 }

int main(){

   Node * root = inputLevel();
   //levelOrder(root);
   int result = counter(root);
   cout<<result<<endl;


return 0;
}
