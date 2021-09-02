public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        long n = v.size();
        long low = lower_bound(v.begin(), v.end(), x) - v.begin();
        long hi = upper_bound(v.begin(), v.end(), x) - v.begin() -1;
        if(low == n || v[low] != x){
            return {-1, -1};
        }
        return {low, hi};
    }