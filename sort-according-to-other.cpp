public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int n, vector<int> A2, int m) 
    {
        //Your code here
        unordered_map<int, int> mp1, mp2;
        for(int i = 0; i<m; i++){
            mp2[A2[i]]++;
        }
        for(int i = 0; i<n; i++){
            if(mp2.find(A1[i]) != mp2.end()) mp1[A1[i]]++;
        }
        vector<int> ans;
        for(int i = 0; i<m; i++){
            int x;
            if(mp1.find(A2[i]) != mp1.end()){
                x = mp1[A2[i]];
                mp1.erase(A2[i]);
            }
            else continue;
            for(int j = 0; j<x; j++) ans.push_back(A2[i]);
        }
        vector<int> v;
        for(int i = 0; i<n; i++){
            if(mp2.find(A1[i]) == mp2.end()) v.push_back(A1[i]);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i<v.size(); i++) ans.push_back(v[i]);
        return ans;
    } 