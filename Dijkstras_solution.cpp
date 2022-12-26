#include <iostream>
#include <thread>
using namespace std;
int N = 5; // so may thuc hien
bool B[6] = { true, true, true, true, true, true }; // muon vao phan critical section
bool C[6] = { true, true, true, true, true, true }; // dang trong phan critical section
int k = 1;
int soLanThucHien[5] = { 0 };
void TheSolution(int i) {
	while (soLanThucHien[i] < 3) {
		B[i] = false;
		while (true) {
			if (k != i) {
				C[i] = true; // doi may khac thuc hien
				if (B[k] == true) {
					k = i; // dua vao critical section
				}
			}
			else {
				C[i] = false; // thuc hien critical section
				bool c = true;
				// vong lap for dam bao chi co 1 may thuc hien 
				for (int j = 1; j <= N; j++) {
					if (j != i && C[j] == false)
						c = false;
				}
				if (c == true)
					break;
			}
		}
		cout << "critical section " << i << endl;
		C[i] = true; // thuc hien xong
		B[i] = true;
		soLanThucHien[i]++;
	}
}

int main()
{
	thread may1(TheSolution, 1);
	thread may2(TheSolution, 2);
	thread may3(TheSolution, 3);
	thread may4(TheSolution, 4);
	thread may5(TheSolution, 5);
	may1.join();
	may2.join();
	may3.join();
	may4.join();
	may5.join();
}