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


string digits[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int get_profit(string s, int change){
	
	for(int i=9;i>=0;i--){
		int res = change;

		for(int bit=0;bit<7;bit++){
			if(char(s[bit])>char(digits[i][bit]))
				break;
			if(char(s[bit])<char(digits[i][bit]))
				res--;
		}
		if(res==0){
			return i;
		}
	}

	return -1;
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

	int n,k;
	cin>>n>>k;
	string a[n];
	// reverse(a, a+n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int profit[n][8] = {0};
	for(int i=0;i<n;i++){
		for(int j=0;j<8;j++){
			profit[i][j] = get_profit(a[i], j);
			// cout << profit[i][j] <<" " ;
		}
		cout<<endl;
	}

	int dp[n+1][k+1] ={0};
	for(int i=0;i<=n;i++){
			for(int j=0;j<=k;j++){
				dp[i][j] = 0;
			}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			for(int change=0;change<=7; change++)
			{	
				if(j-change>=0){
				
					int local_profit = profit[i-1][change];
					dp[i][j] = max( dp[i-1][j-change] + local_profit, dp[i][j]);
					
				}
			}
		}
	}
	

	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			cout<< dp[i][j] << " ";
		}
		cout <<endl;
	}

	int res = dp[n][k];
	int w = k;
	for (int i = n; i > 0 && res > 0; i--) { 
        if (res == dp[i - 1][w])  
            continue;         
        else { 
  
            // This item is included. 
            cout << i << " " << k << endl; 
              
            // Since this weight is included its  
            // value is deducted 
            res = res - get_profit(a[i], w); 
            w = w - wt[i - 1]; 
        } 
    } 

	cout << dp[n][k] << endl;
	
	return 0;
}