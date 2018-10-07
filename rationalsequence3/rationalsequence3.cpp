#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int log2(int n){
	int result = 0;
	while(n){
		result++;
		n >>= 1;
	}
	return result;
}

pii get_node(int row, int column){
	if(row == 0) //root
		return make_pair(1,1);
	else{
		pii parent = get_node(row - 1, column / 2);
		if(column % 2 == 0) //left child
			return make_pair(parent.first, parent.first + parent.second);
		else //right child
			return make_pair(parent.first + parent.second, parent.second);
	}
}

int main(){
	int P,K,N;
	cin >> P;
	for(int i = 0; i < P; i++){
		cin >> K >> N;
		int row = log2(N) - 1;
		//cout << row << "," << N - (1 << row) << endl;
		pii result = get_node(row, N - (1 << row));
		cout << K << " " << result.first << "/" << result.second << endl;
	}
	return 0;
}
