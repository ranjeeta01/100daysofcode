#include<bits/stdc++.h>
using namespace std;

int visited[10];
int dist[10];
vector<pair<int,int>> v[10];

/*

**input

5 7
1 4 5
1 2 6
4 2 2
4 5 1 
2 5 2
2 3 5
5 3 5

**output

0 6 11 5 6

*/

void dijkstra(int source){
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
	//visited[source] = 1;
	dist[source] = 0;
	pq.push({dist[0],source});
	pair<int,int> temp;
	while(!pq.empty()){
		temp = pq.top();
		pq.pop();
		int node = temp.second;
		//cout<<node<<endl;
		if(visited[node]==1)
			continue;
		visited[node]=1;
		for(int i=0;i<v[node].size();i++){
			//cout<<v[node][i].second<<endl;
			if(dist[node] + v[node][i].second < dist[v[node][i].first] && visited[v[node][i].first]==0){
				dist[v[node][i].first] = dist[node] + v[node][i].second;
				pq.push({dist[v[node][i].first],v[node][i].first});
			}
		}
	}
}

int main(){
	int vertex,e,x,y,wt;
	cin>>vertex>>e;
	for(int i=0;i<e;i++){
		cin>>x>>y>>wt;
		v[x].push_back(make_pair(y,wt));
		v[y].push_back(make_pair(x,wt));
	}
	for(int i=1;i<=vertex;i++)
		dist[i]=INT_MAX;
	dijkstra(1);
	for(int i=1;i<=vertex;i++){
		cout<<dist[i]<<" ";  // min distance of each node from source node
	}
	cout<<endl;
	return 0;
}