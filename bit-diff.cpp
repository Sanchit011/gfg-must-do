int countBits(int n, long long int arr[])
    {
        // code here
        long long int ans = 0;
        long long int mod = 1000000007;
        for (int i = 0; i < 32; i++) {
            long long int count = 0;
            for (int j = 0; j < n; j++)
                if ((arr[j] & (1 << i)))
                    count++;
            ans += ((count * (n - count) * 2))%mod;
            ans = ans%mod;
        }
    
        return ans;
    }