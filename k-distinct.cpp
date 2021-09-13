public:
    int longestKSubstr(string s, int k) {
        // your code here
        int n = s.size();
        vector<int> arr(26, 0);
        int count = 0;
        int ans = -1;
        int start = 0;
        int end = 0;
        while(end < n && start < n){
            if(count <= k){
                if(count == k){
                    ans = max(ans, end - start);
                }
                if(arr[s[end] - 'a'] == 0){
                    count++;
                }
                arr[s[end] - 'a']++;
                end++;
            }
            else {
                if(arr[s[start] - 'a'] == 1){
                    count--;
                }
                arr[s[start] - 'a']--;
                start++;
            }
        }
        if(count == k){
            ans = max(ans, end - start);
        }
        return ans;
    }