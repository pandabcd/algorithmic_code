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
#define len 200010


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
		string s;
		cin >> s;
		int left_one[len];
		int left_two[len];
		int left_three[len];

		left_one[0] = -1 ;
		left_two[0] = -1;
		left_three[0] = -1;

		if(s[0]=='1'){
			left_one[0] = 0;
		}

		if(s[0]=='2'){
			left_two[0] = 0;
		}

		if(s[0]=='3'){
			left_three[0] = 0;
		}

		for(int i=1;i<s.size();i++){
			if(s[i]=='1'){
				left_one[i] = i;
			}
			else{
				left_one[i] = left_one[i-1];
			}

			if(s[i]=='2'){
				left_two[i] = i;
			}else{
				left_two[i] = left_two[i-1];
			}

			if(s[i]=='3'){
				left_three[i] = i;
			}else{
				left_three[i] = left_three[i-1];
			}
		}

		// for(int i=0;i<s.size();i++){
		// 	cout << left_one[i] << " " ;
		// }
		// cout << endl;
		// for(int i=0;i<s.size();i++){
		// 	cout << left_two[i] << " " ;
		// }
		// cout << endl;
		// for(int i=0;i<s.size();i++){
		// 	cout << left_three[i] << " " ;
		// }
		// cout << endl;
		lli ans = INT_MAX;
		for(int i=0;i<s.size();i++){
			if(left_one[i]==-1 || left_two[i] == -1 || left_three[i] ==-1)
				continue;
			// lli end_here = 3*i - (left_one[i] + left_two[i] + left_three[i]);
			lli end_here = max(i-left_one[i], max(i-left_two[i], i-left_three[i]));
			// cout << i << " " << i-left_one[i] << " "<< i-left_two[i] << " "<< i-left_three[i] << " " <<endl;
			// cout << end_here << endl;
			ans = min(ans, end_here);
		}
		if(ans==INT_MAX)
		{
			cout << 0 << endl;
			continue;
		}
		cout << max(ans, (lli)0)+1 << endl;
	}
	
	return 0;
}