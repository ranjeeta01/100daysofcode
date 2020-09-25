#include<bits/stdc++.h>
using namespace std;
/*

Given weights and values of n items, put these items in a knapsack of capacity W
to get the maximum total value in the knapsack. 
In other words, 
given two integer arrays val[0..n-1] and wt[0..n-1] which represent values 
and weights associated with n items respectively. 
Also given an integer W which represents knapsack capacity. 
Find out the maximum value subset of val[]
such that sum of the weights of this subset is smaller than or equal to W. 
You cannot break an item, either pick the complete item or 
don’t pick it (0-1 property).

*/

/*

input
50 3
10 20 30
60 100 120

output
220

*/
int knapsack(vector<int> weight,vector<int> values,int W){
	int n = weight.size();
	vector<vector<int>> dp(n+1,vector<int>(W+1));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(weight[i-1]<=W){
				dp[i][j] = max(dp[i-1][j],values[i-1]+dp[i-1][j-weight[i-1]]);
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][W];
}
int main(){
	int W,N;
	cin>>W>>N;
	vector<int> weight(N),values(N);
	for(int i=0;i<N;i++){
		cin>>weight[i];
	}
	for(int i=0;i<N;i++){
		cin>>values[i];
	}
	cout<<knapsack(weight,values,W)<<endl;
	return 0;
}