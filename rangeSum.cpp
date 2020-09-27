#include<bits/stdc++.h>
using namespace std;
/*void merge(vector<int>& pref,int low1,int high1,int low2, int high2){
	vector<int> temp;
	int i=low1,j=low2;
	while(i<=high1 && j<=high2){
		if(pref[i]<pref[j])
			temp.push_back(pref[i++]);
		else
			temp.push_back(pref[j++]);
	}
	while(i<=high1) 
		temp.push_back(pref[i++]);
	while(j<=high2)
		temp.push_back(pref[j++]);
	pref = temp;
	return;
} */
int mergesort(vector<int>& sums,int start,int end,int lower,int upper){
	if (end - start <= 1) return 0;
    int mid = (start + end) / 2;
    int count = mergesort(sums, start, mid, lower, upper) 
              + mergesort(sums, mid, end, lower, upper);
    int j = mid, k = mid, t = mid;
    vector<int> cache(end - start);
    for (int i = start, r = 0; i < mid; ++i, ++r) {
        while (k < end && sums[k] - sums[i] < lower) k++;
        while (j < end && sums[j] - sums[i] <= upper) j++;
        while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
        cache[r] = sums[i];
        count += j - k;
    }
	for(int i=0;i<sums.size();i++)
		sums[i] = cache[i];
	//merge(pref,start,mid-1,mid,end);
	return count;
}
int rangeSum(vector<int>& arr,int n,int low,int high){
	vector<int> pref(n+1,0);
	for(int i=0;i<n;i++)
		pref[i+1] = pref[i] + arr[i];
	return mergesort(pref,0,n+1,low,high);
}
/*

input
3
-2 5 -1
low = -2  high = 2

output
3

[0,0]=-2,[0,2]=-2+5-1=2,[2,2]=-1 => all values counted here lie 
between [-2,2] (inclusive)

input
2
0 0
low=0 high = 0

output
3
[0,0] [0,1] [1,1]

*/
int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int low,high;
	cin>>low>>high;
	cout<<rangeSum(arr,n,low,high)<<endl;
	return 0;
}


/*

*** alternate way is to store running sum in a multiset and then 
find distance bw upper_bound(sum-lower) and lower_bound(sum-upper).

multiset<long long> m;
int sum = 0;
int count=0;
m.insert(sum);
for(int n:nums){
	sum+=n;
	count += distance(m.lower_bound(sum-upper),m.upper_bound(sum-lower));
	m.insert(sum);
}
return count;

*/