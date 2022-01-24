/*Smallest range in K lists 
https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
https://www.youtube.com/watch?v=bWowdBPkidw
*/

struct K_list{
  int value , index , row;
  K_list(int v, int i, int r)
{
    value=v,index=i,row=r;
}
};

struct Compare
{
    bool operator()(const K_list& p1, const K_list& p2)
    {
        if(p1.value != p2.value)
            return p1.value > p2.value;
        return p1.row < p2.row;    
    }    
};

pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
    //  K_list var;//int value , index , row;
     pair<int,int>ans;
     int low = -1, high = -1, max_value = -1, min_value, range = INT_MAX;
    //  int 
     
     priority_queue<K_list, vector<K_list>, Compare>pq;
     
     for(int i=0;i<k;i++)
     {
         max_value = max(max_value, arr[i][0]);
         pq.push({arr[i][0], 0, i});
     }
     
     
     while(pq.empty()==false)
     {
         K_list var = pq.top();
         pq.pop();
         min_value = var.value;
         if(max_value - min_value < range)
         {
             range = max_value - min_value;
             ans.first = min_value;
             ans.second = max_value;
         }
         if(var.index < n-1)
         {
             max_value = max(max_value, arr[var.row][var.index+1]);
             pq.push({arr[var.row][var.index+1], var.index+1, var.row});
         }
         else
            break;
     }
     return ans;
}
