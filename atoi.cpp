public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int n = s.size();
        for(int i = 0; i<n; i++){
            if((i == 0 && s[i] == '-') || (s[i] >= '0' && s[i] <= '9')) continue;
            return -1;
        }
        long long ans = 0;
        long long power = 1;
        for(int i = n-1; i>0; i--){
            long long x = s[i] - '0';
            x = x*power;
            ans += x;
            power = power*10;
        }
        if(s[0] == '-'){
            ans = 0 - ans;
        }
        else{
            ans += (s[0] - '0')*power;
        }
        return ans;
    }