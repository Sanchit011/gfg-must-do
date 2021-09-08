public:
    vector<int> postOrder(Node* root) {
        // code here
        stack<Node*> st;
        stack<Node*> temp;
        vector<int> ans;
        if(root == NULL) return ans;
        Node* curr;
        st.push(root);
        while(!st.empty()){
            curr = st.top();
            st.pop();
            temp.push(curr);
            if(curr->left) st.push(curr->left);
            if(curr->right) st.push(curr->right);
        }
        while(!temp.empty()){
            curr = temp.top();
            temp.pop();
            ans.push_back(curr->data);
        }
        return ans;
    }