#include<bits/stdc++.h>
using namespace std;
vector<int> v[10];
int outdegree[10];
int res;
/*
** input
7 6
1 2
1 3
3 4
3 5
5 6
5 7
** output
2 0 2 0 2 0 0 
2*
1
4*
1
6*
1
7*
0
5*
0
3*
0
1*
3  ->count 
*/
void topological(int n){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(outdegree[i]==0)
			q.push(i);
		cout<<outdegree[i]<<" ";
	}
	cout<<endl;
	int node;
	while(!q.empty()){
		node = q.front();
		cout<<node<<"*"<<endl;
		q.pop();
		for(int i=0;i<v[node].size();i++){
			outdegree[v[node][i]]--;
			cout<<outdegree[v[node][i]]<<endl;
			if(outdegree[v[node][i]]==0){
				q.push(v[node][i]);
				res++;
			}
		}
	}
}
int main(){
	int vertex,edge,x,y;
	res=0;
	cin>>vertex>>edge;
	for(int i=0;i<edge;i++){
		cin>>x>>y;
		v[y].push_back(x);
		//v[y].push_back(x); k
		outdegree[x]++;
		if(!outdegree[y])
			outdegree[y]=0;
	}
	topological(vertex);
	cout<<res<<endl;
	return 0;
}