public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> ans;
       stack<Node*> s1, s2;
       Node* curr1 = root1;
       Node* curr2 = root2;
       while(curr1 != NULL){
           s1.push(curr1);
           curr1 = curr1->left;
       }
       while(curr2 != NULL){
           s2.push(curr2);
           curr2 = curr2->left;
       }
       while(!s1.empty() || !s2.empty()){
           int val1 = INT_MAX;
           int val2 = INT_MAX;
           if(!s1.empty()){
               val1 = s1.top()->data;
           }
           if(!s2.empty()){
               val2 = s2.top()->data;
           }
           if(val1 <= val2){
               ans.push_back(val1);
               curr1 = s1.top();
               s1.pop();
               curr1 = curr1->right;
               while(curr1 != NULL){
                   s1.push(curr1);
                   curr1 = curr1->left;
               }
           }
           else{
               ans.push_back(val2);
               curr2 = s2.top();
               s2.pop();
               curr2 = curr2->right;
               while(curr2 != NULL){
                   s2.push(curr2);
                   curr2 = curr2->left;
               }
           }
       }
       return ans;
    }