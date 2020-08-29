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
#define len 100010

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

int maxSubArraySum(lli a[], lli size) 
{ 
    lli max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (lli i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    // return max((lli)0, max_so_far); 
    return  max_so_far; 
} 


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
		lli n;
		cin >> n;
		lli a[n];
		lli initial_sum = 0;
		for(lli i=0;i<n;i++){
			cin >> a[i];
			if(i%2==0)
				initial_sum += a[i];
		}

		lli b[n/2 + 5] = {0};
		lli c[n/2 + 5] = {0};

		for(lli i=1;i<n;i++){
			if(i%2==1){
				b[i/2] = a[i] - a[i-1];
			}
			else{
				c[i/2] = -1*(a[i] - a[i-1]);
			}
		}

		for(int i=0;i<n/2+5;i++){
			cout << b[i] << " " << c[i] <<endl;
		}

		lli x = maxSubArraySum(b, n/2 + 5);
		lli y = maxSubArraySum(c, n/2 + 5);
		cout << initial_sum + max(x,y) << endl;

	}
	return 0;
}