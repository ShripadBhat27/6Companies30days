#include <iostream>
#include <string>
using namespace std;

string solve(string s1,string s2){
	int n=s1.length(),m=s2.length(),i;

	for( i=0;i<n&&i<m;i++){
		if(s1[i]==s2[i]) continue;
		if(s1[i]<s2[i]) return s1;
		else return s2;
	}
	if(i==n) return s1;
	if(i==m) return s2;
}
int main(){
	string s1,s2;
	cin>>s1>>s2;


	cout<<"\n\nSmaller Version :"<<solve(s1,s2);

	return 0;
}