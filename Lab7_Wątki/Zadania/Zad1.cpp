#include <iostream>
#include <thread>

using namespace std;

//napisa� program kt�ry b�dzie sumowa� warto�ci tablicy doubli.
//nale�y to zrobi� dziel�c tablic� na 4 cz�ci, r�wnocze�nie je doda� a nast�pnie zssumowa� ze sob� otrzymane 4 wyniki

int main()
{
	double tab[100];
	for (int i = 0; i < 100; i++)
	{
		tab[i] = i;
	}


	return 0;
}