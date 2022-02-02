/*1011. Capacity To Ship Packages Within D Days
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/
#include<bits/stdc++.h>
using namespace std;

bool solve(int arr[],int days,int n,int max_value)
{
	int cnt = 0, sum =0;
	for(int i=0;i<n;i++)
	{
		if(arr[i] + sum > max_value)
		{
			sum = arr[i];
			cnt++;
		}
		else
		{
			sum += arr[i];
		}
	}
	if(sum > max_value)
		cnt++;
	cout<<"cnt : "<<cnt<<endl;
	if(cnt >= days)
		return false;
	return true;
}

int shipWithinDays(int wt[],int days,int n)
{
	int start = 0, end = 0, ans = INT_MAX, prev_mid = -1, mid;
	
	for(int i=0;i<n;i++)
	{
		end+=wt[i];
		start = max(start,wt[i]);
	}
	
	while(start<=end)
	{
		mid = (start+end)/2;
		
		if(solve(wt,days,n,mid))
		{
			cout<<"     mid : "<<mid<<"     start : "<<start<<"     end : "<<end<<"   True"<<endl;
			ans = min(ans,mid);
			end = mid - 1;
		}
		else
		{
			cout<<"mid : "<<mid<<"     start : "<<start<<"     end : "<<end<<"   False"<<endl;
			start = mid + 1;
		}
		
		if(mid == prev_mid)
			break;
		prev_mid = mid;
		
	}
	return ans;
}

int main()
{
	int wt[] = {10,50,100,100,50,100,100,100};//160
	int days = 5;
	
//	int wt[] = {1,2,3,4,5,6,7,8,9,10};//15
//	int days = 5;
	
//	int wt[] = {3,2,2,4,1,4};//6
//	int days = 3;
	
//	int wt[] = {1,2,3,1,1};//3
//	int days = 4;
	
	int n = sizeof(wt)/sizeof(wt[0]);
	
	cout<<shipWithinDays(wt,days,n);
	return 0;
}
