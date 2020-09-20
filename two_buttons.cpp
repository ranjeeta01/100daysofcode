#include<bits/stdc++.h>
using namespace std;
int ans[100005];
int bfs(int x,int y){
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int num = q.front();
		q.pop();
		if(num*2<=y){
			if(num*2==y)
			   return ans[num]+1;
			q.push(num*2);
			ans[num*2] = ans[num]+1;
		}
		if(num-1>=1 && num-1<y){
			if(num-1==y)
			   return ans[num]+1;
			q.push(num-1);
			ans[num-1] = ans[num]+1;
		}
	}
	return -1;
}
int main(){
    int num,res;
    memset(ans,0,sizeof ans);
    cin>>num>>res;
    cout<<bfs(num,res)<<endl;
	return 0;
}