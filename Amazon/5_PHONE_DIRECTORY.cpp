/*Phone directory 
https://practice.geeksforgeeks.org/problems/phone-directory4628/1/
*/
vector< vector<string> > displayContacts(int n, string arr[], string str)
    {
        int size = str.length();
    	vector< vector<string> >vec;
    	sort(arr,arr+n);
    	
    	for(int i=1;i<=size;i++)
    	{
    	    vector<string>v;
    	    unordered_set<string>s;//because if duplicates enter just one time
    		string find = str.substr(0,i);
    		for(int j=0;j<n;j++)
    		{
    			string curr = arr[j];
    			
    			if(s.find(curr)==s.end() && 
    			curr.length()>=find.length())
    		    {
        			string curr_substr = curr.substr(0,i);
        			if(curr_substr == find)
        			{
        			    v.push_back(curr);
        			    s.insert(curr);
        				// cout<<curr<<" , ";
        			}
    		    }
    			    
    		}
    		if(v.empty()==false)
    		    vec.push_back(v);
    		else
    		{
        		v.push_back("0");
        	    vec.push_back(v);
    		}
    // 		cout<<endl;
    	}	
    	return vec;
    }
