/*Serialize and Deserialize a Binary Tree 
https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
https://www.youtube.com/watch?v=-YbXySKJsX8
ND
Can't do level order for 2*i+1 && 2*i+2 only for complete BT
*/
vector<int> serialize(Node *root) 
{
   //Your code here
   vector<int> v;
   if(root==NULL)
   {
       v.push_back(-1);
       return v;
   }
   serialize(root->left);
  cout<<root->data<<" ";
   serialize(root->right);
}

int i=0;
Node * deSerialize(vector<int> &A)
{
  //Your code here
    if(A.size()==0) 
        return NULL;
    if(A[i]==-1) 
    {
      i++;
      return NULL;
    }
    Node* root=new Node(A[i++]);
    root->left=deSerialize(A);
    root->right=deSerialize(A);
    return root;
}
