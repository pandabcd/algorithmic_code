#include <iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}

template <typename T,typename U>                                                   
std::pair<T,U> operator*(const std::pair<T,U> & l,const int x) {   
    return {l.first*x,l.second*x};                                    
}

pair<int,int> winner(int x, int y){
	if(x==y){
		return make_pair(0,0);
	}
	if(x==1 and y==3 or x>y){
		return make_pair(1,0);
	}
	return make_pair(0,1);
}

int p1[4][4];
int p2[4][4];
bool visited[4][4] = {0} ;
pair<long long, long long> score, state;

int main() {
	long long k,a,b ;
	cin>>k>>a>>b;

	

	for(int i =1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin>>p1[i][j] ;
		}
	}

	for(int i =1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin>>p2[i][j] ;
		}
	}

	
	state = make_pair(a,b);
	score = make_pair(0,0);

	int i =0;
	for(i=1;i<12;i++){
		
		if(visited[state.first][state.second]){
			break;
		}
		
		visited [state.first][state.second] = true;
		score = score+winner(state.first, state.second);
		state = make_pair(p1[state.first][state.second], p2[state.first][state.second]);
		
		// cout<<state.first<<" "<<state.second<<endl;
	}

	pair<long long, long long> loop_score = make_pair(0,0);

	loop_length = findLoopLength(state);
	loop_score = findLoopScore(state);


	score += (k-i)/loop_length* loop_score;

	for(i=1;i<k%i;i++){
		
		// visited [state.first][state.second] = true;
		score = score+winner(state.first, state.second);
		state = make_pair(p1[state.first][state.second], p2[state.first][state.second]);

	cout<<i<<endl;
	}
	
	
	return 0;
}