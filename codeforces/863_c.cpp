#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int p1[4][4];
int p2[4][4];
bool visited[4][4] = {0} ;
pair<long long, long long> score, state;

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}

// template <typename T,typename U>                                                   
// std::pair<T,U> operator*(const std::pair<T,U> & l,const int x) {   
//     return {l.first*x,l.second*x};                                    
// }

pair<long long, long long> winner(int x, int y){
	if(x==y){
		return make_pair(0,0);
	}
	if( (x==1 and y==3) or (x==3 and y==2) or (x==2 and y==1)){
		return make_pair(1,0);
	}
	return make_pair(0,1);
}

long long findLoopLength(pair<long long, long long> state){
	pair<long long, long long> initial = state;
	long long length = 1;
	state = make_pair(p1[state.first][state.second], p2[state.first][state.second]);
	while(state!=initial){
		state = make_pair(p1[state.first][state.second], p2[state.first][state.second]);
		length++;
	}
	return length;
}

pair<long long, long long> findLoopScore(pair<long long, long long> state){
	pair<long long, long long> initial = state, score;
	score = winner(state.first, state.second);
	state = make_pair(p1[state.first][state.second], p2[state.first][state.second]);
	while(state!=initial){
		score = score + winner(state.first, state.second);
		state = make_pair(p1[state.first][state.second], p2[state.first][state.second]);
	}
	return score;;
}




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

	long long i =0;
	for(i=1;i<=min(k,(long long)12);i++){
		
		if(visited[state.first][state.second]){
			break;
		}
		
		visited [state.first][state.second] = true;
		score = score+winner(state.first, state.second);
		state = make_pair(p1[state.first][state.second], p2[state.first][state.second]);
		
		if(i==k){
			cout<<score.first<<" "<<score.second<<endl;
			exit(0);
		}
		// 
	}

	// cout<<score.first<<" "<<score.second<<endl;


	long long loop_length = findLoopLength(state);
	pair<long long, long long> loop_score = findLoopScore(state);

	long long numberOfLoops = (k-i+1)/loop_length;

	// cout<<loop_length<<" "<<numberOfLoops<<" "<<loop_score.first<<" "<<loop_score.second<<endl;

	score = score + make_pair(numberOfLoops*loop_score.first, numberOfLoops*loop_score.second);

	// cout<<score.first<<" "<<score.second<<endl;

	// cout<<(k-i)%loop_length<<endl;
	for(int j=0;j<(k-i+1)%loop_length;j++){
		
		// visited [state.first][state.second] = true;
		score = score+winner(state.first, state.second);
		state = make_pair(p1[state.first][state.second], p2[state.first][state.second]);
		
	}
	
	

	cout<<score.first<<" "<<score.second;
	
	
	return 0;
}