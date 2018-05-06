#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	int a[1000];

	for(int i=0;i<2*n;i++){
		cin>>a[i];
	}

	sort(a,a+2*n);
	
	if(a[n]>a[n-1]){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
	return 0;
}