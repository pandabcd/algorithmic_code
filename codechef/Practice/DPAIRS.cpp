#include <iostream>
#include<bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

// typedef pair<int, int> PII;
// typedef vector<int> VI;
// typedef vector<string> VS;
// typedef vector<PII> VII;
// typedef vector<VI> VVI;
// typedef map<int,int> MPII;
// typedef set<int> SETI;
// typedef multiset<int> MSETI;

using namespace std;


// Use auto
int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin>>n>>m;

	int a[n], b[m];
	int a_max = INT_MIN, b_min = INT_MAX, a_max_ind = -1, b_min_ind = -1;

	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>a_max){
			a_max = a[i];
			a_max_ind = i;
		}
	}

	for(int i=0;i<m;i++){
		cin>>b[i];
		if(b[i]<b_min){
			b_min = b[i];
			b_min_ind = i;
		}
	}

	for(int i=0;i<m;i++){
		cout<<a_max_ind << " " << i << "\n";
	}

	for(int i=0;i<n;i++){
		if(i!=a_max_ind)
		cout << i << " " <<  b_min_ind << "\n";
	}

	return 0;
}