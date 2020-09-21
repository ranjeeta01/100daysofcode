#include<bits/stdc++.h>
using namespace std;
string dictionary[] = {"mobile","samsung","sam","sung","man","mango", 
                           "icecream","and","go","i","like","ice","cream"};
bool isPresent(string s){
	int n = sizeof(dictionary)/sizeof(dictionary[0]);
	//cout<<n<<" "<< sizeof(dictionary)<<endl;  13 312 
	//cout<<sizeof(dictionary[0])<<endl; 24
	// or we can use set to store dict items and then check from it if string is present or not!
	// O(n*n) solution -> DP 
	for(int i=0;i<n;i++)
		if(dictionary[i].compare(s)==0)
			return true;
	return false;
}
bool wordBreak(string s){
	int n = s.length();
	vector<bool> dp(n+1,false);
	if(n==0)
		return false;
	for(int i=0;i<=n;i++){
		if(dp[i]==false && isPresent(s.substr(0,i)))
			dp[i] = true;
		if(dp[i]==true){
			if(i==n)
				return true;
			for(int j=i+1;j<=n;j++){
				if(dp[j]==false && isPresent(s.substr(i,j-i)))
					dp[j] = true;
				if(j==n && dp[j]==true)
					return true;
			}
		}
	}
	return false;
}

/*

Input
ilike

output
YES

Input 
likei

output
YES

*/

int main(){
	string s;
	cin>>s;
	if(wordBreak(s))
		cout<<"YES";
	else
		cout<<"NO";
	cout<<endl;
	return 0;
}