int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end());
    int n = A.size();
    int count=1;
    priority_queue<int,vector<int>,greater<int>> q;
    q.push(A[0][1]);
    for(int i=1;i<n;i++){
        if(A[i][0]<q.top()){
            count++;
        }
        else{
            q.pop();
        }
        q.push(A[i][1]);
    }
    return count;
}
