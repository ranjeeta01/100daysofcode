#include<bits/stdc++.h>
using namespace std;
#define ff(i,n) for(int i=0;i<n;i++)
typedef long long int ll;

/*

i/p
3
3
2 2 2
3
1 2 3
4
2 3 4 5

o/p
2
3
7

*/
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n);
		ff(i,n){
			cin>>v[i];
		}
		sort(v.begin(),v.end(),greater<ll>());
		vector<ll> temp;
		ll i=0,count=0;
		temp.push_back(v[i++]);
		temp.push_back(v[i++]);
		while(i<n){
			count += (temp[0]==0)?temp[1]:min(temp[0],temp[1]);
			ll nxt = abs(temp[0]-temp[1]);
			temp.clear();
			temp.push_back(nxt);
			temp.push_back(v[i++]);
		}
		count+=min(temp[0],temp[1]);
		cout<<count<<endl;
	}
	return 0;
}