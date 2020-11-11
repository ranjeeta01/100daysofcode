#include<bits/stdc++.h>
using namespace std;
int minDiff(int arr[],int n,int k){
	if(n==0 || k==0)
		return 0;
	sort(arr,arr+n);
	if(n<k)
		return -1;
	int min_diff = INT_MAX;
	for(int i=0;i+k-1<n;i++){
		int diff = arr[i+k-1] - arr[i];
		if(diff<min_diff)
			min_diff = diff;
	}
	return min_diff;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int k,n;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<minDiff(arr,n,k)<<endl;
	}
	return 0;
}