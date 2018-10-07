#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

pii rotate_right(pii direction){
	return make_pair(direction.second, -direction.first);
}

pii add(pii op1, pii op2){
	return make_pair(op1.first + op2.first, op1.second + op2.second);
}

string get_str_dir(pii direction){
	if(direction.first == 0){
		if(direction.second == -1)
			return "down";
		else
			return "up";
	}else{
		if(direction.first == -1)
			return "left";
		else
			return "right";
	}
}


int main(){
	pii pos = make_pair(0,0);
	pii dir = make_pair(-1,0);
	string next_line;
	cout << get_str_dir(dir) << "\n";
	while(cin >> next_line){
		if(next_line == "wall"){
			dir = rotate_right(dir);
		}else if(next_line == "ok"){
			pos = add(pos, dir);
			dir = rotate_right(make_pair(-dir.first, -dir.second));
		}else if(next_line == "solved"){
			//reset
			pos = make_pair(0,0);
			dir = make_pair(-1,0);
		}
//		cout << pos.first << "," << pos.second << " " << dir.first << "," << dir.second << endl;
		if(next_line != "solved" && pos == make_pair(0,0) && dir == make_pair(-1,0)){
			cout << "no way out\n";
			pos = make_pair(0,0);
			dir = make_pair(-1,0);
		}
		cout << get_str_dir(dir) << "\n";
	}	
	return 0;
}
