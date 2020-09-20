#include<bits/stdc++.h>
using namespace std;

class meeting{
private:
	int start;
	int end;
public:
	meeting(){
		start = 0;
		end = 0;
	}
	int getstart(){
		return start;
	}
	int getend(){
		return end;
	}
	void setstart(int n){
		start = n;
	}
	void setend(int n){
		end = n;
	}
};

bool sortstart(meeting a,meeting b){
	return a.getstart()<b.getstart();
}

vector<pair<int,int>> overlap(meeting meetings[],int n){
	vector<pair<int,int>> res;
	sort(meetings,meetings+n,sortstart);
	pair<int,int> temp;
	res.push_back({meetings[0].getstart(),meetings[0].getend()});
	for(int i=1;i<n;i++){
		//cout<<meetings[i].getstart()<<" "<<meetings[i].getend()<<endl;
		int si = meetings[i].getstart(); 
		int ei = meetings[i].getend();
		temp = res.back();
		if(temp.second>=si){
			if(ei>temp.second){
				res.pop_back();
			    res.push_back({temp.first,ei});
			}
		}
		else{
			res.push_back({si,ei});
		}
	}
	return res;
}

/*

**input 

5
0 1
3 5
4 8
10 12
9 10

**output

0 1
3 8
9 12

*/

int main(){
	int n,s,e;
	cin>>n;
	meeting meetings[n];
	for(int i=0;i<n;i++){
		cin>>s>>e;
		meetings[i].setstart(s);
		meetings[i].setend(e);
	}
	vector<pair<int,int>> res = overlap(meetings,n);
	for(int i=0;i<res.size();i++){
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}
	return 0;
}