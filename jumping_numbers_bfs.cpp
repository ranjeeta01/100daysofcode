#include<bits/stdc++.h>
using namespace std;
void bfs(int x,int num){
	queue<int> q;
	q.push(num);
	while(!q.empty()){
		num = q.front();
		q.pop();
		if(num<=x){
			cout<<num<<" ";
			int last_digit = num%10;
		    if(last_digit==0)
			    q.push((num*10) + (last_digit +1));
		    else if(last_digit==9)
			    q.push((num*10) +(last_digit - 1));
		    else{
			    q.push((num*10) + (last_digit- 1));
			    q.push((num*10) + (last_digit + 1));
		   }
		}
	}
}
int main(){
	int x;
	cin>>x;
	cout<<"Counting Numbers upto "<<x<<"are: \n";
	cout<<0<<" ";
	for(int i=1;i<=x && i<=9; i++)
		bfs(x,i);
	return 0;
}