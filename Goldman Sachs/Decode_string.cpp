#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(){

	stack<string> st;

	st.push("shri");

	cout<<st.top()<<"\n";

	st.top()+="pad";

	cout<<st.top()<<"\n";

	cout<<st.size();


	return 0;
}