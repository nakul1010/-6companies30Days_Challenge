/*
Find the Kth Largest Integer in the Array
https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
*/
//________________________________________________________________________________________________________________________________________________________________________
struct myCmp{
    bool operator()(string a, string b){
        if(a.size() == b.size())
        {
            return a < b;
        }
        
        return a.size() < b.size();
    }    
};

string kthLargestNumber(vector<string>& nums, int k) {
    priority_queue<string, vector<string>, myCmp> pq;
    for(string s : nums)
        pq.push(s);
    
    string ans;
    while(k>0)
    {
        if(k == 1)
        {
            ans = pq.top();
        }
        pq.pop();
        k--;
    }
    return ans;
}
//________________________________________________________________________________________________________________________________________________________________________
class compare
{
  public:
    bool operator()(string& a ,string& b)
    {
        if(a.length() == b.length())
            return (a > b);
        return (a.length() > b.length());
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& A, int k) {
        sort(A.begin(),A.end(),compare());
        return A[k - 1];
    }
};
//________________________________________________________________________________________________________________________________________________________________________
