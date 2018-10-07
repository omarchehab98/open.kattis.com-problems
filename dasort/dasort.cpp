#include <bits/stdc++.h>
using namespace std;

int arr[1001];
bool dropped[1001];

int main(){
	int P,K,N;
	cin >> P;
	for(int i = 0; i < P; i++){
		cin >> K >> N;
		memset(dropped, 0, sizeof(dropped));
		for(int j = 0; j < N; j++)
			cin >> arr[j];
		int min_dropped = 0x3f3f3f3f;
		for(int j = 1; j < N; j++){
			int k = j - 1;
			while(k >= 0 && (arr[k] > arr[j] || dropped[k])){
				dropped[k] = true;
				min_dropped = min(min_dropped, arr[k]);
				k--;
			}
		}
		int total_dropped = 0;
		for(int j = 0; j < N; j++)
			if(dropped[j] || arr[j] > min_dropped)
				total_dropped++;
		cout << K << " " << total_dropped << endl;
	}
	return 0;
}
