public:
    int longestUniqueSubsttr(string s){
        //code
        int n = s.size();
        vector<int> arr(26, 0);
        int start = 0;
        int end = 0;
        int ans = 0;
        while(start < n && end < n){
            int x = s[end] - 'a';
            if(arr[x] == 0){
                arr[x]++;
                end++;
                ans = max(ans, end - start);
            }
            else{
                arr[s[start] - 'a']--;
                start++;
            }
        }
        return ans;
    }