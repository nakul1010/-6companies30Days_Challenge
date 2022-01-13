/*
Maximum of all subarrays of size k 
Similar to IPL
https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
*/
vector <int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int>ans;
	deque<int>q;//push index not elements
	for(int i=0;i<k;i++)
	{
		while(q.empty()==false && arr[i] >= arr[q.back()])
		{
			q.pop_back();
		}
		q.push_back(i);
	}
// 	cout<<arr[q.front()]<<"  ";//at any cost only one element therefore used while above
    ans.push_back(arr[q.front()]);
		
	for(int i=k;i<n;i++)
	{
		if(q.front() == i-k)
			q.pop_front();
		
		while(q.empty()==false && arr[i]>=arr[q.back()])
			q.pop_back();
		q.push_back(i);
		ans.push_back(arr[q.front()]);
// 		cout<<arr[q.front()]<<"  ";
	}
    return ans;
}
