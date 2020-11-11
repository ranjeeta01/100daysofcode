#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*

input
2
4 5
I::M
9 10
MIM_XII:M

output
1
2

*/

int main(){
	int T;
	cin>>T;
	while(T--){
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		ll I=0,M=0,count=0,ans=0;
		bool flag = true;
		while(I<n && M<n){
			if(flag == true){
				flag = false;
			    while(s[I]!='I')
					I++;
				while(s[M]!='M')
					M++;
			}
			//cout<<I<<" "<<M<<endl;
			//break;
			ll big = I>M?I:M;
			ll small = I>M?M:I;
			for(ll i=small+1;i<big;i++){
				if(s[i]==':')
					count++; //count conducting sheets between I and M
				else if(s[i]=='X'){
					I = big+1;
					M = big+1;
					flag = true;
					break;
				}
			}
			if(flag==true)
				continue;
			else{
				ll p = k + 1 - abs(I-M) - count;
				if(p>0){
					ans++;
					I++;
					M++;
					flag = true;
				}
				else{
					if(I<M){
						while(s[I]!='I')
							I++;
						flag = false;
					}
					else{
						while(s[M]!='M')
							M++;
						flag = false;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}