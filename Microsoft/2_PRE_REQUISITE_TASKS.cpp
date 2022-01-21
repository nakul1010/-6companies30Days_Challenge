/*Prerequisite Tasks 
https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/
*/
void add_edge(int u,int v,vector<int>adj[])
{
    adj[u].push_back(v);
}
bool iscycle(int src, vector<bool>& visited, vector<bool>& recstack, vector<int> adj[])
{
    if(visited[src] == false)
    {
        visited[src] = true;
        recstack[src] = true;
        for(auto it : adj[src])
        {
            if(!visited[it] and iscycle(it,visited,recstack,adj))
                return true;
            else if(recstack[it])
                return true;
        }
    }
    recstack[src] = false;
    return false;
}
bool isPossible(int N, vector<pair<int, int> >& pre) 
{
    vector<int>adj[N];
    for(int i=0;i<pre.size();i++)
    {
        
        int u = pre[i].first, v = pre[i].second;
        add_edge(v,u,adj);
//        add_edge(u,v,adj);//doesn't matter
        //adj[u].push_back(v);
    }
    
    vector<bool>visited(N,false);
    vector<bool>recstack(N,false);
    for(int i=0; i<N; i++){
        if(visited[i] == false){
            if(iscycle(i,visited,recstack,adj)){
                return false;
            }
        }
    }
    return true;
}
