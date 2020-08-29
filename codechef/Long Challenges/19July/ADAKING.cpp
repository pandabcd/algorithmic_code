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

int get_score(int a){
	int ans = 0;
	while(a>0){
		ans += a%10;
		a/=10;
	}
	return ans;
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
		int k;
		cin >> k;
		string board[8][8];
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				board[i][j] = 'X';
			}
		}

		board[0][0] = 'O';
		bool direction = 1;

		int cell_i = 0, cell_j = 1;
		for(int i=0;i<k-1;i++){
			if(direction){
				board[cell_i][cell_j] = '.';
				cell_j ++ ;

				if(cell_j==8){
					direction = !direction;
					cell_i++;
					cell_j--;
				}
			}

			else{
				board[cell_i][cell_j] = '.';
				cell_j--;
				if(cell_j==-1){
					direction = !direction;
					cell_i++;
					cell_j++;
				}
			}
		}

		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cout << board[i][j];
			}
			cout << endl;
		}
		cout<< endl;

	}
	
	return 0;
}