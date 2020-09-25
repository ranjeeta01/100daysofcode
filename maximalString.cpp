#include<bits/stdc++.h>
using namespace std;
static string mx;
// print maximum string after k swaps !
void swap(string &s,int i,int j){
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}
void findMaximum(string s,int k){
	if(s.compare(mx)>0)
		mx = s;
	if(k==0)
		return;
	for(int i=0;i<s.length()-1;i++){
		for(int j=i+1; j<s.length();j++){
			if(s[j]>s[i]){
				swap(s,i,j);
				findMaximum(s,k-1);
				swap(s,i,j);
			}
		}
	}
}

/*

time taken for each level is O(n*n) => O(n*n*k); -> k==number of recursive calls made / swaps allowed !

input
7599
2
output
9975

input
254
1
output
524

*/
int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	mx = s;
	findMaximum(s,k);
	cout<<mx<<endl;
	return 0;
}