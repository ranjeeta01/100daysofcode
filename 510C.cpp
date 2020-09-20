#include<bits/stdc++.h>
using namespace std;
bool visited[26][26];
int indegree[26];
/*

**input 
2
abcxyz
abcuv

**output
abcdefghijklmnopqrstvwxyzu
// str1<str2 if x<u by definition of alphabets!! so u should come after x y z ;


*/
string topological(vector<string> v,int n){
	int pos,len;
	for(int i=0;i<n-1;i++){
		len = min(v[i].length(),v[i+1].length());
		for(pos=0;pos<len;pos++){
			if(v[i][pos]!=v[i+1][pos])
				break;
		}
		if(pos!=len){
			if(!visited[v[i][pos]-'a'][v[i+1][pos]-'a']){
				visited[v[i][pos]-'a'][v[i+1][pos]-'a'] = true;
				indegree[v[i+1][pos]-'a']++;
			}
		}
		else{
			if(v[i].length()>v[i+1].length())
				return "Impossible";
		}
	}
	queue<int> q;
	for(int i=0;i<26;i++){
		if(!indegree[i])
			q.push(i);
	}
	int tp,p=0;
	int ans[26];
	while(!q.empty()){
		tp = q.front();
		q.pop();
		ans[p++] = tp;
		for(int i=0;i<26;i++){
			if(visited[tp][i]){
				indegree[i]--;
				if(!indegree[i])
					q.push(i);
			}
		}
	}
	if(p!=26)
		return "Impossible";
	string res;
	for(int i=0;i<26;i++)
		res+=('a'+ans[i]);
	return res;
}
int main(){
	int n;
	cin>>n;
	vector<string> v;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		v.push_back(s);
	}
	//memset(indegree,0,sizeof 0);
	for(int i=0;i<26;i++)
		indegree[i]=0;
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			visited[i][j]=false;
	cout<<topological(v,n)<<endl;
	//cout<<'n'-'a'<<endl;
	return 0;
}