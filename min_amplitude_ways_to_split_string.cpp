#include<bits/stdc++.h>
using namespace std;
int minAmplitude(vector<int>& arr,int n){
	sort(arr.begin(),arr.end());
    //cout<<arr[0]<<" "; 
    for(int i=0;i<3;i++){
    	
    }
	return 0;
}
int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<minAmplitude(arr,n)<<endl;
	return 0;
}