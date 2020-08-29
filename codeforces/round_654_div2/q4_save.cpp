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
		int n,k;
		cin >> n >> k;
		int magicSquare[n][n] ;
		 memset(magicSquare, 0, sizeof(magicSquare));

		int i = n/2;  
	    int j = n-1;  
	  
	    // One by one put all values in magic square  
	    for (int num = 1; num <= k; )  
	    {  
	        if (i == -1 && j == n) //3rd condition  
	        {  
	            j = n-2;  
	            i = 0;  
	        }  
	        else
	        {  
	            // 1st condition helper if next number  
	            // goes to out of square's right side  
	            if (j == n)  
	                j = 0;  
	  
	            // 1st condition helper if next number  
	            // is goes to out of square's upper side  
	            if (i < 0)  
	                i = n - 1;  
	        }  
	        if (magicSquare[i][j]) //2nd condition  
	        {  
	            j -= 2;  
	            i++;  
	            continue;  
	        }  
	        else{
	        	cout << "Setting" << i << " " << j << endl;
	            magicSquare[i][j] = num++; //set number  
	        }
	  
	        j++; i--; //1st condition  
	    }  
	
		int min_row_sum = 1e9;
		int max_row_sum = 0;
		for(int i=0;i<n;i++){
			int row_sum = 0;
			for(int j=0;j<n;j++){
				row_sum += magicSquare[i][j];
			}
			min_row_sum = min(min_row_sum, row_sum);
			max_row_sum = max(max_row_sum, row_sum);
		}


		int min_col_sum = 1e9;
		int max_col_sum = 0;
		
		for(int j=0;j<n;j++){
			int col_sum = 0;
			for(int i=0;i<n;i++){
				col_sum += magicSquare[i][j];
			}
			min_col_sum = min(min_col_sum, col_sum);
			max_col_sum = max(max_col_sum, col_sum);
		}

		cout << (max_col_sum - min_col_sum)*(max_col_sum - min_col_sum) + (max_row_sum - min_row_sum)*(max_row_sum - min_row_sum) << endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << magicSquare[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}