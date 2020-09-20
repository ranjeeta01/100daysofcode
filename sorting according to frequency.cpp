#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        int a[n];
        //_MAP_<int,int> hash;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int count[n];
            for(int i=0;i<n;i++){
                count[i]=0;
                if(a[i]!=-1){
                    for(int j=0;j<n;j++){
                        if(a[i]==a[j]){
                            count[i]++;
                            a[j]=-1;
                        }
                    }
                }
                else{
                    count[i]=-1;
                }
            }
            for(int i=0;i<n;i++){
                cout<<count[i];
            }
        t--;
    }
    return 0;
}