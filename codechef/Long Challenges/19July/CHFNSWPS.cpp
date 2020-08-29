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
		lli a[n], b[n];
		MPII count_a, count_b;
		multiset<lli> ele_a, ele_b;

		lli m = 1e9 + 10 ;

		for(int i=0;i<n;i++){
			cin >> a[i];
			m = min(m, a[i]);
			count_a[a[i]]++;
		}
		for(int i=0;i<n;i++){
			cin >> b[i];
			m = min(m, b[i]);
			count_b[b[i]]++;
		}

		bool possible = 1;

		for(auto ii = count_a.begin(); ii!=count_a.end(); ii++){
			if( ((ii->second) + count_b[ii->first])%2 == 1)
				possible = 0;
			else{
				if(ii->second == count_b[ii->first]){
					count_a.erase(ii);
					count_b.erase(ii->first);
				}
				else if(ii->second < count_b[ii->first]){
					count_b[ii->first] -= ii->second;
					count_a.erase(ii);
					// cout << "Deleting " << ii->first << " from a "<<endl;
				}
				else if(ii->second > count_b[ii->first]){
					ii->second -= count_b[ii->first];
					count_b.erase(ii->first);

					// cout << "Deleting " << ii->first << " from b "<<endl;
				}
			}
		}

		for(auto ii = count_b.begin(); ii!=count_b.end(); ii++){
			if( ((ii->second) + count_a[ii->first])%2 == 1)
				possible = 0;

		}
		for(auto ii = count_a.begin(); ii!=count_a.end(); ii++){
			for(int i=0;i<ii->second;i++)
				ele_a.insert(ii->first);
		}

		for(auto ii = count_b.begin(); ii!=count_b.end(); ii++){
			for(int i=0;i<ii->second;i++)
				ele_b.insert(ii->first);
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

		lli ans = 0;

		// cout << "Greater a,b : " << greater_a << " " << greater_b << endl;
 
		for(int i=0;i<min(greater_a, greater_b)/2;i++){
			auto ia = ele_a.rbegin();
			auto ib = ele_b.rbegin();
			ele_a.erase( next(ele_a.rbegin()).base());
			ele_b.erase( next(ele_b.rbegin()).base());
			ele_a.erase( next(ele_a.rbegin()).base());
			ele_b.erase( next(ele_b.rbegin()).base());
			ans += m*2;
		}

		// cout << "Ans: " << ans << endl;

		// for(auto ii = ele_a.begin(); ii!=ele_a.end(); ii++){
		// 	cout << *ii << " " ;
		// }

		// cout << endl;
		// cout << "Printing B" << endl;

		// for(auto ii = ele_b.begin(); ii!=ele_b.end(); ii++){
		// 	cout << *ii << " " ;
		// }
		
		auto ib = ele_b.rbegin();
		int size = ele_a.size();
		int i = 0;

		for(auto ia = ele_a.begin(); ia!=ele_a.end(); ia++){
			ans += min(*ia, *ib);
			ib--;
			i++;
			if(i>=(size + 1)/2)
				break;
		}
		cout << ans << endl;
	}
	
	return 0;
}