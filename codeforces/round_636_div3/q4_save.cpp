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

#define MAX 200010*2

// ll ncr(ll n,ll r,ll m){int ans=1;for (int i = 0; i < r; i++){ans=ans*(n-i)%m*inv[i+1]%m;}return ans;}

// ll inv[maxx];   // returns the modular inverse of number
// void inversify( ll m){inv[1]=1;for(int i=2;i<maxx;i++){inv[i]= m- m/i*inv[m%i]%m;}}

// bool sv[maxx]={0};    // returns 0 if a num is prime
// int sp[maxx]={0};     // gives smallest prime factor of the number
// void Sieve() {for(int i= 2; i< maxx; i+= 2) sv[i]=1,sp[i] = 2;sv[2]=0;for(ll i = 3; i < maxx; i += 2){if (!sv[i]){sp[i] = i;for (ll j = i; (j*i) < maxx; j += 2){if (!sv[j*i])sv[j*i] = true, sp[j*i] = i;}}}}
int n;

int tree[MAX] = {0};  // To store segment tree 
int lazy[MAX] = {0};  // To store pending updates 
  
/*  si -> index of current node in segment tree 
    ss and se -> Starting and ending indexes of elements for 
                 which current nodes stores sum. 
    us and ue -> starting and ending indexes of update query 
    diff -> which we need to add in the range us to ue */
void updateRangeUtil(int si, int ss, int se, int us, 
                     int ue, int diff) 
{ 
    // If lazy value is non-zero for current node of segment 
    // tree, then there are some pending updates. So we need 
    // to make sure that the pending updates are done before 
    // making new updates. Because this value may be used by 
    // parent after recursive calls (See last line of this 
    // function) 
    if (lazy[si] != 0) 
    { 
        // Make pending updates using value stored in lazy 
        // nodes 
        tree[si] += (se-ss+1)*lazy[si]; 
  
        // checking if it is not leaf node because if 
        // it is leaf node then we cannot go further 
        if (ss != se) 
        { 
            // We can postpone updating children we don't 
            // need their new values now. 
            // Since we are not yet updating children of si, 
            // we need to set lazy flags for the children 
            lazy[si*2 + 1]   += lazy[si]; 
            lazy[si*2 + 2]   += lazy[si]; 
        } 
  
        // Set the lazy value for current node as 0 as it 
        // has been updated 
        lazy[si] = 0; 
    } 
  
    // out of range 
    if (ss>se || ss>ue || se<us) 
        return ; 
  
    // Current segment is fully in range 
    if (ss>=us && se<=ue) 
    { 
        // Add the difference to current node 
        tree[si] += (se-ss+1)*diff; 
  
        // same logic for checking leaf node or not 
        if (ss != se) 
        { 
            // This is where we store values in lazy nodes, 
            // rather than updating the segment tree itelf 
            // Since we don't need these updated values now 
            // we postpone updates by storing values in lazy[] 
            lazy[si*2 + 1]   += diff; 
            lazy[si*2 + 2]   += diff; 
        } 
        return; 
    } 
  
    // If not completely in rang, but overlaps, recur for 
    // children, 
    int mid = (ss+se)/2; 
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 
  
    // And use the result of children calls to update this 
    // node 
    tree[si] = tree[si*2+1] + tree[si*2+2]; 
} 
  
// Function to update a range of values in segment 
// tree 
/*  us and eu -> starting and ending indexes of update query 
    ue  -> ending index of update query 
    diff -> which we need to add in the range us to ue */
