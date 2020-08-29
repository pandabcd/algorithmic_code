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
// #define int long long int
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

// A utility function to find set of an element i 
// (uses path compression technique) 

// Use auto
int main(int argc, char* argv[]) {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1], pos[n+1]={0};
		for(int i=1;i<=n;i++){
			cin>>a[i];
			pos[a[i]] = i;
		}

		int end = n+1;
		int next_ind = pos[1]+1;
		int start = pos[1];
		int flag = 0;

		// if(pos[1]==n){

		// }

		for(int i=2;i<n;i++){
		
			if(next_ind==end){
				end = start-1;
				next_ind = pos[i+1];
				start = pos[i+1];
				continue;
			}

			if(pos[i]==next_ind){
				next_ind++;
				continue;
			}
			else{
				cout <<"No" << endl;;
				flag = 1;
				break;
			}
		}

		if(not flag){
			cout << "Yes" << endl;
		}
	}
	
	return 0;
}