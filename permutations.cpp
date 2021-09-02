vector<string> ans;
void helper(string s, int l, int r){
    if(l == r){
        ans.push_back(s);
        return;
    }
    for(int i = l; i<=r; i++){
        swap(s[l], s[i]);
        helper(s, l+1, r);
        swap(s[l], s[i]);
    }
    return;
}
vector<string> permutation(string s)
{
    //Your code here
    ans.clear();
    int n = s.size();
    helper(s, 0, n-1);
    sort(ans.begin(), ans.end());
    return ans;
}