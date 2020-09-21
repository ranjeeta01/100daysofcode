#include<bits/stdc++.h>
using namespace std;
int starting_point(vector<int> stations[],int n){
	int gasSum=0,start=0,costSum=0,tank=0;
	for(int i=0;i<n;i++){
		costSum+=stations[i][0];
		gasSum+=(i+1);
		tank+= (i+1) - stations[i][0];
		if(tank<0){
			start = i+1;
			tank = 0;
			//cout<<start<<" "<<tank<<endl;
		}
	}
	return (gasSum<costSum)?-1:start;
}

int starting_point2(vector<int> stations[],int n){  // O(n) since i = i+j -> looping each element only once
	int i=0,tank=0,j;
	for(;i<n;i+=j){
		tank = 0;
		for(j=1;j<=n;j++){
			int k = (i+j-1)%n;
			tank+= (k+1)-stations[k][0];
			if(tank<0)
				break;
		}
		if(j>n)
			return i;
	}
	return -1;
}
/*

Input 1
5
1 3
2 4
3 5
4 1
5 2

output 1
4

input2
3
1 3
2 4
3 3

output2
-1

*/

int main(){
	int n;
	cin>>n;
	vector<int> stations[n];
	int x,y;
	//memset(stations,0,sizeof stations);
	for(int i=0;i<n;i++){
		cin>>x>>y;
		x--;
		stations[x].push_back(y);
	}
	cout<<starting_point2(stations,n)<<endl;
	return 0;
}