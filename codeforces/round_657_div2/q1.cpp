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
	int xx = 0;
	while(t--){
		// cout << "xx " << xx++ << endl;
		int n;
		cin >> n;
		string s;
		cin >> s;

		int count_present = 0;
		for(int i=3;i<n-3;i++){
			if(s[i] == 'c')
			{
				if(s[i-3]=='a' && s[i-2]=='b' && s[i-1]=='a' && s[i+1]=='a' && s[i+2]=='b' && s[i+3]=='a')
					count_present++;
			}
		}

		// cout << count_present << endl;

		if(count_present>1){
			cout << "No" << endl;
			continue;
		}

		if(count_present==1){
			cout << "Yes" << endl;
			for(int i=0;i<n;i++){
				if(s[i]=='?')
					s[i] ='z';
			}
			cout << s << endl;
			continue;
		}

		bool ans = 0;
		for(int i=0;i<n-6;i++){
			if( (s[i] == 'a' || s[i] =='?') && (s[i+1] == 'b' || s[i+1] =='?') && (s[i+2] == 'a' || s[i+2] =='?') && (s[i+3] == 'c' || s[i+3] =='?') && (s[i+4] == 'a' || s[i+4] =='?') && (s[i+5] == 'b' || s[i+5] =='?') && (s[i+6] == 'a' || s[i+6] =='?')){
				if(i+10<n){
					if(s[i+7] == 'c' && s[i+8] == 'a' && s[i+9] == 'b' && s[i+10] == 'a'){
						// cout << "in";
						for(int j=i;j<=i+10;j++){
							if(s[j]=='?')
								s[j] = 'z';
						}
						// cout << endl << s <<endl;
						continue;
					}
				}

				ans = 1;
				s[i] = 'a';
				s[i+1] = 'b';
				s[i+2] = 'a';
				s[i+3] = 'c';
				s[i+4] = 'a';
				s[i+5] = 'b';
				s[i+6] = 'a';
				break;
			}
		}

		for(int i=0;i<n;i++){
			if(s[i]=='?')
				s[i] ='z';
		}

		count_present = 0;
		for(int i=3;i<n-3;i++){
			if(s[i] == 'c')
			{
				if(s[i-3]=='a' && s[i-2]=='b' && s[i-1]=='a' && s[i+1]=='a' && s[i+2]=='b' && s[i+3]=='a')
					count_present++;
			}
		}

		// cout << count_present << endl;

		if(count_present>1){
			cout << "No" << endl;
			continue;
		}

		if(ans){
			cout << "Yes" << endl;
			cout << s << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	
	return 0;
}