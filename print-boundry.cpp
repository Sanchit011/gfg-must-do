public:
    vector<int> ans, l, r, bottom;
    
    void printLeft(Node* root){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        l.push_back(root->data);
        if(root->left != NULL){
            printLeft(root->left);
        }
        else if(root->right != NULL){
            printLeft(root->right);
        }
        return;
    }
    
    void printRight(Node* root){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        r.push_back(root->data);
        if(root->right != NULL){
            printRight(root->right);
        }
        else if(root->left != NULL){
            printRight(root->left);
        }
        return;
    }
    
    void printLeaves(Node* root){
        if(root == NULL) return;
        if(root->left){
            printLeaves(root->left);
        }
        if(root->right){
            printLeaves(root->right);
        }
        if(root->left == NULL && root->right == NULL){
            bottom.push_back(root->data);
        }
        return;
    }
    
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        ans.clear();
        l.clear();
        r.clear();
        bottom.clear();
        if(root == NULL) return ans;
        ans.push_back(root->data);
        printLeft(root->left);
        printRight(root->right);
        printLeaves(root->left);
        printLeaves(root->right);
        reverse(r.begin(), r.end());
        
        for(int i = 0; i<l.size(); i++) ans.push_back(l[i]);
        for(int i = 0; i<bottom.size(); i++) ans.push_back(bottom[i]);
        for(int i = 0; i<r.size(); i++) ans.push_back(r[i]);
        return ans;
    }