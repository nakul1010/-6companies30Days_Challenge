/*14 - Minimum Size Subarray Sum
https://leetcode.com/problems/minimum-size-subarray-sum/
*/
#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int arr[],int n,int target)
{
	int ans = INT_MAX, curr_sum = 0, i=0, j=0;
	
	while(i<n)
	{
		
		curr_sum += arr[i];
		cout<<"\ni : "<<i<<"   j : "<<j<<"    curr_sum : "<<curr_sum<<"   ans : "<<ans<<endl;
		
		while(curr_sum>=target)
		{
			ans = min(ans, abs(i-j)+1);//imp step
			curr_sum =  curr_sum - arr[j];
			j++;
		}
		cout<<"i : "<<i<<"   j : "<<j<<"    curr_sum : "<<curr_sum<<"   ans : "<<ans<<endl;
		
		if(curr_sum >= target)
			ans = min(ans, abs(i-j)+1);
		i++;
	}
	
	if(ans==INT_MAX)
		ans= 0;
	return ans;	
}

int main()
{
//	int arr[] = {2,3,1,2,4,3};//2
//	int target = 7;
	
//	int arr[] = {1,4,4};
//	int target = 4;
	
	int arr[]={1,1,1,1,1,1,1,1};
	int target = 11;
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<minSubArrayLen(arr,n,target);
	return 0;
}
