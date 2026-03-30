#include <bits/stdc++.h>
using namespace std;

long maxRevenue(vector<int>& vmStock, int m) {
    long ans=0;
	int cap=0;
	priority_queue<int>pq;
	set<int>st;
	for(auto &n:vmStock) {
		pq.push(n);
		st.insert(n);
	}
	

	while(cap<m){
         int maxi=pq.top();
		 int mini=*(st.begin());
		 pq.pop();
		 if(maxi<=0) maxi=mini;
		 ans+=mini+maxi;
		 maxi-=1;
		 pq.push(maxi);
		 st.insert(maxi);
		 cap++;
	}

	return ans;
}

int main() {
    int t,n, m;
    cin >>t;
	while(t--){
	cin>>n;
    vector<int> vmStock(n);
    for (int i = 0; i < n; i++) cin >> vmStock[i];
    cin >> m;
    
    cout << maxRevenue(vmStock, m) << endl;
	}
    return 0;
}