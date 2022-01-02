
#include <iostream>
#include<vector>
using namespace std;

int main() {
	
	int n,m,k;
	cin>>n>>m>>k;
	
	int left=(m%n);
	int ans;
	if(left>(n-k)){
	    left-=(n-k);
	    ans=left;
	}
	else
	    ans=k+left-1;
	    
	   cout<<ans;
	
	
	return 0;
}