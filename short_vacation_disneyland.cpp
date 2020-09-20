#include<bits/stdc++.h>
using namespace std;

void dfs(int source,vector<int> v[],vector<bool>& visited){
	visited[source]=true;
	//int count=0;
	//cout<<source<<" ";
	for(int i=source;i<visited.size();i++)
		if(visited[i])
			cout<<i<<" ";
	for(int i=1;i<v[source].size();i++){
		if(!visited[i])
			dfs(i,v,visited);
		//visited[i] = false;
	}
	cout<<endl;
	//cout<<count<<"*"<<endl;
	//return count;
}


void minTickets(vector<int> v[],vector<bool>& visited,int n){
	//int total=0;
	for(int i=1;i<n;i++){
		dfs(i,v,visited);
	}
	//cout<<total<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v[n+1];
		int x,y;
		for(int i=0;i<=n;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		vector<bool> visited(n+1,0);
		minTickets(v,visited,n+1);
	}
	return 0;
}