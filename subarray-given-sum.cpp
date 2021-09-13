public:
    int findSubArraySum(int arr[], int n, int k)
    {
        // code here
        vector<int> pre(n, 0);
        pre[0] = arr[0];
        int ans = 0;
        for(int i = 1; i<n; i++){
            pre[i] = arr[i] + pre[i-1];
        }
        unordered_map<int, int> mp;
        mp[0]++;
        for(int i = 0; i<n; i++){
            int curr = pre[i];
            if(mp.find(curr - k) != mp.end()){
                ans += mp[curr - k];
            }
            mp[curr]++;
        }
        return ans;
    }