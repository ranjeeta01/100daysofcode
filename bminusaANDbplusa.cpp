#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
unsigned long long int power(unsigned long long int a,unsigned long long int y) 
{ 
    unsigned long long int ans = 1;
    while(y){
        cout<<ans<<"-"<<a<<endl;
        if(y&1){
            ans=(ans*a)%MOD; 
            cout<<ans<<"&";
        }
        a=(a*a)%MOD; 
        y=y/2;
    }
    return ans;
} 
/*

input 4 999 1881
output  728771468 762921230

input 1 3 1
output 1 3

input 1 3 2
output 2 4

*/
int main() {
    unsigned long long int a,b,n,temp_a,temp_b;
    cin>>a>>b>>n;
    temp_a = a;
    temp_b=b;
    if(n%2!=0){
        a = power(2,n/2)*temp_a;
        b = power(2,n/2)*temp_b;
    }
    else{
        a = power(2,(n/2)-1)*(temp_b - temp_a);
        b = power(2,(n/2)-1)*(temp_b + temp_a);
    }
    //cout<<pow(2,1881)<<"***"<<endl;
    cout<<a%1000000007<<" "<<b%1000000007;
	return 0;
}