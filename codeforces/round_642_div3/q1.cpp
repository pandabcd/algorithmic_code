#include <iostream>
#include<bits/stdc++.h>
#include<utility>

#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl "\n"
#define lli long long int
#define float double
// #define size 100010


using namespace std;

typedef pair<int, int> PII;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef map<string,int> MPSI;
typedef map<string,string> MPSS;
typedef multimap<int,string> MMPSI;
typedef set<int> SETI;
typedef set<string> SETS;
typedef multiset<int> MSETI;


// ll ncr(ll n,ll r,ll m){int ans=1;for (int i = 0; i < r; i++){ans=ans*(n-i)%m*inv[i+1]%m;}return ans;}

// ll inv[maxx];   // returns the modular inverse of number
// void inversify( ll m){inv[1]=1;for(int i=2;i<maxx;i++){inv[i]= m- m/i*inv[m%i]%m;}}

// bool sv[maxx]={0};    // returns 0 if a num is prime
// int sp[maxx]={0};     // gives smallest prime factor of the number
// void Sieve() {for(int i= 2; i< maxx; i+= 2) sv[i]=1,sp[i] = 2;sv[2]=0;for(ll i = 3; i < maxx; i += 2){if (!sv[i]){sp[i] = i;for (ll j = i; (j*i) < maxx; j += 2){if (!sv[j*i])sv[j*i] = true, sp[j*i] = i;}}}}




// Use auto
int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans[n] = {0};

		multimap<float, pair<int, int>> m;
		m.insert( MP(n, MP(0,n-1)));

		int i = 1;
		double dbl_min = 0.0000000000001;
		while(m.begin() != m.end()){
			map<float , pair<int, int>>::iterator ele = m.end();
			ele--;
			float size = ele->first;
			int start = (ele->second).first;
			int end = (ele->second).second;
			
			// cout << "Processing: " <<  start << " " << end << " " << size << endl;
			// if(start==end){
			// 	ans[start] = i;
			// 	i++;
			// 	cout << "Mistake" << endl;
			// }
			// else{
				if((end-start+1)%2==1){
					int mid = (start+end)/2;
					ans[mid] = i;
					if(mid>start){
						float val = float(mid-start) + float(1) - float(start)/float(n) - dbl_min;
						m.insert(MP(val, MP(start, mid-1)));
						// cout << "Addingodd1 " << start << " " << mid-1 << " " << val << endl; 
					}
					if(end>mid){
						float val = float(end - mid) + float(1) - float(mid+1)/float(n) - dbl_min;
						m.insert(MP(val, MP(mid+1, end)));
						// cout << "Addingodd " << mid+1 << " " << end << " " << val << endl;
					}
					
					
				}

				else{
					int mid = (start+end-1)/2;
					ans[mid] = i;
					if(mid>start){
						float val = float(mid-start) + float(1) - float(start)/float(n) - dbl_min;
						m.insert(MP(val, MP(start, mid-1)));
						// cout << "Addingeven1 " << start << " " << mid-1 << " " <<val << endl; 
						// cout << (mid-start) <<endl;
						// cout << float(1) - float(start)/float
					}
					if(end>mid){
						float val = float(end - mid) + float(1) - float(mid+1)/float(n) - dbl_min;
						m.insert(MP(val, MP(mid+1, end)));
						// cout << "Addingeven2 " << mid+1 << " " << end << " " << val << endl;
					}
					
					// 9 5 14 3 10 7 15 1 11 6 16 2 12 4 8 13 

				}
			// }
			
			m.erase(ele);
			// cout << i << " " <<m.size() << endl<<endl;
			i++;
		}

		for(int i=0;i<n;i++){
			cout << ans[i] << " ";
		}
		cout << endl;
		// for(int i=0;i<n;i++){
		// 	cout << i+1 << " ";
		// }
	}

	return 0;
}