/*Rotate by 90 degree 
https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/
*/
void rotate(vector<vector<int> >& mat)
{
    int n = mat.size();
    
    //Transpose
    for(int i=0;i<n;i++)
    {
        for(int j=i+1; j<n; j++)
            swap(mat[i][j],mat[j][i]);
    }
    
    int start_row=0,end_row=n-1;
    
    while(start_row<end_row)
    {
        
        for(int i=0;i<n;i++)
            swap(mat[start_row][i], mat[end_row][i]);
        
        start_row++,end_row--;
    }
    
}

