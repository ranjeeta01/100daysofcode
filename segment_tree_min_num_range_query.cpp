#include<bits/stdc++.h>
using namespace std;
int st[400004],arr[100001];  //since segment tree takes 4n space -> so size of st = 4n, n->size of array
void build(int si , int ss , int se)
{
	if(ss == se)   // that means we are at leaf node -> Eg. 1,1 2,2 3,3 4,4 etc. 
	{
		st[si] = arr[ss];
		return;
	}
 
	int mid = (ss + se)/2;
	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);
 
	st[si] = min(st[2*si] , st[2*si+1]);
}
 
int query(int si , int ss , int se , int qs , int qe)
{
	if(qe < ss || qs> se)  // segment start is greater than start of query => outofbound (no need to traverse here).
		return INT_MAX-1;   // will be ignored in the final step since there is no intersection with query
 
	if(ss>=qs && se<=qe)   //if the segment is completely inside the query segment
		return st[si];
 
	int mid = (ss + se)/2;
	int l = query(2*si , ss , mid , qs , qe);
	int r = query(2*si+1 , mid+1 , se , qs , qe);
 
	return min(l , r);
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	build(1,1,n);
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		int res = query(1,1,n,l+1,r+1);
		cout<<res<<endl;
	}
	return 0;
}