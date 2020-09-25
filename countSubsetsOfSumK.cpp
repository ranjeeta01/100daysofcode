#include<bits/stdc++.h>
using namespace std;
int countSubsetsOfSumK(vector<int> arr,int k){
	int n = arr.size();
	vector<vector<int>> dp(n+1,vector<int>(k+1));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(j==0)
				dp[i][j] = 1;
			else if(i==0 && j!=0)
				dp[i][j] = 0;
			else if(arr[i-1]<=j)
				dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][k];
}
/*

input
5 30
10 20 30 5 25

output
3

*/
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<countSubsetsOfSumK(arr,k)<<endl;
	return 0;
}