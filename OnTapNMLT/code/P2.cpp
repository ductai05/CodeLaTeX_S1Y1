#include <iostream>
#include <cmath>

using namespace std;

int Kth(int a, int b, int k){
	for(int i = 1; i > 0; i++){
		if(i % a == 0 || i % b == 0){
			k--;
		}
		if(k == 0){
			return i;
		}
	}
}

int main() {
	int a, b, k;
	cin >> a >> b >> k;
	cout << Kth(a, b, k);
    return 0;
}