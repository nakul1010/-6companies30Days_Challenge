/*Alien Dictionary 
https://practice.geeksforgeeks.org/problems/alien-dictionary/1/
*/
string ans = "";

void push_in_graph(string str1,string str2,int n, vector<int>adj[])
{
    for(int i=0;i<n;i++)
    {
        if(str1[i]!=str2[i])
        {
            adj[str1[i]-'a'].push_back(str2[i]-'a');//not 0
            // adj[str2[i]].push_back(str1[i]);//undirected graph
            return;
        }
    }
}

void Topo_Sort(int i,bool visit[],vector<int>adj[],stack<int>&s)
{
    visit[i]=true;
    vector<int>::iterator itr;
    for(itr=adj[i].begin(); itr!=adj[i].end(); itr++)
    {
        if(visit[*itr]==false)
        {
            Topo_Sort(*itr,visit,adj,s);
        }
    }
    s.push(i);
}

string findOrder(string dict[], int n, int k) 
{
    vector<int>adj[k+1];
    
    
    for(int i=0;i<n-1;i++)
    {
        string str1 = dict[i];
        string str2 = dict[i+1];
        int n = min(str1.length(),str2.length());
        push_in_graph(str1,str2,n,adj);
    }
    
    
    //Topological Sort
    bool visit[k] = {false};
    stack<int>s;
    for(int i=0;i<k;i++)
    {
        if(visit[i]==false)
        {
            Topo_Sort(i,visit,adj,s);
        }
    }
    
    while(s.empty()==false)
    {
        char ch = char(s.top() + 'a');
        ans = ans + ch;
        s.pop();
    }
    return ans;
}
