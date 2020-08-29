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
	while(t--){
		int n,x;
		cin >> n;
		string sa, sb;
		cin >> sa >> sb;
		
		if(sa==sb){
			cout << 0 << endl;
			continue;
		}

		vector<int> a, b;
		for(int i=0;i<n;i++){
			a.push_back(sa[i] - '0');
			// cout << a[i] ;
		}

		for(int i=0;i<n;i++){
			b.push_back(sb[i] - '0');
		}



		int end = n-1;
		vector<int> ans;
		// cout << "hi" << endl;
		// reverse(a.begin(), a.begin()+2);

		
		int iterations = 0;
		while(end>=0){
			iterations++;
			if(iterations>10)
				break;
			if(end == 0){
				if(a[0]!=b[0])
					ans.push_back(1);
				break;
			}
			else if(a[0]==b[end]){
				ans.push_back(1);
				a[0] = 1 - a[0];
			}
			else{
				ans.push_back(end+1);
				reverse(a.begin(), a.begin()+end+1);
				for(int i=0;i<=end;i++)
					a[i] = 1 - a[i];
				while(end >0 && b[end] == a[end]){
					end--;
				}
			}
			
			// cout <<"a" << endl;
			// for(int i=0;i<a.size();i++)
			// 	cout << a[i];
			// cout << endl;
			// for(int i=0;i<n;i++)
			// 	cout << b[i];
			// cout << endl << end << " Ans: " << ans.size() << endl;
			
		}
		
		cout << ans.size() << " ";
		for(int i=0;i<ans.size();i++)
			cout << ans[i] << " " ;
		cout << endl;
	}
	
	return 0;
}