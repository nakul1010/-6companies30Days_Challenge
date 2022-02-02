/*Number of Provinces
https://leetcode.com/problems/number-of-provinces/
*/
//______________________________________________________________________________________________________________________________________________________________
void dfs(int start, bool visit[],int n, vector<vector<int>>& adj)
{
	visit[start] = true;
    for (int i = 0; i < adj[start].size(); i++) 
	{
        if (adj[start][i] == 1 && (!visit[i]))
            dfs(i, visit,n,adj);
    }
}
//______________________________________________________________________________________________________________________________________________________________
int findCircleNum(vector<vector<int>>& vec) 
{
    int n = vec.size(), components = 0;
    bool visit[n];
    memset(visit, false, sizeof(visit));
    
    for(int i=0; i<n; i++)
    {
        if(visit[i]==false)
        {
            dfs(i, visit, n,vec);
            components++;
        }
    }
    return components;
}
//______________________________________________________________________________________________________________________________________________________________
