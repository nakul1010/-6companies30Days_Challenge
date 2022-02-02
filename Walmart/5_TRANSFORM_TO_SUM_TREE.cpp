/*Transform to Sum Tree 
https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/
*/

int Sum_Tree(Node*curr)
{
    if(curr==NULL)  
        return 0;
    int left_sum = Sum_Tree(curr->left);
    int right_sum = Sum_Tree(curr->right);
    int curr_val = curr->data;
    curr->data = left_sum + right_sum;
    return curr_val + curr->data;
    
}

void toSumTree(Node *curr)
{
    int x = Sum_Tree(curr);
}
