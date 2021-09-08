public:
    vector<int> preOrder(Node* root)
    {
        //code here
        stack<Node*> st;
        vector<int> ans;
        Node* curr = root;
        while(curr != NULL || st.empty() == false){
            while(curr != NULL){
                st.push(curr);
                ans.push_back(curr->data);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            curr = curr->right;
        }    
        return ans;
    }