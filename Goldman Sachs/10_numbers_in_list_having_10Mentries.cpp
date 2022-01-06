#include <iostream>
#include <queue>
using namespace std;

int main(){
	priority_queue <int, vector<int>, greater<int> > pq;
	long long n;
	cin>>n;
	int num;
	while(n--){
		cin>>num;
		if(pq.size()==10){

			if(num>pq.top()){
				pq.push(num);pq.pop();
			}
		}else
		pq.push(num);
	}
	cout<<"\n\n\n";
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	return 0;
}