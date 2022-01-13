/*Is Sudoku Valid 
https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/
*/
int isValid(vector<vector<int>> mat)
{
    int n = 9;
    unordered_set<string>s;
    for(int i=0; i<n; i++)
    {   
        for(int j=0; j<n; j++)
        {
            if(mat[i][j]!=0)
            {
                string str = "";
                str = to_string(mat[i][j]) + "found in row" + to_string(i);
                if(s.find(str)!=s.end())
                    return 0;
                
                str = "";
                str = to_string(mat[i][j]) + "found in col" + to_string(j);
                if(s.find(str)!=s.end())
                    return 0;
                
                str = "";
                str = to_string(mat[i][j]) + "found in box" + to_string(i/3) + to_string(j/3);
                if(s.find(str)!=s.end())
                    return 0;
                
                s.insert(to_string(mat[i][j]) + "found in row" + to_string(i));
                s.insert(to_string(mat[i][j]) + "found in col" + to_string(j));
                s.insert(to_string(mat[i][j]) + "found in box" + to_string(i/3) + to_string(j/3));
            }
        }
    }
    return 1;
}
