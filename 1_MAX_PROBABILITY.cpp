/*Path with Maximum Probability
https://leetcode.com/problems/path-with-maximum-probability/
*/	
void DFS(bool visit[], int src, vector< pair<int,double> >adj[])
{
    visit[src]=true;
    for(auto it : adj[src])
    {
        if(visit[it.first]==false)    
            DFS(visit,it.first,adj);
    }
}

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
{
    //Create Graph
    vector< pair<int,double> >adj[n+1];
    
    //Add Edges
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        double wt = succProb[i];
        // cout<<"u : "<<u<<"   v : "<<v<<"    wt : "<<wt<<endl;
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }
    
    //Check if path from start --> end exist with DFS
    bool visit[n];
    memset(visit,false,sizeof(visit));
    DFS(visit,start,adj);
    if(visit[end]==false)
        return 0;
    
    //out of here hence path exist 
    //With dijikstra we find min dist but here max dist hence max heap instead of min heap use
    
    vector<double>dist(n,0);
    memset(visit,false,sizeof(visit));
    //imp here double first since sort according to double
    priority_queue< pair<double,int> > pq;
    
    pq.push(make_pair(1.0,start));
    dist[start] = 1.0;
    while(pq.empty()==false)
    {
        int u = pq.top().second;
        visit[u] = true;
        pq.pop();
        for(auto k:adj[u]){
            int v = k.first;
            double wt = k.second;
            
            if(visit[v]==false && dist[v] < dist[u]*wt)
            {
                dist[v] = dist[u]*wt;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    return dist[end];
}
