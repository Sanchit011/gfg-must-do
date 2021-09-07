public:
    int ans;
    Node* mainRoot;
    int maxSum(Node* root){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->data;
        int left = -10000000;
        int right = -10000000;
        if(root->left != NULL) left = maxSum(root->left);
        if(root->right != NULL) right = maxSum(root->right);
        if(root->left != NULL && root->right != NULL){
            ans = max(ans, left + right + root->data);
        }
        else if(root == mainRoot){
            ans = max(ans, root->data + max(left, right));
        }
        return max(left, right) + root->data ;
    }
    
    int maxPathSum(Node* root)
    {
        // code here
        ans = INT_MIN;
        mainRoot = root;
        int sum = maxSum(root);
        return ans;
    }