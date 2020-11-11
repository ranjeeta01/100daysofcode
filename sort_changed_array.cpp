#include<bits/stdc++.h>
using namespace std;
#define ff(i,n) for(int i=0;i<n;i++)
#define fff(i,n) for(int i=0;i+1<n;i++)

void sort_merged(vector<int>& arr,int n){
	vector<int> sorted;
	vector<int> changed;
	fff(i,n){
		if(arr[i]<arr[i+1] && arr[i-1]<arr[i] && i!=0){
			sorted.push_back(arr[i]);
		}
		else{
			changed.push_back(arr[i]);
		}
	}
	std::sort(changed.begin(),changed.end());
	ff(i,sorted.size()){
		cout<<sorted[i]<<" ";
	}
	cout<<endl;
	ff(i,changed.size()){
		cout<<changed[i]<<" ";
	}
	cout<<endl;
	int i=0,j=0,idx=0;
	while(i<sorted.size() && j<changed.size()){
		if(sorted[i]<changed[j]){
			arr[idx] = sorted[i];
			idx++;
			i++;
		}
		else if(changed[j]<sorted[i]){
			arr[idx] = changed[j];
			idx++;
			j++;
		}
		else{
			arr[idx] = changed[i];
			idx++;
			i++;
			j++;
		}
	}
	while(i<sorted.size()){
		arr[idx]=sorted[i];
		idx++;
		i++;
	}
	while(j<changed.size()){
		arr[idx]=changed[j];
		idx++;
		j++;
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	ff(i,n){
		cin>>arr[i];
	}
	sort_merged(arr,n);
	ff(i,n){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}