#include<iostream>
using namespace std;
int numNode=0;
int start=0;

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
	int search(node *current, int val){
	if (current==NULL){
	cout<<"Not there\n";
	return 0;
	 }
	else {
	if (val<current->data)	{search(current->left, val);}
	else if (current->data==val){cout<<"The value is there\n";
					return 1;}
	else if (val>current->data) {search(current->right, val);}
	else {cout<<"Not there\n";
		return 0;}
	}	
	}
	
		void count(node*current){
		if (current == NULL) {return;}
		else 
			count (current->left);
			numNodes++;
			count (current->right);
			}
			
	void rangeFinder(node*current, int a, int b){
		if (current==NULL){
			return;}
		else if (b<a) { cout<< "Please enter the first value smaller than the second\n"; }
		else if ((current->data<a)||(current->data>b)){ return; }
		else {
			rangeFinder(current->left, a, b);
			cout<<current->data<<" ";
			start++;
			rangeFinder(current->right, a, b);
		}
	}
};


int main()
{	 int num;
	 bstree obj;
	 obj.insert(obj.root,7);
	 obj.insert(obj.root,3);
	 obj.insert(obj.root,4);
	 obj.insert(obj.root,1);
	 obj.insert(obj.root,8);
	 obj.display(obj.root);
	 cout <<"\nWhich number do you want to search for?\n";
	 cin>>num;
	 obj.search(obj.root,num);
 	 obj.count(obj.root);
	 cout<<numNodes<<endl;
	 obj.rangeFinder(obj.root, 1, 7);
	 cout<<"\nThe number of nodes in the range is"<<start<<endl;
	 return 0;
}




		

