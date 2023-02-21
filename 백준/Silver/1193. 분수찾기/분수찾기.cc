#include <iostream>
using namespace std;
int main() {
	int n, swi = 1, k = 0, i = 2, j = 0;
	cin >> n;
	while (k < n) { 
		if (swi == 1) {
			j++;
			i--;
			if (i != 0) {
				k++;
			}
			else if (i == 0) {
				i = 1;
				swi *= (-1);
				k++;
			}
		}
		else if (swi == -1) {
			i++;
			j--;
			if (j != 0) {
				k++;
			}
			else if (j == 0) {
				j = 1;
				swi *= (-1);
				k++;
			}
		}		
	}
	cout << i << '/' << j;
	return 0;
}