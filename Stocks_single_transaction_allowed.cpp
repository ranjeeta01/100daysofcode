#include<bits/stdc++.h>
#define ff(i,n) for(int i=0;i<n;i++)
using namespace std;
// atmost one transaction allowed
int maxProfit(int arr[],int n){
	int buy = INT_MAX,profit = 0;
	ff(i,n){
		if(arr[i]<buy)
			buy = arr[i];
		else if(arr[i]-buy>profit)
			profit = arr[i] - buy;
	}
	return profit;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	ff(i,n){
		cin>>arr[i];
	}
	cout<<maxProfit(arr,n)<<endl;
	return 0;
}