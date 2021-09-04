public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int, int>> trains;
    	for(int i = 0; i<n; i++){
    	    trains.push_back({arr[i], dep[i]});
    	}
    	int ans = 0;
    	sort(trains.begin(), trains.end());
    	priority_queue<int, vector<int>, greater<int>> q;
    	for(int i = 0; i<n; i++){
    	    int a = trains[i].first;
    	    int d = trains[i].second;
    	    q.push(d);
    	    while(!q.empty() && a > q.top()){
    	        q.pop();
    	    }
    	    if(q.size() > ans) ans = q.size();
    	}
    	return ans;
    }