#include<bits/stdc++.h>
using namespace std;
class Tree{
public:
	int val;
	Tree *left;
	Tree *right;
	Tree(int data){
		val = data;
		left = nullptr;
		right = nullptr;
	}
};

pair<int,bool> helper(Tree* root){
	if(!root)
		return {0,true};
	bool isunival = true;
	pair<int,bool> left = helper(root->left);
	pair<int,bool> right = helper(root->right);
	if(!right.second && !left.second)
	    isunival = true;
	if(!root->val && root->left->val!=root->val)
		isunival = false;
	if(!root->val && root->right->val!=root->val)
		isunival = false;
	if(isunival)
		return {right.first + left.first + 1, true};
	else
		return {right.first + left.first, false};
}

int unival_count(Tree* root){
	pair<int,bool> temp = helper(root);
	return temp.first;
}

// O(n) time complexity in this case

int main(){
	Tree* root = new Tree(2);
	root->left = new Tree(3);
	root->left->right = new Tree(3);
	root->left->left = new Tree(3);
	cout<<unival_count(root)<<endl;  //count = 4 three nulls and one 333;
	return 0;
}