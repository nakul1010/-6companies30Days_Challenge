/*Bridge edge in a graph 
https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1#
*/
void remove_edge(vector<int> adj[], int u, int v)
{
    for(int i=0; i<adj[u].size(); i++)
    {
        if(adj[u][i]==v)
        {
            adj[u].erase(adj[u].begin()+i);
            break;
        }
    }
    for(int i=0; i<adj[v].size(); i++)
    {
        if(adj[v][i]==u)
        {
            adj[v].erase(adj[v].begin()+i);
            break;
        }
    }
}

void DFS(vector<int> adj[], bool visit[], int i)
{
    visit[i]=true;
    vector<int>::iterator ptr;
    for(ptr=adj[i].begin(); ptr!=adj[i].end(); ptr++)
    {
        if(visit[*ptr]==false)
            DFS(adj,visit,*ptr);
    }
}

//Function to find if the given edge is a bridge in graph.
int isBridge(int V, vector<int> adj[], int c, int d) 
{
    remove_edge(adj,c,d);
    bool visit[V] = {false};
    memset(visit,false,sizeof(visit));
    
    DFS(adj,visit,c);
    if(visit[d]==false)
        return 1;
    return 0;
    // for(int i=0;i<V;i++)//not for loop
    // {
    //     if(visit[i]==false)
    //         return true;
    // }
    // return false;
}
