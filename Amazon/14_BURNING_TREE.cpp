/*Burning Tree
https://practice.geeksforgeeks.org/problems/burning-tree/1/
*/

    void Make_Parent_Pts_Through_Level_Order(Node*root,unordered_map<Node*,Node*>&parent,Node*&target_ptr,int t)
    {
        queue<Node*>q;
        q.push(root);
        
        while(q.empty()==false)
        {
            Node*curr = q.front();
            q.pop();
            if(curr->data == t)
                target_ptr = curr;
            if(curr->left)
            {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    int minTime(Node* root, int target) 
    {
        Node*target_ptr=NULL;
        unordered_map<Node*,Node*>parent;
        
        Make_Parent_Pts_Through_Level_Order(root,parent,target_ptr,target);
        
        int time_ = 0;
        Node*dump = new Node(-1);
        queue<Node*>q;
        q.push(target_ptr);
        q.push(dump);
        unordered_set<Node*>s;
        s.insert(target_ptr);
        // cout<<target_ptr->data<<endl;
        while(q.empty()==false)
        {
            Node*curr = q.front();
            q.pop();
            
            if(curr==dump)
            {
                q.push(dump);
                curr = q.front();
                q.pop();
                if(curr == dump)
                    break;
                time_++;
            }
            // cout<<curr->data<<endl;
            if(curr->left && s.find(curr->left)==s.end())
            {
                q.push(curr->left);
                s.insert(curr->left);
            }
            if(curr->right && s.find(curr->right)==s.end())
            {
                q.push(curr->right);
                s.insert(curr->right);
            }   
            if(parent.find(curr)!=parent.end() && s.find(parent[curr])==s.end())
            {
                q.push(parent[curr]);
                s.insert(parent[curr]);
            }
        }
        // cout<<endl;
        return time_;
    }
