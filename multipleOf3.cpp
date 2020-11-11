#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    unsigned long long int k,d0,d1;
	    cin>>k>>d0>>d1;
	    unsigned long long int num=(d0*10)+d1,temp;
	    temp = (d0+d1)%10;
	    if(k==2 && num%3==0)
	        cout<<"YES"<<endl;
	   num+=temp;
	   unsigned long long int remGroups = (k-3)/4;
	   int remDigits = (k-3)%4;
	   num+=(remGroups*20);
	   for(int i=0;i<remDigits;i++){
	       temp = (2*temp)%10;
	       num+=temp;
	   }
	   if(num%3==0)
	    cout<<"YES"<<endl;
	   else
	    cout<<"NO"<<endl;
	}
	return 0;
}