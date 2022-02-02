/*
1162. As Far from Land as Possible
https://leetcode.com/problems/as-far-from-land-as-possible/
*/
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int maxDistance(vector<vector<int>>& grid) 
{
    queue<pair<int,int>>q;
    int n = grid.size();
    bool water = false, land = false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==0)
                water=true;
            else
            {
                q.push(make_pair(i,j));
                land=true;
            }
                
        }
    }
    if(land==false || water==false)
        return -1;
    int distance = 0;
    
    //BFS
    while(q.empty()==false)
    {
        int size = q.size();
        distance++;
        while(size--)
        {
            auto[i , j] = q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                
                if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0)
                {
                    grid[x][y]=1;
                    q.push(make_pair(x,y));
                }
            }
        }
    }
    
    return distance-1;
}
