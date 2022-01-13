/*Rotten Oranges - BFS in array
https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1/
https://www.youtube.com/watch?v=pUAPcVlHLKA

Points 
Make it two once found otherwise diuplicates on fresh orange will enter in queue
*/
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
    
bool check(int x,int y,int n,int m,vector<vector<int>>& arr)
{
    if(x<0 || x>=n || y<0 || y>=m || arr[x][y]==0 || arr[x][y]==2)    
        return false;
    return true;
}

int orangesRotting(vector<vector<int>>& arr) 
{
    int n = arr.size(), m = arr[0].size();
    pair<int,int>p;
    queue< pair<int,int> >q;
    int time_ = 0,x,y,x1,y1;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==2)
                q.push(make_pair(i,j));
        }
    }
    
    q.push(make_pair(-1,-1));
    
    while(q.empty()==false)
    {
        p = q.front();
        q.pop();
        x = p.first, y = p.second;
        cout<<"x : "<<x<<"   y : "<<y<<"   time : "<<time_<<endl;
        
        
        if(x==-1 && y==-1)
        {
            q.push(make_pair(-1,-1));
            p = q.front();
            q.pop();
            x = p.first, y = p.second;
            if(x==-1 && y==-1)
                break;
            time_++;
        }
        //imp
        for(int j=0;j<4;j++)
        {
            x1 = x + dx[j];
            y1 = y + dy[j];
            if(check(x1,y1,n,m,arr))
            {
                arr[x1][y1] = 2;
                cout<<"x1 : "<<x1<<"   y1 : "<<y1<<"   time : "<<time_<<endl;
                q.push(make_pair(x1,y1));
            }
        }
    }
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)
                return -1;
        }
    }
    // time_--;
    return time_;
}
int main() {
    // Write C++ code here
    vector<vector<int>>arr {
        {0,1,2},{0,1,2},{2,1,1}
    };
    cout<<orangesRotting(arr);
    return 0;
}
