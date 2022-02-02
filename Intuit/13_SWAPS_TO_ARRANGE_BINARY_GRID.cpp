/*Minimum Swaps to Arrange a Binary Grid
https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
Steps in NB
*/
 int minSwaps(vector<vector<int>>& grid) 
{
    int n = grid.size(), trail_zero_cnt=0;
    int i,j;
    vector<int>vec;
    for(i=0;i<n;i++)
    {
        trail_zero_cnt=0;
        for(j=n-1;j>=0;j--)
        {
            if(grid[i][j]==1)    
                break;
            else
                trail_zero_cnt++;
        }
        vec.push_back(trail_zero_cnt);
    }
    
    int zeros_req=0,swaps=0, element;
    for(i=0; i<n; i++)
    {
        bool done = false;
        zeros_req = n - i - 1;
        for(j=i ;j<n; j++)
        {
            if(vec[j] >= zeros_req)
            {
                swaps += abs(j-i);
                element = vec[j];
                vec.erase(vec.begin()+j);
                vec.insert(vec.begin(), element);
                done = true;
                break;
            }
        }
        if(done == false)
            return -1;
    }
    return swaps;
}
