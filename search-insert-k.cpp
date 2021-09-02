public:
    int searchInsertK(vector<int>arr, int n, int k)
    {
        // code here
        int x = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
        return x;
    }