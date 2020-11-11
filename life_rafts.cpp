#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i=0;i<n;i++)

/*

input
4 5
1 3 5 2
output
3

*/

int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int start = 0,end = n-1,count=0;
        while(start<=end){
            if(people[end]+people[start]<=limit && end!=start){
                count++;
                start++;
                end--;
            }
            else{
                if(people[start]==limit){
                    count++;
                    start++;
                }
                else{
                    count++;
                    end--;
                }
            }
        }
        return count;
  }

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> people(n);
	loop(i,n){
		cin>>people[i];
	}
	cout<<numRescueBoats(people,k)<<endl;
	return 0;
}