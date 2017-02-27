#include <iostream>
using namespace std;



int longestZigZag(int arr[],int l){
	int ans=1;
	int arrp[l];int arrn[l];
	arrp[0]=1;arrn[0]=1;
	for(int i=1;i<l;i++){
		arrp[i]=1;arrn[i]=1;
		for(int j= i-1;j>=0;j--){
		if((arr[i]<arr[j])){
			arrn[i]=max(arrp[j]+1,arrn[i]);}
		else if((arr[i]>arr[i-1])) {
			arrp[i]=max(arrn[j]+1,arrp[i]);
			}
	}
	ans=max(ans,arrp[i]);ans=max(ans,arrn[i]);
	}
	return ans;
	}
int main() {
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	 cout<< longestZigZag(arr,n);
	return 0;
}
