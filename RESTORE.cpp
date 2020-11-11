#include<bits/stdc++.h>
using namespace std;
#define ff(i,n) for(int i=0;i<n;i++)
typedef long long int ll;
#define MM 100005
bool primes[MM];
void sieve(){
	memset(primes,true,sizeof(primes));
	for(int i=2;i*i<MM;i++){
		if(primes[i]==true){
			for(int j=i*i;j<MM;j+=i){
				primes[j]=false;
			}
		}
	}
}

/*

i/p
2
5
5 2 3 4 5
4
4 4 4 4

multiple o/p's are possible
11 3 5 7 11 
7 7 7 7 

or 

2 6 5 3 4
2 6 3 12


*/
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> B(n);
		ff(i,n){
			cin>>B[i];
		}
		vector<ll> A(n);
		sieve();
		ll idx=0;
		for(int i=2;i<MM;i++){
			if(primes[i]==true){
				A[idx++] = i;
				//cout<<A[idx-1]<<" ";
			}
			if(idx==n)
				break;
		}
		for(int i=1;i<=n;i++){
			if(i != B[i-1]){
				A[i-1] = A[B[i-1]+1];
			}
		}
		ff(i,n){
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}