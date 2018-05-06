#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;

	int a[n+1], lastRoomVisitTime[20001] = {-1}, timeToRoom[20001] = {-1}, ans = 1, room = 2;
	lastRoomVisitTime[1] = 0;
	timeToRoom[0] = 1;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		cout<<timeToRoom[0]<<" "<<timeToRoom[1]<<endl;
		cout<<lastRoomVisitTime[0]<<" "<<lastRoomVisitTime[1]<<endl<<endl;
		if(timeToRoom[a[i]]==-1){
			ans++;
			timeToRoom[a[i]] = room;
			lastRoomVisitTime[room] = a[i];
			room++;
		}
		else{
			lastRoomVisitTime[timeToRoom[a[i]]] = i;
			timeToRoom[a[i]] = -1;
			

		}


	}

	cout<<ans;
	
	
	return 0;
}