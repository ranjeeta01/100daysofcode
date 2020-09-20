#include<bits/stdc++.h>
using namespace std;
string minString(vector<string>& v,string s){
	int n = v.size();
	int m = s.length();
	string res;
	int i=0;
	bool flag =0;
	while(i<=m){
		for(int j=0;j<n;j++){
			if(i<v[j].length() && v[j][i]==s[i])
				continue;
			else{
				flag=1;
				break;
			}
		}
		if(flag==0)
			res+=s[i];
		else
			break;
		i++;
	}
	if(res=="")
		return "not possible";
	return res;
}
/*

**input 
1
stfu
appbsdk

**output
not possible

*/
int main(){
	int n;
	cin>>n;
	vector<string> v(n);
	string x;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	cin>>x;
	cout<<minString(v,x)<<endl;
	return 0;
}