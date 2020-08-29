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
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		int peaks[n] = {0};
		bool is_peak[n] = {0};

		for(int i=1;i<n-1;i++){
			peaks[i] = peaks[i-1];
			if(a[i]>a[i-1] && a[i]>a[i+1]){
				peaks[i]++; 
				is_peak[i] = 1;
			}
		}

		peaks[n-1] = peaks[n-2];

		// for(int i=0;i<n;i++){
		// 	cout << peaks[i] << " ";
		// }
		// cout<<endl;


		int max_parts = 0, left_border = 0;;
		for(int i=0;i<n;i++){
			if(i+k-1>=n)
				break;
			int subtractor = 0;
			if(is_peak[i])
				subtractor++;
			if(is_peak[i+k-1])
				subtractor++;
			// cout << peaks[i+k-1] - peaks[i] -subtractor <<endl;
			if(peaks[i+k-1] - peaks[i] -subtractor > max_parts){
				max_parts = peaks[i+k-1] - peaks[i] -subtractor;
				left_border = i;
			}
		}

		// if(max_parts==1){
		// 	cout<<1<<" " << 1 <<endl;
		// }
		cout<< max_parts+1 << " " << left_border+1 << endl;

	}
	
	return 0;
}