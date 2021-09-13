public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    long long ans = 0;
	    unordered_map<long long, long long> mp;
	    vector<long long> pre(n, 0);
	    pre[0] = arr[0];
	    for(int i = 1; i<n; i++){
	        pre[i] = pre[i-1] + arr[i];
	    }
	    mp[0] = -1;
	    for(int i = 0; i<n; i++){
	        long long curr = (pre[i]%k + k)%k;
	        if(mp.find(curr) != mp.end()){
	            ans = max(ans, i - mp[curr]);
	        }
	        else{
	            mp[curr] = i;
	        }
	    }
	    return ans;
	}