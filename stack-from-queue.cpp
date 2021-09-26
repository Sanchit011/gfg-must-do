/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code       
        int n = q1.size();
        if(n == 0) return -1;
        for(int i = 0; i<n-1; i++){
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return x;
}