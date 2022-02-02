/*Course Schedule II
https://leetcode.com/problems/course-schedule-ii/
*/

bool isCyclicUtil(int v, bool visited[], bool recStack[], vector<int> adj[]) 
{ 
if(visited[v] == false) 
{
	visited[v] = true; 
	recStack[v] = true; 

	vector<int>::iterator i; 
	for(i = adj[v].begin(); i != adj[v].end(); ++i) 
	{ 
		if(visited[*i]==false && isCyclicUtil(*i, visited, recStack, adj)) 
		{
			return true; 
		}
			
		else if(recStack[*i]) 
		{
			return true; 
		}
	} 
} 

recStack[v] = false;
return false; 
} 

void DFS(int v, bool visited[], stack<int>&s,vector<int>adj[])
{
visited[v]=true;
vector<int> ::iterator ptr;
for (ptr=adj[v].begin(); ptr!=adj[v].end(); ++ptr) 
{
	if(!visited[*ptr])
		DFS(*ptr,visited,s,adj);//remember push *ptr not i
}
s.push(v);//IMP
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
{
vector<int>ans;
vector<int>adj[numCourses+1];

int n = prerequisites.size();

for(int i=0; i<n; i++)
    adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

bool visited[numCourses];
bool recStack[numCourses];
memset(visited,false,sizeof(visited));
memset(recStack,false,sizeof(recStack));

for(int i = 0; i < numCourses; i++) 
{
	if (visited[i]==false && isCyclicUtil(i,visited,recStack,adj))
	{
		return ans; 
	}	
}

memset(visited,false,sizeof(visited));
stack<int>s;
for(int i=0;i<numCourses;i++)
{
	if(!visited[i])
	{
		DFS(i,visited,s,adj);
	}
}

while(!s.empty())
{
    ans.push_back(s.top());
	s.pop();
}
return ans;
}
