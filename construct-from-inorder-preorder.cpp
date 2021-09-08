public:
    int index;
    unordered_map<int, int> hash;
    
    Node* newNode(int data) {
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = data;
        
        return temp;
    }
    
    Node* build(int in[],int pre[], int start, int end){
        if(start > end) return NULL;
        Node* root = newNode(pre[index++]);
        int k = hash[root->data];
        root->left = build(in, pre, start, k-1);
        root->right = build(in, pre, k+1, end);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        index = 0;
        hash.clear();
        for(int i = 0; i<n; i++){
            hash[in[i]] = i;
        }
        Node* root = build(in, pre, 0, n-1);
        return root;
    }