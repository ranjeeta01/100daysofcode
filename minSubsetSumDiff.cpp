#include<bits/stdc++.h>
using namespace std;
int minSubsetSumDiff(vector<int> arr,int n){
	int arrSum = 0;
	for(int i=0;i<n;i++)
		arrSum+=arr[i];
	int k = arrSum/2;
	vector<vector<int>> dp(n+1,vector<int>(k+1));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(j==0)
				dp[i][j] = 1;
			else if(i==0 && j!=0)
				dp[i][j] = 0;
			else if(arr[i-1]<=j)
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	int diff = INT_MAX;
	for(int j=k;j>=0;j--)
		if(dp[n][j]==true)
			diff = min(diff, arrSum - (2*j));
	return diff;
}
/*

input
5
10 20 30 5 25
output
0

*/
int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<minSubsetSumDiff(arr,n)<<endl;
	return 0;
}