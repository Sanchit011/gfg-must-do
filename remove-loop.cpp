public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node* slow = head;
        Node* fast = head;
        while(slow->next && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(slow == fast){
            if(slow == head){
                while(fast->next != slow){
                    fast = fast->next;
                }
                fast->next = NULL;
            }
            else{
                slow = head;
                while(slow->next != fast->next){
                    slow = slow->next;
                    fast = fast->next;
                }
                fast->next = NULL;
            }
        }
        return;
    }