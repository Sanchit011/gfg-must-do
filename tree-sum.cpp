public:
    bool ans;
    int sum(Node* root){
        if(root == NULL) return 0;
        int left = sum(root->left);
        int right = sum(root->right);
        if(root->left || root->right){
            if(root->data != left + right) ans = false;
        }
        return root->data + left + right;
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         ans = true;
         int x = sum(root);
         return ans;
    }