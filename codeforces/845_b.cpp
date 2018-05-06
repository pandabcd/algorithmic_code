#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s;
	cin>>s;
	
	int a[3] = {s[0]-'0', s[1]-'0', s[2]-'0' } ;
	int b[3] = {s[3]-'0', s[4]-'0', s[5]-'0' } ;
	
	int sum1 = a[0]+a[1]+a[2];
	int sum2 = b[0]+b[1]+b[2];
	
	sort(a,a+3);
	sort(b,b+3);
	
	if(sum1==sum2){
		cout<<0;
		exit(0);
	}
	
	int ans1 = 0, ans2 = 0;
	int i =0;
	
	int s1 = sum1, s2 = sum2 ;
	
	if(sum1<sum2){
		while(sum1<sum2){
			sum1+= (9-a[i]);
			i++;
			ans1++;
		}
		sum1 = s1, sum2 = s2;
		
		i=0;
		while(sum1<sum2){
			sum2-= b[i];
			i++;
			ans2++;
		}
		
		
		cout<<min(ans1,ans2);
		exit(0);
	}
	
	
	i=0;
	while(sum2<sum1){
		sum2+= (9-b[i]);
		i++;
		ans1++;
	}
	
	sum1 = s1, sum2 = s2;
	i=0;
	while(sum2<sum1){
		sum1-= a[i];
		i++;
		ans2++;
	}
	cout<<min(ans1, ans2);
	
	return 0;
}