public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int> ref(26, 0);
        vector<int> arr(26, 0);
        int n = s.size();
        int m = p.size();
        if(m > n) return "-1";
        for(int i = 0; i<m; i++){
            ref[p[i] - 'a']++;
        }
        int count = 0;
        int start = 0;
        int end = 0;
        int ans = -1;
        int len = INT_MAX;
        bool flag = false;
        while(start<n && end<n){
            while(end < n && count < m){
                int x = s[end] - 'a';
                if(ref[x] > arr[x]){
                    count++;
                }
                arr[x]++;
                end++;
            }
            if(count == m) flag = true;
            while(count == m){
                int x = s[start] - 'a';
                arr[x]--;
                start++;
                if(arr[x] < ref[x]){
                    count--;
                    break;
                }
            }
            if(flag && end - start + 1 < len){
                ans = start - 1;
                len = end - start + 1;
            }
            flag = false;
        }
        if(ans == -1) return "-1";
        string str = s.substr(ans, len);
        return str;
    }