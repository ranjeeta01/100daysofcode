// dp solution O(n^2) time and O(n) space
int Solution::canJump(vector<int> &A) {
    int N=A.size();
    int dp[N]; // dp[i] will be equal to 1, if we can reach i from 0.
    dp[0]=1;
    for(int i=1; i<N; i++){
        dp[i]=0;
        for(int j=0; j<i; j++){
            if(dp[j]==1){
                if(i-j <= A[j]){
                    dp[i]=1;
                    break;
                }
            }
        }
    }
    return dp[N-1];
}

// O(n) time and space O(1)
int Solution::canJump(vector<int> &A){
	int can_reach = 0,n=A.size();
	for(int i=0;i<=can_reach && i<n;i++){
		if(i==n-1)
			return 1;
		else
			can_reach = max(can_reach,i+A[i]);
	}
	return 0;
}