public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> ans;
    map<int, vector<int>> mp;
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        ans.clear();
        mp.clear();
        queue<pair<Node*, int>> q;
        if(root == NULL) return ans;
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i<n; i++){
                Node* curr = q.front().first;
                int d = q.front().second;
                mp[d].push_back(curr->data);
                q.pop();
                if(curr->left) q.push({curr->left, d-1});
                if(curr->right) q.push({curr->right, d+1});
            }
            
        }
        for(auto m : mp){
            for(auto el : m.second){
                ans.push_back(el);
            }
        }
        return ans;
    }