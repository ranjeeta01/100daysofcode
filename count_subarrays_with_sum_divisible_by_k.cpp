#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int mod[k];
	memset(mod,0,sizeof(mod));
	int tot_sum = 0;
	for(int i=0;i<n;i++){
		tot_sum+=arr[i];
		mod[((tot_sum%k)+k)%k]++;
	}
	int results = mod[0];
	for(int i=1;i<k;i++){
		if(mod[i]>1)
			results += ((mod[i]-1)*mod[i])/2;
	}
	cout<<results<<endl;
	return 0;
}