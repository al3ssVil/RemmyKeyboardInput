#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct piece
{
	int number;
	char color[15];
};

void ReadPieces(piece*& vector)
{
	std::cout << "Read pieces: ";
	vector = new piece[15];
	for (int i = 0; i < 14; i++)
		std::cin >> vector[i].number >> vector[i].color;
}

void Display(piece* vector)
{
	for (int i = 0; i < 14; i++)
		std::cout << vector[i].number << ' ' << vector[i].color << ' ';
}

void Validation(piece* vector)
{
	int** matrix;
	matrix = new int* [14];
	for (int i = 1; i < 14; i++)
	{
		matrix[i] = new int[5];
		for (int j = 1; j < 5; j++)
			matrix[i][j] = 0;
	}
	int ok = 1;
	for (int i = 0; i < 14 && ok == 1; i++)
	{
		if (vector[i].number < 1 || vector[i].number>13)
		{
			ok = 0;
			break;
		}
		if (strcmp(vector[i].color, "blue") != 0)
			if (strcmp(vector[i].color, "black") != 0)
				if (strcmp(vector[i].color, "red") != 0)
					if (strcmp(vector[i].color, "yellow") != 0)
					{
						ok = 0;
						break;
					}
					else
						matrix[vector[i].number][4]++;
				else
					matrix[vector[i].number][3]++;
			else
				matrix[vector[i].number][2]++;
		else
			matrix[vector[i].number][1]++;
	}
	for (int i = 1; i < 14; i++)
		for (int j = 1; j < 5; j++)
			if (matrix[i][j] > 2)
				ok = 0;
	if (ok == 0)
	{
		std::cout << "Invalid! Please read again." << '\n';
		ReadPieces(vector);
	}
	else
		std::cout << "Valid pieces" << '\n';
	for (int i = 1; i < 5; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void QuickSort(piece*& vector, int left, int right)
{
	int i = left, j = right;
	int middle = vector[(i + j) / 2].number;
	while (i <= j)
	{
		while (middle > vector[i].number)
			i++;
		while (vector[j].number > middle)
			j--;
		if (i <= j)
		{
			piece aux = vector[i];
			vector[i] = vector[j];
			vector[j] = aux;
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(vector, left, j);
	if (i < right)
		QuickSort(vector, i, right);
}

void ValueSequence(piece* vector)
{
	std::cout << "\nPieces ordered by value:\n";
	for (int i = 0; i < 12; i++)
	{
		piece* formation;
		formation = new piece[10];
		formation[0].number = vector[i].number;
		strcpy(formation[0].color, vector[i].color);
		int position = 1;
		for (int j = i; j < 14; j++)
			if (formation[0].number == vector[j].number)
			{
				int ok = 1;
				for (int p = 0; p < position && ok == 1; p++)
					if (strcmp(formation[p].color, vector[j].color) == 0)
						ok = 0;
				if (ok == 1)
				{
					formation[position].number = vector[j].number;
					strcpy(formation[position].color, vector[j].color);
					position++;
				}
			}
		if (position >= 3)
		{
			for (int p = 0; p < position; p++)
				std::cout << formation[p].number << ' ' << formation[p].color << ' ';
			std::cout << '\n';
		}
		delete[] formation;
	}
}

void CheckOrdered(piece* vector, piece* orderedVector)
{
	int number = 0;
	for (int i = 0; i < 14; i++)
		if (vector[i].number != orderedVector[i].number)
			number++;
	if (number)
		std::cout <<'\n'<< number << " pieces have changed their position after sorting " << '\n';
}

void NumberSequence(piece* vector)
{
	std::cout << "\nPieces ordered by number:\n";
	for (int i = 0; i < 12; i++)
	{
		piece* formation;
		formation = new piece[10];
		formation[0].number = vector[i].number;
		strcpy(formation[0].color, vector[i].color);
		int position = 1;
		for (int j = i; j < 14; j++)
			if (strcmp(formation[0].color, vector[j].color) == 0)
			{
				if (formation[position - 1].number + 1 == vector[j].number)
				{
					formation[position].number = vector[j].number;
					strcpy(formation[position].color, vector[j].color);
					position++;
				}
			}
		if (position >= 3)
		{
			for (int p = 0; p < position; p++)
				std::cout << formation[p].number << ' ' << formation[p].color << ' ';
			std::cout << '\n';
		}
		delete[] formation;
	}
}

void Draw(piece*& vector)
{
	std::cout << "\nGive a valid value for the 15th card: ";
	std::cin >> vector[14].number;
	std::cin >> vector[14].color;
}

void LongestFormation(piece* vector)
{
	int length = 0;
	piece* maxim;
	maxim = new piece[10];
	for (int i = 0; i <= 12; i++)
	{
		piece* formation;
		formation = new piece[10];
		formation[0].number = vector[i].number;
		strcpy(formation[0].color, vector[i].color);
		int position = 1;
		for (int j = i; j <= 14; j++)
			if (formation[0].number == vector[j].number)
			{
				int ok = 1;
				for (int p = 0; p < position && ok == 1; p++)
					if (strcmp(formation[p].color, vector[j].color) == 0)
						ok = 0;
				if (ok == 1)
				{
					formation[position].number = vector[j].number;
					strcpy(formation[position].color, vector[j].color);
					position++;
				}
			}
		if (position >= 3)
			for (int p = 0; p < position; p++)
				if (formation[p].number == vector[14].number)
					if (strcmp(formation[p].color, vector[14].color) == 0)
						if (length < position)
						{
							length = position;
							for (int j = 0; j < position; j++)
							{
								maxim[j].number = formation[j].number;
								strcpy(maxim[j].color, formation[j].color);
							}
						}
		delete[] formation;
	}
	for (int i = 0; i <= 12; i++)
	{
		piece* formation;
		formation = new piece[10];
		formation[0].number = vector[i].number;
		strcpy(formation[0].color, vector[i].color);
		int position = 1;
		for (int j = i; j <= 14; j++)
			if (strcmp(formation[0].color, vector[j].color) == 0)
			{
				if (formation[position - 1].number + 1 == vector[j].number)
				{
					formation[position].number = vector[j].number;
					strcpy(formation[position].color, vector[j].color);
					position++;
				}
			}
		if (position >= 3)
			for (int p = 0; p < position; p++)
				if (formation[p].number == vector[14].number)
					if (strcmp(formation[p].color, vector[14].color) == 0)
						if (length < position)
						{
							length = position;
							for (int j = 0; j < position; j++)
							{
								maxim[j].number = formation[j].number;
								strcpy(maxim[j].color, formation[j].color);
							}
						}
		delete[] formation;
	}
	if (length > 0)
	{
		std::cout << "\nThe longest formation made with this piece is: ";
		for (int i = 0; i < length; i++)
		
			std::cout << maxim[i].number << ' ' << maxim[i].color << ' ';
	}
	else
		std::cout << "\nA formation cannot be made with this piece";
	delete[] maxim;
}

int main()
{
	piece* vector;
	piece* orderedVector;
	orderedVector = new piece[15];
	ReadPieces(vector);
	for (int i = 0; i < 14; i++)
		orderedVector[i] = vector[i];
	Validation(vector);
	QuickSort(orderedVector, 0, 13);
	CheckOrdered(vector, orderedVector);
	ValueSequence(vector);
	NumberSequence(vector);
	Draw(vector);
	LongestFormation(vector);
	delete[] vector;
	//1 blue 2 black 2 blue 1 red 1 black 3 blue 10 black 10 red 11 black 10 blue 12 red 8 blue 4 black 5 red
	//Try first 4 blue for the 15th piece, after that try 5 red
	return 0;
}