/*Maximum Performance of a Team
https://leetcode.com/problems/maximum-performance-of-a-team/
*/
int mod = 1000000007;
int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
{
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++) vec.push_back(make_pair(efficiency[i], speed[i]));
    
    sort(vec.rbegin(), vec.rend());
    
    priority_queue<int, vector<int>, greater<int>>pq;
    long long max_sum = -1, sum=0;
    for(int i=0;i<n;i++)
    {
        pq.push(vec[i].second);
        
        sum += vec[i].second;
        
        if(pq.size()>k)
        {
            sum -= pq.top();
            pq.pop();
        }
        max_sum = max(max_sum, sum*vec[i].first);
        cout<<"sum : "<<sum<<"    overall : "<<sum*vec[i].first<<"     max_sum : "<<max_sum<<endl;
    }
    return max_sum%mod;
}
