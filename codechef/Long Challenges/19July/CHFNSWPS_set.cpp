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
#define size 100010


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
		lli x, y;
		multiset<lli> a, b;
		int m = 1e9 + 10 ;

		for(int i=0;i<n;i++){
			cin >> x;
			m = min(m, x);
			a.insert(x);
			// count_a[a[i]]++;
		}
		for(int i=0;i<n;i++){
			cin >> y;
			m = min(m, y);
			b.insert(y)
			// count_b[b[i]]++;
		}

		bool possible = 1;
		for(auto ii = count_a.begin(); ii!=count_a.end(); ii++){
			if( (ii->second) % 2  + count_b[ii->first] == 1)
				possible = 0;

			if( ii->second == count_b[ii->first]){
				count_a.erase(ii);
				count_b.erase(ii->first);
			}

		}

		for(auto ii = count_b.begin(); ii!=count_b.end(); ii++){
			if( (ii->second) % 2 + count_a[ii->first] == 1)
				possible = 0;
		}

		if(not possible){
			cout << -1 << endl;
			continue;
		}


		int greater_a = 0, greater_b = 0;
		for(auto ii = count_a.begin(); ii!=count_a.end(); ii++){
			if( (ii->first) >= 2*m )
				greater_a ++;
		}

		for(auto ii = count_b.begin(); ii!=count_b.end(); ii++){
			if( (ii->first) >= 2*m )
				greater_b ++;
		}

		lli ans = 0;
		for(int i=0; i< min(greater_a, greater_b), i++){
			auto ia = count_a.rbegin();
			auto ib = count_b.rbegin();
			count_a.erase( count_a.rbegin());
			count_b.erase( count_b.rbegin());
			ans += m*2;
		}

		for(auto ia = count_a.begin(), auto ib = count_b.rbegin(); ia!=count_a.end(); ia++, ib--){
			ans += min(ia->first)
		}
		

	}
	
	return 0;
}