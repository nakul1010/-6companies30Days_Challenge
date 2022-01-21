/*Count Number of SubTrees having given Sum 
https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/
Didn't got the problem 1st 
*/

int solve(Node*root,int &x,int &cnt)
{
    if(root == NULL)
        return 0;
    int left_sum = solve(root->left,x,cnt);
    int right_sum = solve(root->right,x,cnt);
    int total_sum = root->data + left_sum + right_sum;
    // cout<<"root : "<<root->data<<"    total_sum : "<<total_sum<<endl;
    if(total_sum == x)  
    {
        // cout<<"root : "<<root->data<<endl;
        cnt++;
    }
    return total_sum;
}

int countSubtreesWithSumX(Node* root, int x)
{
    int cnt = 0;
    solve(root,x,cnt);
    return cnt;
}
