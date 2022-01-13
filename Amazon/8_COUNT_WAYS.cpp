/*Count ways to N'th Stair(Order does not matter) 
https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/
*/
set<string>s;
void Count_Ways(int n,int curr,long long &cnt,int index,string str)
{
    if(curr==n)
    {
        sort(str.begin(),str.end());
        if(s.find(str)==s.end())
        {
            // cout<<str<<endl;
            cnt++;
        }
            
        s.insert(str);
        return;
    }
    if(curr>n || index>2)
        return;
        
    Count_Ways(n,curr,cnt,index+1,str);
    str = str + to_string(index);
    Count_Ways(n,curr+index,cnt,index,str);
}

long long countWays(int m)
{
    return (m/2)+1;

    long long cnt = 0;
    string str = "";
    Count_Ways(m,0,cnt,1,str);
    return cnt;
}
