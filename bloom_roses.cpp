#include<bits/stdc++.h>
using namespace std;

// here,   k-> min size of bunch, n-> min number of bunches reqd.

bool isValid(vector<int> arr,int k,int n,int day){
	int countsize=0,countbunch=0;
	for(int val : arr){
		if(val<=day)
			countsize++;
		else 
			countsize = 0;
		if(countsize == k){
			countsize = 0;
			countbunch++;
		}
		if(countbunch == n)
			return true;
	}
	return false;
}
int bloomday(vector<int> arr,int k,int n){
	int low = INT_MAX, high = INT_MIN;
	for(int i: arr){
		low = min(low,i);
		high = max(high,i);
		while(low<=high){
			int mid = low + (high-low)/2;
			if(isValid(arr,k,n,mid))
				high = mid - 1;
			else 
				low = mid+1;
		}
	}
	return low;
}

// time-> O(n*log(m)) ,  m->max number of days for a rose to bloom

/*

input 

7
1 2 4 9 3 4 1
2 2

output
 
4

*/

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int k;
	cin>>k>>n;
	cout<<bloomday(arr,k,n)<<endl;
	return 0;
}