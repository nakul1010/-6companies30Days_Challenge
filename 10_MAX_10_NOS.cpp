/*
10- Find max 10 numbers in a list having 10M entries
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	priority_queue< int, vector<int>, greater<int> >pq;//vector<int> forgot
	while(1)
	{
		cout<<"Enter Number : ";
		cin>>n;
		if(n==-1)
			break;
		if(pq.size()==3 && pq.top()<n)
		{
			pq.pop();
			pq.push(n);
		}
		else if(pq.size()<3)
			pq.push(n);
	}
	
	while(pq.empty()==false)
	{
		cout<<pq.top()<<"  ";
		pq.pop();
	}
	return 0;
}
