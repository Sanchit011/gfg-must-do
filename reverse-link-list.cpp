public:
    //Function to reverse a linked list.
    
    struct Node* rev(struct Node* head, struct Node* prev){
        if(head->next == NULL){
            head->next = prev;
            return head;  
        } 
        struct Node* ans = rev(head->next, head);
        head->next = prev;
        return ans;
    }
    
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        return rev(head, NULL);
        
    }