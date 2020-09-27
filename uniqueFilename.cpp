/*
Given an array of strings names of size n. 
You will create n folders in your file system such that, at the ith minute, you will create a folder with the name names[i].
Since two files cannot have the same name, if you enter a folder name which is previously used, 
the system will have a suffix addition to its name in the form of (k), where, 
k is the smallest positive integer such that the obtained name remains unique.
Return an array of strings of length n where ans[i] is the actual name the system will assign to the ith folder when you create it.

input
4
["gta","gta(1)","gta","avalon"]

output
["gta","gta(1)","gta(2)","avalon"]

*/
#include<bits/stdc++.h>
using namespace std;
vector<string> uniqueNames(vector<string> v,int n){
	unordered_map<string,int> map;
	vector<string> res;
	for(int i=0;i<n;i++){
		if(map.count(v[i])==0){
			map[v[i]] = 0;
			res.push_back(v[i]);
		}
		else{
			map[v[i]]++;
			int k = map[v[i]];
			string newName = v[i]+"("+to_string(k)+")";
			while(map.count(newName)!=0){
				k++;
				newName = v[i]+"("+to_string(k)+")";
			}
			map[newName] = 0;
			res.push_back(newName);
		}
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	v = uniqueNames(v,n);
	for(int i=0;i<n;i++)
		cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}