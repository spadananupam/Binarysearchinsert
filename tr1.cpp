#include<iostream>
using namespace std;

//trees
class node{
	public:
	int data;
	node *parent;
	node *left;
	node *right;
	node(){
		data=0;
		parent=NULL;
		left=NULL;
		right=NULL;
	}
};

class bstree{
	//insert a node
	public:
	node *root;
	bstree(){
		root=NULL;
	}
	//node *current=NULL;
	void insert(node *current, int data){	
	//go and check if there is a root
	node *temp = new node;
	temp->data= data;
	if (root==NULL){
		root=temp;
		node *current=root;
	}
	//see which one is bigger
	else if (data<current->data){
		if (current->left!=NULL){
			insert(current->left, data);
		}
		else {current->left=temp;}
	}
	//if the data you give is bigger
	else if (current->right!=NULL){
		insert (current->right, data);
	}
	else current->right=temp;
	}
	//done inserting
	
	void display(node *current){
	//current=root;
	if (current==NULL){
		return;
	}
	else {
		display(current->left);
		cout<<" "<<current->data<<" ";
		display(current->right);
	}
	}
};


int main()
{
	 bstree obj;
	 obj.insert(obj.root,7);
	 obj.insert(obj.root,3);
	 obj.insert(obj.root,4);
	 obj.insert(obj.root,1);
	 obj.insert(obj.root,8);
	 obj.display(obj.root);
	 return 0;
}




		
