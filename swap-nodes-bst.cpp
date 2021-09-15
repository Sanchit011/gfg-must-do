public:
    
    struct Node* prev;
    struct Node* n1;
    struct Node* n2;
    struct Node* n3;
    int x;
    
    void preorder (Node* root){
        if(root == NULL) return;
        preorder(root->left);
        int curr = root->data;
        if(curr < x){
            if(n1 == NULL){
                n1 = prev;
                n2 = root;   
            }
            else{
                n3 = root;
            }
        }
        prev = root;
        x = curr;
        preorder(root->right);
        return;
    }
    
    void correctBST( struct Node* root )
    {
        // add code here.
        n1 = NULL;
        n2 = NULL;
        n3 = NULL;
        x = INT_MIN;
        prev = NULL;
        preorder(root);
        if(n3 == NULL){
            swap(n1->data, n2->data);
        }
        else{
            swap(n1->data, n3->data);
        }
        return;
    }