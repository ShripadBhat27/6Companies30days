#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(){

	stack<string> sc;
	stack<int> st;
	string s,ans="",upto;
	sc.push(ans);
	cin>>s;
	string times="";
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9')
			times+=s[i];
		else if(s[i]=='['){
			st.push(stoi(times));
			times="";
			sc.push(s.substr(i,1));
		}	
		else if(s[i]>='a'&&s[i]<='z'){
				sc.push(s.substr(i,1));
		}
		else if(s[i]==']'){
				int t=st.top()-1;st.pop();
				string rev="";
				while(sc.top()!="["){
					rev=sc.top()+rev;sc.pop();
				}
				sc.pop();
				string append=rev;

				while(t--)
					rev+=append;
				// cout<<sc.size()<<""<<sc.top()<<"\n";
				sc.top()+=rev;
		}
	}

	cout<<sc.top();
	// while(!sc.empty()){
	// 	cout<<sc.top()<<"\n";sc.pop();
	// }
	


	return 0;
}