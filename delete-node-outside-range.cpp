public:
    Node* removekeys(Node* root, int l, int r) {
        // code here
        
        if(root == NULL) return root;
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        
        if(root->data < l){
            Node* rc = root->right;
            delete root;
            return rc;
        }
        if(root->data > r){
            Node* lc = root->left;
            delete root;
            return lc;
        }
        return root;
    }