#include<bits/stdc++.h>
using namespace std;
int water(vector<int> arr, int c1,int c2){
	int n = arr.size();
	int f2 = n-1, count=2,f1=0,can1=c1,can2=c2;
	while(f1<=f2){
		//cout<<f1<<" "<<f2<<" "<<count<<" "<<can1<<" "<<can2<<endl;
		if(arr[f1]<=can1 && arr[f2]<=can2 && f1!=f2){
			can1 -= arr[f1];
			can2 -=arr[f2];
			f1++;
			f2--;
		}
		else if((can1<arr[f1] || can2<arr[f2]) && f1!=f2){
			if(can1<arr[f1]){
				arr[f1]-=can1;
				can1=c1;
				count++;
			}
			if(can2<arr[f2]){
				arr[f2]-=can2;
				can2 = c2;
				count++;
			}
		}
		else if((can1<arr[f1] || can2<arr[f2]) && f1==f2){
			if(can1+can2 >= arr[f1])
				break;
			else{
				can1 = ((c1>c2)&&(c1>arr[f1]))?c1:c2;
				count++;
				break;
			}
		}
	}
	return count;
}

/*

input
5
2 4 5 1 2
5 7

output
3

*/

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	int c1,c2;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>c1>>c2;
	cout<<water(arr,c1,c2)<<endl;
	return 0;
}