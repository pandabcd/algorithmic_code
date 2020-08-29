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
     
     
    lli gcd(lli a, lli b){ 
        if (a == 0) 
            return b;  
        return gcd(b % a, a);  
     } 
     
    lli lcm(lli a, lli b)  
     {  
        return (a*b)/gcd(a, b);  
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
    		lli a, b, q;
    		cin >> a >> b >> q;
    		lli common = lcm(a,b);
    		lli aa = min(a,b);
    		lli bb = max(a,b);
    		for(int i=0;i<q;i++){
    			lli l,r;
    			cin >> l >> r;
    			lli ans = 0, mn = l, mx = r;

    			// mn = (l + common - 1)/common

    			for(lli j=l;j<=r;j++){
    				mn = j;
    				if( j%aa == (j%bb)%aa )
    					ans++;
    				if(j%common==0){
    					break;
    				}
    			}
    			// cout << ans << endl;
     	
    			for(lli j=mn;j<=r;j+=common){
    				if(j+common>r)
    					break;
    			}

    			// for(lli j=r;j>=mn;j--){
    			// 	mx = j;
    			// 	if( j%aa == (j%bb)%aa && j!=mn)
    			// 		ans++;
    			// }
     			
     			ans += min(r-mx, mx-1);
    			
    			// cout << ans << endl;
    			// cout << mn << " " << mx  << " ";
    			
    			ans += (mx-mn)*((mx-mn)/common) ;
    			// cout << ans << " " <<  (r - l + 1 - ans) << " " << endl;
     
    			cout << (r - l + 1 - ans) << " " ;
    		}
    		cout << endl;
    	}
    	return 0;
    }