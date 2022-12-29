#include <iostream>
#include <thread>
using namespace std;

int control[6] = { 0 };
int N = 5;
int k = 2;
int demSoLanDaLam[6] = { 0 };
int volumeLeft = 3000;
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
			if (volumeLeft <= 0) 
			{
				cout << "Het nuoc!\n";
			}
			else 
			{
				volumeLeft -= 500;
				cout << "Da lay duoc" << endl;
			}
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
		if (volumeLeft <= 0)
		{
			cout << "Het nuoc!\n";
		}
		else
		{
			int temp = volumeLeft - 500;
			cout << "Da lay duoc" << endl;
			volumeLeft -= 500;
		}
	demSoLanDaLam[i]++;
	}
}

int main() 
{
	thread mayOne(ConcurrentProgramming, 1);
	thread mayTwo(ConcurrentProgramming, 2);
	thread mayThree(ConcurrentProgramming,3);
	thread mayFour(ConcurrentProgramming, 4);
	thread mayFive(ConcurrentProgramming, 5);

	/*thread mayOne(ConcurrentProgramming1, 1);
	thread mayTwo(ConcurrentProgramming1, 2);
	thread mayThree(ConcurrentProgramming1, 3);
	thread mayFour(ConcurrentProgramming1, 4);
	thread mayFive(ConcurrentProgramming1, 5);*/

	mayOne.join();
	mayTwo.join();
	mayThree.join();
	mayFive.join();
	mayFour.join();
	return 0;
}