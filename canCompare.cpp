#include<bits/stdc++.h>
using namespace std;
int canCompare(vector<int> arr,int n){
	int leftsum = 0, rightsum=0;
	for(int i=0;i<n;i++)
		leftsum+=arr[i];
	for(int i=n-1;i>=0;i--){
		rightsum+=arr[i];
		leftsum-=arr[i];
		if(leftsum==rightsum)
			return i;
	}
	return -1;
}

//divides array into two subarrays having same sum in O(n) and O(1) time.

/*

**input 
6
1 2 3 4 5 5 
**output
4

**input
5
1 1 4 2 0
**output
-1

*/

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<canCompare(arr,n)<<endl;
	return 0;
}