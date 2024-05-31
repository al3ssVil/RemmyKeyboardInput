#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct piesa
{
	int numar;
	char culoare[100];
};

void citirePiese(piesa*& vector)
{
	std::cout << "Citeste piese ";
	vector = new piesa[15];
	for (int i = 0; i < 14; i++)
		std::cin >> vector[i].numar >> vector[i].culoare;
}

void afisare(piesa* vector)
{
	for (int i = 0; i < 14; i++)
		std::cout << vector[i].numar << ' ' << vector[i].culoare << ' ';
}

void validare(piesa* vector)
{
	int** matrice;
	matrice = new int* [14];
	for (int i = 1; i < 14; i++)
	{
		matrice[i] = new int[5];
		for (int j = 1; j < 5; j++)
			matrice[i][j] = 0;
	}
	int ok = 1;
	for (int i = 0; i < 14 && ok == 1; i++)
	{
		if (vector[i].numar < 1 || vector[i].numar>13)
		{
			ok = 0;
			break;
		}
		if (strcmp(vector[i].culoare, "albastru") != 0)
			if (strcmp(vector[i].culoare, "negru") != 0)
				if (strcmp(vector[i].culoare, "rosu") != 0)
					if (strcmp(vector[i].culoare, "galben") != 0)
					{
						ok = 0;
						break;
					}
					else
						matrice[vector[i].numar][4]++;
				else
					matrice[vector[i].numar][3]++;
			else
				matrice[vector[i].numar][2]++;
		else
			matrice[vector[i].numar][1]++;
	}
	for (int i = 1; i < 14; i++)
		for (int j = 1; j < 5; j++)
			if (matrice[i][j] > 2)
				ok = 0;
	if (ok == 0)
	{
		std::cout << "Esuat" << '\n';
		citirePiese(vector);
	}
	else
		std::cout << "Valid" << '\n';
	for (int i = 1; i < 5; i++)
		delete[] matrice[i];
	delete[] matrice;
}

void quickSort(piesa*& vector, int left, int right)
{
	int i = left, j = right;
	int mijloc = vector[(i + j) / 2].numar;
	while (i <= j)
	{
		while (mijloc > vector[i].numar)
			i++;
		while (vector[j].numar > mijloc)
			j--;
		if (i <= j)
		{
			piesa aux = vector[i];
			vector[i] = vector[j];
			vector[j] = aux;
			i++;
			j--;
		}
	}
	if (left < j)
		quickSort(vector, left, j);
	if (i < right)
		quickSort(vector, i, right);
}

void succesiuneValoare(piesa* vector)
{
	for (int i = 0; i < 12; i++)
	{
		piesa* formatie;
		formatie = new piesa[10];
		formatie[0].numar = vector[i].numar;
		strcpy(formatie[0].culoare, vector[i].culoare);
		int pozitie = 1;
		for (int j = i; j < 14; j++)
			if (formatie[0].numar == vector[j].numar)
			{
				int ok = 1;
				for (int p = 0; p < pozitie && ok == 1; p++)
					if (strcmp(formatie[p].culoare, vector[j].culoare) == 0)
						ok = 0;
				if (ok == 1)
				{
					formatie[pozitie].numar = vector[j].numar;
					strcpy(formatie[pozitie].culoare, vector[j].culoare);
					pozitie++;
				}
			}
		if (pozitie >= 3)
		{
			for (int p = 0; p < pozitie; p++)
				std::cout << formatie[p].numar << ' ' << formatie[p].culoare << ' ';
			std::cout << '\n';
		}
		delete[] formatie;
	}
}

void verificareOrdonat(piesa* vector, piesa* vectorOrdonat)
{
	int numar = 0;
	for (int i = 0; i < 14; i++)
		if (vector[i].numar != vectorOrdonat[i].numar)
			numar++;
	if (numar)
		std::cout << numar << " piese si au schimbat pozitia " << '\n';
}

