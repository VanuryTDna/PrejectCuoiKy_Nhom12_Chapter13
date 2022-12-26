#include <iostream>
#include <thread>
using namespace std;

int soLanThucHien[2] = { 0 };
bool b[2] = { true, true };
int k = 0;
void TheSolution(int i) {
	// moi may thuc hien 3 lan (0->2)
	while (soLanThucHien[i] < 3) {
		b[i] = false; // bat dau 
		while(k != i) {
			// giu cho may con lai doi den khi nao thuc hien xong
			while (true) {
				if (b[1 - i] == true)
					break;
			}
			k = i;
		}
		cout << "critical section " << i << endl;
		b[i] = true;
		soLanThucHien[i]++;
	}
}

int main()
{
	thread may1(TheSolution, 0);
	thread may2(TheSolution, 1);
	may1.join();
	may2.join();
	return 0;
}
