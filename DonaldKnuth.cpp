#include <iostream>
#include <thread>
using namespace std;

int control[6] = {0};
int N = 5;
int k = 2;
int demSoLanDaLam[6] = {0};

void DonaldKnuth(int i) {
	int j, flag = 1;
	while (demSoLanDaLam[i] <= 2) {
		control[i] = 1;
		j = k;
		while (j >= 1) {
			if (j==i) 
				break;
			if (control[j] != 0) {
				j = k+1;
				flag = 1;
			}
			j--;
			if (j < 1 && flag) {
				j = N;
				flag = 0;
			}
		}
		control[i] = 2;
		for (j=N;j>=1;j--) {
			if (j != i && control[j] == 2) break;
		}
		if (j < 1) {
			k = i;
			cout << "May " << i << " thuc hien critical section!\n";
			if (i == 1)
				k = N;
			else
				k = i - 1;
			control[i] = 0;
			demSoLanDaLam[i]++;
		}
		flag = 1;
	}
}

void DonaldKnuthBruijn(int i) {
	int j, flag = 1;
	while (demSoLanDaLam[i] <= 2) {
		control[i] = 1;
		j = k;
		while (j >= 1) {
			if (j==i) 
				break;
			if (control[j] != 0) {
				j = k+1;
				flag = 1;
			}
			j--;
			if (j < 1 && flag) {
				j = N;
				flag = 0;
			}
		}
		control[i] = 2;
		for (j=N;j>=1;j--) {
			if (j != i && control[j] == 2) break;
		}
		if (j < 1) {
			cout << "May " << i << " thuc hien critical section!\n";
			if (control[k] == 0 || k == i) {
				if (k == 1)
					k = N;
				else
					k = k -1;
			} 
			control[i] = 0;
			demSoLanDaLam[i]++;
		}
		flag = 1;
	}
}

void KoDonaldKnuth(int i) {
	while (demSoLanDaLam[i] <= 2) {
		cout << "May " << i << " thuc hien critical section!\n";
		demSoLanDaLam[i]++;
	}
}

int main() {
	thread may[5];
	for (int i=0;i<5;i++) {
		may[i] = thread(DonaldKnuth, i + 1);
	}
	for (int i=0;i<5;i++) {
		may[i].join();
	}
	
	return 0;
}
