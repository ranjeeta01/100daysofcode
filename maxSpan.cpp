#include<bits/stdc++.h>
using namespace std;
int maxSpan(vector<int> arr,int n){
	int res=INT_MIN;
	for(int i=0;i<n;i++){
		int j=n-1;
		while(arr[j]!=arr[i])
			j--;
		res = max(res,j-i+1);
	}
	return res;
}

int maxSpanOptimum(vector<int> arr,int n){
	unordered_map<int,int> hash;
	int res = INT_MIN;
	for(int i=0;i<n;i++){
		if(!hash[arr[i]]){
			hash[arr[i]] = i;
		}
		else{
			res = max(res,i-hash[arr[i]]+1);
		}
	}
	return res;
}

/*

** input

8
2 4 3 2 4 2 7 4

** output

7
7

*/

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<maxSpan(arr,n)<<endl;
	cout<<maxSpanOptimum(arr,n)<<endl;
	return 0;
}