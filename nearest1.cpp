#include<bits/stdc++.h>
using namespace std;
//int visited[104][104];
/*
*** input

3 4
0 0 0 1
0 0 1 1
0 1 1 0

***output

3 2 1 0 
2 1 0 0 
1 0 0 1 

*/
int dist[104][104];
void bfs(vector<vector<int>> &v, int row,int col){
	queue<pair<int,int>> q;
	int direction[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			dist[i][j] = INT_MAX;
			if(v[i][j]==1){
				//visited[i][j] = 1;
				dist[i][j] = 0;
				q.push({i,j});
			}
		}
	}
	pair<int,int> popped;
	while(!q.empty()){
		popped = q.front();
		q.pop();
		int x = popped.first;
		int y = popped.second;
		for(int i=0;i<4;i++){
			int dir_X = direction[i][0] + x;
			int dir_Y = direction[i][1] + y;
			if(dir_X>=0 && dir_X<row && dir_Y>=0 && dir_Y<col && dist[dir_X][dir_Y]>dist[x][y]+1 ){
				dist[dir_X][dir_Y] = dist[x][y]+1;
				//visited[dir_X][dir_Y] = 1;
				q.push({dir_X,dir_Y});
			}
		}
	}
}
int main(){
	int row,col;
	cin>>row>>col;
	//memset(visited,0,sizeof visited);
	vector<vector<int>> v(row,vector<int>(col));
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>v[i][j];
		}
	}
	/*for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	} */
	bfs(v,row,col);
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			cout<<dist[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}