#include<bits/stdc++.h>
using namespace std;

class bst{
public:
	int data;
	bst *left;
	bst *right;

	bst(int n){
		data = n;
		left = nullptr;
		right = nullptr;
	}
	~bst(){
		delete left;
		delete right;
	}
};

// recursive solution O(n) or best time O(lgn) only recursive stack space is used.
int secondLargest(bst* root,int &count){
	if(!root)
		return 0;
	int temp = secondLargest(root->right,count);
	count--;
	if(temp)
		return temp;
	if(count==0)
		return root->data;
	return secondLargest(root->left,count);
}
/*

for 2nd largest output
14

for 6th largest
3

*/

int main(){
	bst* root = new bst(10);
	root->left = new bst(6);
	root->right = new bst(14);
	root->left->left = new bst(3);
	root->left->right = new bst(8);
	root->right->right = new bst(15);
	int count = 6;
	cout<<secondLargest(root,count)<<endl;
	return 0;
}