void succesiuneNumar(piesa* vector)
{
	for (int i = 0; i < 12; i++)
	{
		piesa* formatie;
		formatie = new piesa[10];
		formatie[0].numar = vector[i].numar;
		strcpy(formatie[0].culoare, vector[i].culoare);
		int pozitie = 1;
		for (int j = i; j < 14; j++)
			if (strcmp(formatie[0].culoare, vector[j].culoare) == 0)
			{
				if (formatie[pozitie - 1].numar + 1 == vector[j].numar)
				{
					formatie[pozitie].numar = vector[j].numar;
					strcpy(formatie[pozitie].culoare, vector[j].culoare);
					pozitie++;
				}
			}
		if (pozitie >= 3)
		{
			for (int p = 0; p < pozitie; p++)
				std::cout << formatie[p].numar << ' ' << formatie[p].culoare << ' ';
			std::cout << '\n';
		}
		delete[] formatie;
	}
}

void tragere(piesa*& vector)
{
	std::cout << "Da ti o valoare valida pentru a 15 a carte:";
	std::cin >> vector[14].numar;
	std::cin >> vector[14].culoare;
}

void ceaMaiLungaFormatie(piesa* vector)
{
	int Lungime = 0;
	piesa* maxim;
	maxim = new piesa[10];
	for (int i = 0; i <= 12; i++)
	{
		piesa* formatie;
		formatie = new piesa[10];
		formatie[0].numar = vector[i].numar;
		strcpy(formatie[0].culoare, vector[i].culoare);
		int pozitie = 1;
		for (int j = i; j <= 14; j++)
			if (formatie[0].numar == vector[j].numar)
			{
				int ok = 1;
				for (int p = 0; p < pozitie && ok == 1; p++)
					if (strcmp(formatie[p].culoare, vector[j].culoare) == 0)
						ok = 0;
				if (ok == 1)
				{
					formatie[pozitie].numar = vector[j].numar;
					strcpy(formatie[pozitie].culoare, vector[j].culoare);
					pozitie++;
				}
			}
		if (pozitie >= 3)
			for (int p = 0; p < pozitie; p++)
				if (formatie[p].numar == vector[14].numar)
					if (strcmp(formatie[p].culoare, vector[14].culoare) == 0)
						if (Lungime < pozitie)
						{
							Lungime = pozitie;
							for (int j = 0; j < pozitie; j++)
							{
								maxim[j].numar = formatie[j].numar;
								strcpy(maxim[j].culoare, formatie[j].culoare);
							}
						}
		delete[] formatie;
	}
	for (int i = 0; i <= 12; i++)
	{
		piesa* formatie;
		formatie = new piesa[10];
		formatie[0].numar = vector[i].numar;
		strcpy(formatie[0].culoare, vector[i].culoare);
		int pozitie = 1;
		for (int j = i; j <= 14; j++)
			if (strcmp(formatie[0].culoare, vector[j].culoare) == 0)
			{
				if (formatie[pozitie - 1].numar + 1 == vector[j].numar)
				{
					formatie[pozitie].numar = vector[j].numar;
					strcpy(formatie[pozitie].culoare, vector[j].culoare);
					pozitie++;
				}
			}
		if (pozitie >= 3)
			for (int p = 0; p < pozitie; p++)
				if (formatie[p].numar == vector[14].numar)
					if (strcmp(formatie[p].culoare, vector[14].culoare) == 0)
						if (Lungime < pozitie)
						{
							Lungime = pozitie;
							for (int j = 0; j < pozitie; j++)
							{
								maxim[j].numar = formatie[j].numar;
								strcpy(maxim[j].culoare, formatie[j].culoare);
							}
						}
		delete[] formatie;
	}
	if (Lungime > 0)
		for (int i = 0; i < Lungime; i++)
			std::cout << maxim[i].numar << ' ' << maxim[i].culoare << ' ';
	else
		std::cout << "Nu se poate face o formatie cu aceasta piesa";
	delete[] maxim;
}

int main()
{
	piesa* vector;
	piesa* vectorOrdonat;
	vectorOrdonat = new piesa[15];
	citirePiese(vector);
	for (int i = 0; i < 14; i++)
		vectorOrdonat[i] = vector[i];
	validare(vector);
	quickSort(vectorOrdonat, 0, 13);
	verificareOrdonat(vector, vectorOrdonat);
	succesiuneValoare(vector);
	succesiuneNumar(vector);
	tragere(vector);
	ceaMaiLungaFormatie(vector);
	delete[] vector;
	//1 albastru 2 negru 2 albastru 1 rosu 1 negru 3 albastru 10 negru 10 rosu 11 negru 10 albastru 12 rosu 8 albastru 13 negru 5 rosu
	return 0;
}