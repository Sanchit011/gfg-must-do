class Solution {
  public:
    void levelPushUtil(queue<Node *> &q, int &timer){
        int size = q.size();
        timer++;
        while(size--){
            Node *curr = q.front();
            q.pop();
            /*cout<<curr->data<<" ";*/
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    
    bool burnTree(Node *root, int target, int &timer, queue<Node *> &q){
        if(root == NULL)
            return false;
        
        if(root->data == target){
            /*cout<<root->data<<endl;*/
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
            return true;
        }
        
        if(burnTree(root->left, target, timer, q)){
            levelPushUtil(q, timer);
            /*cout<<root->data<<endl;*/
            if(root->right) q.push(root->right);
            return true;
        }
        else if(burnTree(root->right, target, timer, q)){
            levelPushUtil(q, timer);
            /*cout<<root->data<<endl;*/
            if(root->left) q.push(root->left);
            return true;
        }
        
    }
    
    int minTime(Node* root, int target) {
        queue<Node *> q;
        int timer=0;
        
        burnTree(root, target, timer, q);
        while(!q.empty()){
            levelPushUtil(q, timer);
            /*cout<<endl;*/
        }
        return timer;
    }
};