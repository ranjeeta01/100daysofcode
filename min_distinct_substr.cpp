#include<bits/stdc++.h>
using namespace std;
#define ff(i,n) for(int i=0;i<n;i++)

/*

input 
GEEKSGEEKSFOR

output
GEEKSFOR

*/
int main(){
	string s;
	cin>>s;
	unordered_map<char,int> map;
	ff(i,s.length()){
		map[s[i]]++;
	}
	int max_distinct = map.size();
	int min_len = INT_MAX;
	int count =0;
	int start = 0,start_idx = -1;
	unordered_map<char,int> curr_count;
	ff(i,s.length()){
		curr_count[s[i]]++;
		if(curr_count[s[i]]==1) // if distinct char is added in curr string 
			count++;
		if(count == max_distinct){
			while(curr_count[s[start]]>1){
				if(curr_count[s[start]]>1)
					curr_count[s[start]]--;
				start++;
				//cout<<start<<endl;
			}
			int window_len = i-start+1;
			if(window_len<min_len){
				min_len = window_len;
				start_idx = start;
			}
		}
	}
	//cout<<max_distinct<<endl;
	cout<<s.substr(start_idx,min_len)<<endl;
	return 0;
}