void updateRange(int n, int us, int ue, int diff) 
{ 
   updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 
  
  
/*  A recursive function to get the sum of values in given 
    range of the array. The following are parameters for 
    this function. 
    si --> Index of current node in the segment tree. 
           Initially 0 is passed as root is always at' 
           index 0 
    ss & se  --> Starting and ending indexes of the 
                 segment represented by current node, 
                 i.e., tree[si] 
    qs & qe  --> Starting and ending indexes of query 
                 range */
int getSumUtil(int ss, int se, int qs, int qe, int si) 
{ 
    // If lazy flag is set for current node of segment tree, 
    // then there are some pending updates. So we need to 
    // make sure that the pending updates are done before 
    // processing the sub sum query 
    if (lazy[si] != 0) 
    { 
        // Make pending updates to this node. Note that this 
        // node represents sum of elements in arr[ss..se] and 
        // all these elements must be increased by lazy[si] 
        tree[si] += (se-ss+1)*lazy[si]; 
  
        // checking if it is not leaf node because if 
        // it is leaf node then we cannot go further 
        if (ss != se) 
        { 
            // Since we are not yet updating children os si, 
            // we need to set lazy values for the children 
            lazy[si*2+1] += lazy[si]; 
            lazy[si*2+2] += lazy[si]; 
        } 
  
        // unset the lazy value for current node as it has 
        // been updated 
        lazy[si] = 0; 
    } 
  
    // Out of range 
    if (ss>se || ss>qe || se<qs) 
        return 0; 
  
    // At this point we are sure that pending lazy updates 
    // are done for current node. So we can return value  
    // (same as it was for query in our previous post) 
  
    // If this segment lies in range 
    if (ss>=qs && se<=qe) 
        return tree[si]; 
  
    // If a part of this segment overlaps with the given 
    // range 
    int mid = (ss + se)/2; 
    return getSumUtil(ss, mid, qs, qe, 2*si+1) + 
           getSumUtil(mid+1, se, qs, qe, 2*si+2); 
} 
  
// Return sum of elements in range from index qs (query 
// start) to qe (query end).  It mainly uses getSumUtil() 
int getSum(int n, int qs, int qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return getSumUtil(0, n-1, qs, qe, 0); 
} 
  
// A recursive function that constructs Segment Tree for 
//  array[ss..se]. si is index of current node in segment 
// tree st. 
void constructSTUtil(int arr[], int ss, int se, int si) 
{ 
    // out of range as ss can never be greater than se 
    if (ss > se) 
        return ; 
  
    // If there is one element in array, store it in 
    // current node of segment tree and return 
    if (ss == se) 
    { 
        tree[si] = arr[ss]; 
        return; 
    } 
  
    // If there are more than one elements, then recur 
    // for left and right subtrees and store the sum 
    // of values in this node 
    int mid = (ss + se)/2; 
    constructSTUtil(arr, ss, mid, si*2+1); 
    constructSTUtil(arr, mid+1, se, si*2+2); 
  
    tree[si] = tree[si*2 + 1] + tree[si*2 + 2]; 
} 
  
/* Function to construct segment tree from given array. 
   This function allocates memory for segment tree and 
   calls constructSTUtil() to fill the allocated memory */
void constructST(int arr[], int n) 
{ 
    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n-1, 0); 
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
	cin>>t;
	while(t--){
		int  k;
		cin>>n>>k;
		int a[n];
		int max_num = INT_MIN;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		constructST(a, n);

		MPII sum_counter;
		for(int i=0;i<n/2;i++){
			int sum = a[i] + a[n-i-1];
			

			if(sum_counter.find(sum) == sum_counter.end()){
				sum_counter[sum] = 1;
			}
			else{
				sum_counter[sum] ++;
			}
		}

		int max_sum_freq = 0, max_sum = 0;

		for(auto it: sum_counter){
			if(it.second>max_sum_freq){
				max_sum = it.first;
				max_sum_freq = it.second;
			}
			cout<< it.first<<" " <<it.second<<endl;;
		}

		cout<<max_sum << " "  << max_sum_freq<<endl;
		int ans = 0;
		for(int i=0;i<n/2;i++){
			int sum = a[i] + a[n-i-1];
			int min_ele = min(a[i], a[n-i-1]);
			int max_ele = max(a[i], a[n-i-1]);
			if(sum==max_sum){
				continue;
			}
			if( (max_sum > k + max_ele) || (max_sum < (min_ele+1))){
				ans+=2;
			}
			else{
				ans+=1;
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}