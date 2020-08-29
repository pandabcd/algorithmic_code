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
		lli n,m;
		cin >> n >> m;
		// multimap<int, int, greater <int>> top;
		multimap<int, int, greater <int>> topp;
		multimap<int, int, greater <int>> top_n_next;
		// set<int, greater <int>> next;
		lli next_element = 0;

		lli a[m], b[m];
		for(int i=0;i<m;i++){
			cin >> a[i] >> b[i];
			top_n_next.insert(make_pair(a[i] + b[i], i));
			// topp.insert(make_pair(a[i], i));
		}
		cin.ignore();
		lli ans = 0;
		// lli ans = top.begin()->first;
		// int index = top.begin()->second;
		// next.insert(b[index]);
		// next_element = b[index];
		// top.erase(top.begin());
		// n--;




		for(int i=0;i<m;i++){
			// cout << "Hi";
			if(top_n_next.begin() == top_n_next.end()){
				ans += next_element*n;
				break;
			}

			lli top_element = top_n_next.begin()->first;
			int index = top_n_next.begin()->second;
			// cout << "zz" << top_element;
			if(next_element >= top_element){
				ans += n*next_element;
				break;
			}
			// cout << "Hello";
			if(n==1){
				ans += max(next_element, top_element - b[index]);
				break;
			}
			else{
				ans += top_n_next.begin()->first;
				next_element = max(next_element, b[index]);
				top_n_next.erase(top_n_next.begin());
				n-=2;
				cout << "Getting top two of " << i << endl;
			}
		}

		cout << top_n_next.begin()->first << endl;
		cout << (top_n_next.end())->first << endl;
		cout << ans << endl;

		top_n_next.clear();
	}
	
	return 0;
}