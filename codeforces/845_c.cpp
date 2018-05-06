#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class showTime{
	
	
	public:
	int start, end ;
	showTime(){};
	showTime(int l,int r){
		start = l;
		end = r;
	};
	
	bool operator() (const showTime t1, const showTime t2) {
		return t1.start<t2.start ;
	}
};

bool comparator( showTime t1, showTime t2){
	return t1.start<t2.start;
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	
	showTime arr[n] ;
	
	int l,r;
	
	for(int i=0;i<n;i++){
		cin>>l>>r ;
		arr[i].start = l, arr[i].end = r;
		// cout<<&st<<endl;
	}
	
	sort(arr, arr+n, comparator) ;
	
	// bool tv1 = true, tv2 = true ;
	int tv1 = 0, tv2 = -1 ;
	
	for(int i=1;i<n;i++){
	      if(arr[tv1].end<arr[i].start){
	      	tv1 = i ;
	      }
	      else if (tv2==-1 or arr[tv2].end<arr[i].start){
	      	tv2 = i ;
	      }
	      else{
	      	cout<<"NO" ;
	      	exit(0);
	      }
	}
	
	cout<<"YES" ;
	return 0;
}