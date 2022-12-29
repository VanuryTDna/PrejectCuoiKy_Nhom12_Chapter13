#include <iostream>
#include <thread>
using namespace std;

int control[6] = { 0 };
int N = 5;
int k = 2;
int demSoLanDaLam[6] = { 0 };
int a[50] = { 0 };
int na = 0;
void ConcurrentProgramming(int i) 
{
	int j, flag = 1;
	while (demSoLanDaLam[i] <= 1) 
	{
		control[i] = 1;
		j = k;
		while (j >= 1) 
		{
			if (j == i)
				break;
			if (control[j] != 0) 
			{
				j = k + 1;
				flag = 1;
			}
			j--;
			if (j < 1 && flag) 
			{
				j = N;
				flag = 0;
			}
		}
		control[i] = 2;
		for (j = N; j >= 1; j--) 
		{
			if (j != i && control[j] == 2) 
				break;
		}
		if (j < 1) 
		{
			a[na] = i;
			cout << "Da nhan duoc mot thu moi" << "\n";
			na++;
			if (control[k] == 0 || k == i) 
			{
				if (k == 1)
					k = N;
				else
					k = k - 1;
			}
			control[i] = 0;
			demSoLanDaLam[i]++;
		}
	}
}

void ConcurrentProgramming1(int i) 
{
	while (demSoLanDaLam[i] <= 1)
	{
		a[na] = i;
		cout << "Da nhan duoc mot thu moi" << "\n";
		na++;
		demSoLanDaLam[i]++;
	}
}

int main() 
{
	thread mayOne(ConcurrentProgramming, 1);
	thread mayTwo(ConcurrentProgramming, 2);
	thread mayThree(ConcurrentProgramming, 3);
	thread mayFour(ConcurrentProgramming, 4);
	thread mayFive(ConcurrentProgramming, 5);

	/*thread mayOne(ConcurrentProgramming1, 1);
	thread mayTwo(ConcurrentProgramming1, 2);
	thread mayThree(ConcurrentProgramming1,3);
	thread mayFour(ConcurrentProgramming1, 4);
	thread mayFive(ConcurrentProgramming1, 5);*/

	mayOne.join();
	mayTwo.join();
	mayThree.join();
	mayFive.join();
	mayFour.join();

	for (int i = 0; i < na; i++)
		cout << a[i] << " ";
	return 0;
}
