/* 
in this problem we just have to observe from where max length can 
be obtained it can be from left subtree from right subtree or from both left and right subtree.
and we have to return the max of it.
*/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d)
    {
        data=d;left=NULL,right=NULL;
    }
};

node* buildtree(){
    int d;
    cin>>d;
    
    if(d==-1){ 
        //-1 means end
        return NULL;
    }
    
    node * root=new node(d);
    //root->left= as i am storing values
    root->left=buildtree();//left subtree
    root->right=buildtree();//right subtree
 
    return root;
}

int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}

int diameter(node* root)
{
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    
    return max(max(op1,op2),op3);
}

int main() 
{
	node* root=buildtree();
	cout<<"Diameter of a tree is := ";
	cout<<diameter(root)<<endl;
	return 0;
}
