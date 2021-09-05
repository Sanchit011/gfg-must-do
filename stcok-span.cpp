public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans(n, 1);
       stack<int> st;
       for(int i = 0; i<n; i++){
           int x = price[i];
           while(!st.empty() && price[st.top()] <= x){
               st.pop();
           }
           if(!st.empty()){
               ans[i] = i - st.top();
           }
           else{
               ans[i] = i + 1;
           }
           st.push(i);
       }
       return ans;
    }