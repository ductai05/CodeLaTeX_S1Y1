#include <iostream>
#include <cmath>
#define max_dong 75
#define max_cot 75

using namespace std;

int Check(int a[max_dong][max_cot], int I, int J, int n, int m){
	int S = 0, maxx = 0;
	bool Break = false;
	for(int i = I; i < n; i++){
		for(int j = J; j < m; j++){
			S = (i - I + 1)*(j - J + 1);
			Break = false;
			for(int x = I; x <= i; x++){
				for(int y = J; y <= j; y++){
					if(a[x][y] == 0){
						Break = true;
						break;
					}
				}
				if (Break) {
                    break; 
                }
			}
			if(maxx < S && Break == false){
				maxx = S;
			}
		}
	}
	return maxx;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int a[max_dong][max_cot];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] <= k){
				a[i][j] = 1;
			} else {
				a[i][j] = 0;
			}
		}
	}
	int S = 0, maxx = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			S = Check(a, i, j, n, m);
			if(maxx < S){
				maxx = S;
			}
		}
	}
	cout << maxx;
    return 0;
}