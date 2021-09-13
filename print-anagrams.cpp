public:
    vector<vector<string> > Anagrams(vector<string>& slist) {
        //code here
        int n = slist.size();
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> mp;
        vector<int> ref(26, 0);
        for(int i = 0; i<n; i++){
            vector<int> arr = ref;
            string str = slist[i];
            for(auto c : str){
                arr[c - 'a']++;
            }
            mp[arr].push_back(str);
        }
        for(auto m : mp){
            vector<string> v;
            for(auto str : m.second){
                v.push_back(str);
            }
            ans.push_back(v);
        }
        return ans;
    }