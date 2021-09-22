public:
    void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
       if(head == NULL) return;
       if(head->next == NULL) return;
       Node* temp = head->next;
       Node* odd = head;
       Node* even = head->next;
       while (true)
        {
            if (!odd || !even || !(even->next))
            {
                odd->next = temp;
                return;
            }
            odd->next = even->next;
            odd = even->next;
            if (odd->next == NULL)
            {
                even->next = NULL;
                odd->next = temp;
                return;
            }
            even->next = odd->next;
            even = odd->next;
        }
        return;
    }