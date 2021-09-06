public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        deque<int> dq;
        vector<int> ans(n-k+1, 0);
        for(int i = 0; i<k; i++){
            if(dq.size() == 0) dq.push_back(i);
            else{
                while(dq.size() > 0 && arr[dq.back()] <= arr[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        int index = 0;
        ans[index++] = arr[dq.front()];
        for(int i = k; i<n; i++){
            while(dq.size() > 0 && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            if(dq.size() > 0 && dq.front() + k <= i) dq.pop_front();
            dq.push_back(i);
            ans[index++] = arr[dq.front()];
        }
        
        return ans;
    }