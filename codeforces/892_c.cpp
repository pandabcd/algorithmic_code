#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int getGCD(int a, int b){
	int A = min(a,b), B = max(a,b);
	if(A==0){
		return B;
	}

	return getGCD(B%A, A);
}

int main() {
	int n;
	cin>>n;
	int a[n], count_zeros = 0, gcd, ans = 100000;

	for(int i=0;i<n;i++){
		cin>>a[i];
		count_zeros += (a[i]==1? 1 : 0) ;
	}

	if(count_zeros){
		cout<<n-count_zeros;
		exit(0);
	}

	for(int i=0;i<n;i++){
		gcd = a[i];
		for(int j=i+1;j<n;j++){
			gcd = getGCD(gcd, a[j]);
			if(gcd==1){
				ans = min(ans, (j - i ) + (n - 1));
			}
		}
	}

	if(ans==100000){
		ans = -1;
	}
	cout<<ans;

	
	return 0;
}