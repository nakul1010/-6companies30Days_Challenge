/*Word Search 
https://practice.geeksforgeeks.org/problems/word-search/1/
*/

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool DFS(vector<vector<char>>&arr,string &word,int i,int j, int pos)
{
    
    int n = arr.size();//row
    int m = arr[0].size();//col
    
    if(i<0 ||  j<0 || i>=n || j>=m)
        return false;
    
    if(pos>=word.length())
        return true;
    if(arr[i][j] == word[pos])
    {
        char temp = arr[i][j];//instead of visit
        arr[i][j] = '#';
        bool a = DFS(arr,word,i+1,j,pos+1);
        bool b = DFS(arr,word,i-1,j,pos+1);
        bool c = DFS(arr,word,i,j+1,pos+1);
        bool d = DFS(arr,word,i,j-1,pos+1);
        arr[i][j] = temp;
        return a || b || c || d;
    }
    else
        return false;
}

bool isWordExist(vector<vector<char>>& arr, string word) 
{
    int n = arr.size();
    int m = arr[0].size();
    int length = word.length();
    if(length == 0)
        return true;
        
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == word[0])
            {
                if(DFS(arr,word,i,j,0))
                    return true;
            }
        }
    }
    return false;
}
