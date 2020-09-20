#include<bits/stdc++.h>
using namespace std;
int sumNumbers(string s){
	int sum =0;
	string temp="";
	for(char c:s){
		if(isdigit(c))
			temp += c;
		else{
			sum += atoi(temp.c_str());
			temp = "";
		}
	}
	//cout<<sum<<endl;
	return sum+atoi(temp.c_str());
}

/*

**input

hello123bc1dk

**output

124

*/

int main(){
	string s;
	cin>>s;
	cout<<sumNumbers(s)<<endl;
	return 0;
}