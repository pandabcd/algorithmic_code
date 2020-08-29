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
		lli a[n], b[n];
		MPII count_a, count_b;
		multiset<lli> ele_a, ele_b;

		lli m = 1e9 + 10 ;

		for(int i=0;i<n;i++){
			cin >> a[i];
			m = min(m, a[i]);
			count_a[a[i]]++;
			ele_a.insert(a[i]);
		}
		for(int i=0;i<n;i++){
			cin >> b[i];
			m = min(m, b[i]);
			count_b[b[i]]++;
			ele_b.insert(b[i]);
		}

		bool possible = 1;

		for(auto ii = count_a.begin(); ii!=count_a.end(); ii++){
			if( (ii->second) % 2  + count_b[ii->first] == 1)
				possible = 0;
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
				greater_a += ii->second;
		}

		for(auto ii = count_b.begin(); ii!=count_b.end(); ii++){
			if( (ii->first) >= 2*m )
				greater_b += ii->second;
		}

		for(auto ii = count_a.begin(); ii!=count_a.end(); ii++){
			cout << ii->first << " " << ii->second << endl;
		}

		cout << "Printing B" << endl;
		for(auto ii = count_b.begin(); ii!=count_b.end(); ii++){
			cout << ii->first << " " << ii->second << endl;
		}

		lli ans = 0;
		while(greater_a > 0 && greater_b >0){
			auto ia = count_a.rbegin();
			auto ib = count_b.rbegin();
			int c_a = ia->second, c_b = ib->second;

			if(c_a == c_b){
				greater_a -= c_b;
				greater_b -= c_b;
				count_a.erase( next(count_a.rbegin()).base());
				count_b.erase( next(count_b.rbegin()).base());
			}

			if(c_a>c_b){
				greater_a -= c_b;
				greater_b -= c_b;
				count_b.erase( next(count_b.rbegin()).base());
				ia->second -= c_b;
			}

			if(c_b>c_a){
				greater_a -= c_a;
				greater_b -= c_a;
				count_a.erase( next(count_a.rbegin()).base());
				ib->second -= c_a;
			}	
			ans += m*2;


		}

		cout << "Done " << endl;

		for(auto ii = count_a.begin(); ii!=count_a.end(); ii++){
			cout << ii->first << " " << ii->second << endl;
		}

		cout << "Printing B" << endl;
		for(auto ii = count_b.begin(); ii!=count_b.end(); ii++){
			cout << ii->first << " " << ii->second << endl;
		}

		// for(auto ia = count_a.begin(), auto ib = count_b.rbegin(); ia!=count_a.end(); ia++, ib--){
		// 	ans += min(ia->first)
		// }
		

	}
	
	return 0;
}