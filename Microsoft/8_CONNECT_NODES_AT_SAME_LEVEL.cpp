/*Connect Nodes at Same Level 
https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/
*/
void connect(Node *root)
{
    Node*curr=NULL;
    Node*connector = NULL;
    vector<Node*>vec;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    
    while(q.empty()==false)
    {
        curr = q.front();
        q.pop();
        // cout<<"data : "<<curr->data<<endl;
        if(curr==NULL)
        {
            q.push(NULL);
            curr = q.front();
            q.pop();
            if(curr==NULL)
            {
                break;
            }
                
        }
        connector = q.front();
        curr->nextRight = connector;
        
        // if(curr && connector)
        //     cout<<curr->data<<" : "<<connector->data<<endl;
        // else
        //     cout<<curr->data<<" : NULL"<<endl;
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
    
}    

