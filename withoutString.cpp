#include<bits/stdc++.h>
using namespace std;
string withoutString(string s,string rem){
	string res=s;
	for(int i=0;i<s.length();i++){
		if(s[i]==rem[0])
			res.replace(i,rem.length(),"");
	}
	return res;
}
int main(){
	string s,rem;
	cin>>s;
	cin>>rem;
	cout<<withoutString(s,rem)<<endl;
	return 0;
}