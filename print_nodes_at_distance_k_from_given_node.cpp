#include<bits/stdc++.h>
using namespace std;

class Tree{
public:
	int val;
	Tree* left;
	Tree* right;
	Tree(int data){
		val = data;
		left = nullptr;
		right = nullptr;
	}
};

void printKthDistanceNode(Tree* root,int k){
	if(root==NULL)
		return;
	if(k==0){
		cout<<root->val<<endl;
		return;
	}
	printKthDistanceNode(root->left,k-1);
	printKthDistanceNode(root->right,k-1);
}

int printNodeUtil(Tree* root,Tree* target,int k){
	if(root==NULL)
		return -1;
	if(root==target){
		printKthDistanceNode(root,k);
		return 0;
	}
	int dist_left = printNodeUtil(root->left,target,k);
	if(dist_left!=-1){  //that means target has been found and down nodes are printed
		if(dist_left+1==k)
			cout<<root->val<<endl;
		else
			printNodeUtil(root->right,target,k-2-dist_left);
		return 1 + dist_left;
	}
	int dist_right = printNodeUtil(root->right,target,k);
	if(dist_right!=-1){
		if(dist_right+1==k)
			cout<<root->val<<endl;
		else
			printKthDistanceNode(root->left,k-2-dist_right);
		return 1 + dist_right;
	}
	return -1;
}

int printNode(Tree* root,Tree* target,int k){
	if(root==NULL || target==NULL || k<0)
		return -1;
	return printNodeUtil(root,target,k);
}

int main(){
	Tree* root = new Tree(2);
    root->left = new Tree(7);
    root->right = new Tree(9);
    root->right->right = new Tree(3);
    root->left->left = new Tree(10);
    root->left->right = new Tree(6);
    root->left->right->left = new Tree(5);
    root->left->right->right = new Tree(11);
    int x = printNode(root,root->left,2);
    if(x==-1)
    	cout<<"No Node present at desired location!!"<<endl;
	return 0;
}