public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       queue<Node*> q;
       if(root == NULL) return;
       q.push(root);
       while(!q.empty()){
           int n = q.size();
           for(int i = 0; i<n-1; i++){
               Node* curr = q.front();
               q.pop();
               Node* next = q.front();
               curr->nextRight = next;
               if(curr->left != NULL) q.push(curr->left);
               if(curr->right != NULL) q.push(curr->right);
           }
           Node* last = q.front();
           q.pop();
           if(last->left != NULL) q.push(last->left);
           if(last->right != NULL) q.push(last->right);
       }
    }    