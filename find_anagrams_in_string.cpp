/*
Given a string s and a non-empty string p, 
find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both
strings s and p will not be larger than 20,100.
The order of output does not matter.
*/
#include<bits/stdc++.h>
using namespace std;
void printAnagramPos(string s,string p){
	vector<int> hashs(26,0);
	vector<int> hashp(26,0);
	int left = 0, right = 0, window = p.length();
	if(s.length()<window){
		cout<<0<<endl;
		return ;
	}
	while(right<window){
		hashs[s[right]-'a']++;
		hashp[p[right]-'a']++;
		right++;
	}
	right--;
	while(right<s.length()){
		if(hashs==hashp){
			cout<<left<<" "; 
		}
		right++;
		if(right!=s.length())
			hashs[s[right]-'a']++;
		hashs[s[left]-'a']--;
		left++;
	}
	return;
}
/*
input 
bbabcba
abc

output
2 4

time complexity => O(length of s * 26) since 26 is the 
size of alphabets we need to compare when we compare both the hashmaps!!
*/
int main(){
	string s,p;
	cin>>s;
	cin>>p;
	printAnagramPos(s,p);
	return 0;
}