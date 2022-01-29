#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int dp[10001][10001];
int solve(int arr[],int index,int curr_sum,int tot){
	if(curr_sum>tot) return 0;
	if(index==0){
		return dp[index][curr_sum]=abs(tot-2*curr_sum);
	}
	if(dp[index][curr_sum]!=-1) return dp[index][curr_sum];
	return dp[index][curr_sum]=min(solve(arr,index-1,curr_sum+arr[index],tot),solve(arr,index-1,curr_sum,tot));

}


int main(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	int arr[n];
	int tot=0;
	for(int i=0;i<n;i++){
	 cin>>arr[i];tot+=arr[i];

	}

	cout<<solve(arr,n-1,0,tot);

	return 0;
}