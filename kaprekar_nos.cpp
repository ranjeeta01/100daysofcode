#include <bits/stdc++.h>
#include <math.h>

using namespace std;
int digits(int p){
    int count=0;
    while(p){
        p=p/10;
        count++;
    }
    return count;
}

int half(int a){
    int len=digits(a);
    int i=0;
    int h=0;
    while(i<=(len/2)){
        int p=0;
        int num=a%10;
        h= h+(num*(pow(10,p)));
        a=a/10;
        i++;
    }
    return h;
}

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    int s,d,l,r;
    for(int j=p;j<=q;j++){
        int i=1;
        s = p*p;
        d=digits(p);
        if(digits(s)==(2*d)||digits(s)==((2*d)-1)){
            r=half(s);
            l=s-(r*pow(10,digits(r)));
            if(l+r==j){
                cout<<" "<<j;
            }
        }
    }
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
