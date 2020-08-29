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
		int n;
		cin >> n;
		string s;
		cin >> s;

		// vector<int> zeros;
		// vector<int> ones;
		// int start_zero = 0;
		// int start_one = 0;
		SETI zeros;
		SETI ones;

		int count = 1;
		int ans[n] = {0};
		for(int i=0;i<n;i++){
			if(s[i] == '0')
				zeros.insert(i);
			else
				ones.insert(i);
		}


		int neww = 1;
		int state = 0;
		int index = 0;
		while(!zeros.empty() && !ones.empty()){
			auto z = zeros.begin();
			auto o = ones.begin();
			if(neww){
				if(*z < *o){
					ans[*z] = count;
					state = 1;
					neww = 0;
					index = *z;
					zeros.erase(z);

				}
				else{
					ans[*o] = count ;
					state = 0;
					neww = 0;
					index = *o;
					ones.erase(o);
				}
			}
			else{
				if(state==1){
					auto i = upper_bound(ones.begin(), ones.end(), index);
					if(i == ones.end()){
						count++;
						neww = 1;
					}
					else{
						ans[*i] = count;

						index = *i;

						state = !state;
						ones.erase(i);
					}
				
				}
				else{
					// cout << "State 0 " << index << endl ;
					auto i = upper_bound(zeros.begin() , zeros.end() , index);
					if(i == zeros.end()){
						count++;
						neww = 1;
					}
					else{
						// cout << "Found at: " << *i << endl;
						// cout << *zeros.begin() << " " << *zeros.begin() + 1 << endl;
						ans[*i] = count;
						// for(int i= 0;i<n;i++)
						// 	cout << ans[i] << " ";
						// cout << endl;
						// cout << endl;
						index = *i;
						state = !state;
						zeros.erase(i);
					}
					
				}
			}
			// cout << "Size: " << zeros.size() << " " << ones.size() << endl;
			// cout << *z << " " << *o << " " << count << endl;
		}



		
		for(int i= 0;i<n;i++){
			if(ans[i]==0){
				ans[i] = count;
				count ++;
			}
			
		}
		cout << count-1 << endl;
		for(int i=0;i<n;i++){
			cout << ans[i] << " ";
		}
		cout << endl;


	}
	
	return 0;
}