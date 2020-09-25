#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> arr,int k){
	int n = arr.size();
	bool dp[n+1][k+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(j==0)
				dp[i][j] = true;
			else if(i==0 && j!=0)
				dp[i][j] = false;
			else if(arr[i-1]<=j)
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][k];
}

/*
input
5 25
10 20 30 5 0

output
Possible


*/
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	if(isPossible(arr,k))
		cout<<"Possible"<<endl;
	else
		cout<<"Not Possible"<<endl;
	return 0;
}