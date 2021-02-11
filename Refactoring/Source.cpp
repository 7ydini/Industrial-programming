#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void soutMatrix(int** matrix,size_t x,size_t y);//Метод для вывода матрицы.
void matrixRandFill(int** matrix, size_t x,size_t y);//Метод для заполнение матрицы случайными значениями.
void matrixFill(int** matrix, size_t x2, size_t y2);//Метод для заполнения матрицы вручную.
void initMatrix(int** matrix, int x, int y);//Метод для инициализации матрицы
void copyMatrix(int** matrix1, int** matrix2, size_t x, size_t y);//Метод для копирования матриц.

void main()
{
	srand(time(NULL));
	int x1, y1, x2, y2, k, l = 2;//k - показатель заполнения матрицы(вручную или случайно), l - размерность матрицы, для приведения к общему размеру. Х У - Размерность матриц
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Ввод размеров матрицы пользователем////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Дважды введите размеры первой матрицы(х, у)\n";
		cin >> x1 >> y1;
	} while (x1 <= 0 || y1 <= 0);
	do
	{
		cout << "Дважды введите размеры второй матрицы(х, у)\n";
		cin >> x2 >> y2;
	} while (x2 <= 0 || y2 <= 0);
	int** M1 = new int* [x1];
	initMatrix(M1, x1, y1);
	int** M2 = new int* [x2];
	initMatrix(M2, x2, y2);
	/*int** M1 = new int* [x1];
	for (int i = 0; i < x1; i++)
		M1[i] = new int[y1];
	int** M2 = new int* [x2];
	for (int i = 0; i < x2; i++)
		M2[i] = new int[y2];*/

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выбор способа заполнения и заполнение матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		cin >> k;
	} while (k < 1 || k > 2);
	switch (k)
	{
	case 1:
		matrixFill(M1, x1, y1);//Метод заполнения матрицы вручную.

		/*for (int i = 0; i < x1; i++)
			for (int j = 0; j < y1; j++)
				cin >> M1[i][j];*/

		matrixFill(M2, x2, y2);//Метод заполнения матрицы вручную.

		/*for (int i = 0; i < x2; i++)
			for (int j = 0; j < y2; j++)
				cin >> M2[i][j];*/

		cout << "\nМатрица 1\n\n";
		soutMatrix(M1, x1, y1);//Метод для вывода матрицы.

		/*for (int i = 0; i < x1; i++)
		{
			for (int j = 0; j < y1; j++)
				cout << M1[i][j] << " ";
			cout << endl;
		}*/
		cout << "\nМатрица 2\n\n";
		soutMatrix(M2, x2, y2);//Метод для вывода матрицы.

		/*for (int i = 0; i < x2; i++)
		{
			for (int j = 0; j < y2; j++)
				cout << M2[i][j] << " ";
			cout << endl;
		}*/
		break;
	case 2:
		matrixRandFill(M1, x1, y1);//Метод для заполнение матрицы случайными значениями.

		/*for (int i = 0; i < x1; i++)
			for (int j = 0; j < y1; j++)
				M1[i][j] = rand() % 10;*/

		matrixRandFill(M2, x2, y2);

		/*for (int i = 0; i < x2; i++)
			for (int j = 0; j < y2; j++)
				M2[i][j] = rand() % 10;*/

		cout << "\nМатрица 1\n\n";
		soutMatrix(M1, x1, y1);

		/*for (int i = 0; i < x1; i++)
		{
			for (int j = 0; j < y1; j++)
				cout << M1[i][j] << " ";
			cout << endl;
		}
		*/

		cout << "\nМатрица 2\n\n";
		soutMatrix(M2, x2, y2);

		/*for (int i = 0; i < x2; i++)
		{
			for (int j = 0; j < y2; j++)
				cout << M2[i][j] << " ";
			cout << endl;
		}*/

		break;
	}

	///////////////////////////////////////////////////////////////////////////////
	/////////////////Приведение матриц к требуемому размеру////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (l < x1 || l < x2 || l < y1 || l < y2)
		l *= 2;
	int** M3 = new int* [l];
	initMatrix(M3, l, l);
	int** M4 = new int* [l];
	initMatrix(M4, l, l);
	/*int** M3 = new int* [l];
	for (int i = 0; i < l; i++)
	{
		M3[i] = new int[l];
		for (int j = 0; j < l; j++)
			M3[i][j] = 0;
	}*/
	/*int** M4 = new int* [l];
	for (int i = 0; i < l; i++)
	{
		M4[i] = new int[l];
		for (int j = 0; j < l; j++)
			M4[i][j] = 0;
	}*/
	copyMatrix(M3, M1, x1, y1);
	/*for (int i = 0; i < x1; i++)
	{
		for (int j = 0; j < y1; j++)
			M3[i][j] = M1[i][j];
	}*/
	copyMatrix(M4, M2, x2, y2);
	/*for (int i = 0; i < x2; i++)
	{
		for (int j = 0; j < y2; j++)
			M4[i][j] = M2[i][j];
	}*/
	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	soutMatrix(M3, l, l);
	/*for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
			cout << M3[i][j] << " ";
		cout << endl;
	}*/
	cout << "\nМатрица 2\n\n";
	soutMatrix(M4, l, l);
	/*for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
			cout << M4[i][j] << " ";
		cout << endl;
	}*/

	///////////////////////////////////////////////////////////////////////////////
	///////////////Разбиение матриц на подматрицы и их заполнение//////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** semiMatrix1 = new int* [l / 2];
	initMatrix(semiMatrix1, l / 2, l / 2);
	copyMatrix(semiMatrix1, M3, l/2, l/2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix1[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix1[i][j] = M3[i][j];
	}*/
	int** semiMatrix2 = new int* [l / 2];
	initMatrix(semiMatrix2, l / 2, l / 2);
	copyMatrix(semiMatrix2, M3, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix2[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix2[i][j] = M3[i][j + l / 2];
	}*/

	int** semiMatrix3 = new int* [l / 2];
	initMatrix(semiMatrix3, l / 2, l / 2);
	copyMatrix(semiMatrix3, M3, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix3[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix3[i][j] = M3[i + l / 2][j];
	}*/
	int** semiMatrix4 = new int* [l / 2];
	initMatrix(semiMatrix4, l / 2, l / 2);
	copyMatrix(semiMatrix4, M3, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix4[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix4[i][j] = M3[i + l / 2][j + l / 2];
	}*/
	int** semiMatrix5 = new int* [l / 2];
	initMatrix(semiMatrix5, l / 2, l / 2);
	copyMatrix(semiMatrix5, M4, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix5[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix5[i][j] = M4[i][j];
	}*/
	int** semiMatrix6 = new int* [l / 2];
	initMatrix(semiMatrix6, l / 2, l / 2);
	copyMatrix(semiMatrix6, M4, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix6[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix6[i][j] = M4[i][j + l / 2];
	}*/
	int** semiMatrix7 = new int* [l / 2];
	initMatrix(semiMatrix7, l / 2, l / 2);
	copyMatrix(semiMatrix7, M4, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix7[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix7[i][j] = M4[i + l / 2][j];
	}*/
	int** semiMatrix8 = new int* [l / 2];
	initMatrix(semiMatrix8, l / 2, l / 2);
	copyMatrix(semiMatrix8, M4, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix8[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix8[i][j] = M4[i + l / 2][j + l / 2];
	}*/

	///////////////////////////////////////////////////////////////////////////////
	////////////////////////Создание промежуточных матриц//////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** p1 = new int* [l / 2];
	initMatrix(p1, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		p1[i] = new int[l / 2];
	}*/
	int** p2 = new int* [l / 2];
	initMatrix(p2, l/2, l/2);
	/*for (int i = 0; i < l / 2; i++)
	{
		p2[i] = new int[l / 2];
	}*/
	int** p3 = new int* [l / 2];
	initMatrix(p3, l / 2 , l / 2);

	/*for (int i = 0; i < l / 2; i++)
	{
		p3[i] = new int[l / 2];
	}*/
	int** p4 = new int* [l / 2];
	initMatrix(p4, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		p4[i] = new int[l / 2];
	}*/
	int** p5 = new int* [l / 2];
	initMatrix(p5, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		p5[i] = new int[l / 2];
	}*/
	int** p6 = new int* [l / 2];
	initMatrix(p6, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		p6[i] = new int[l / 2];
	}*/
	int** p7 = new int* [l / 2];
	initMatrix(p7, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		p7[i] = new int[l / 2];
	}*/

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Вычисление значений промежуточных матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			p1[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p1[i][j] += (semiMatrix1[i][z] + semiMatrix4[i][z]) * (semiMatrix5[z][j] + semiMatrix8[z][j]);
			}

			p2[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p2[i][j] += (semiMatrix3[i][z] + semiMatrix4[i][z]) * semiMatrix5[z][j];
			}

			p3[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p3[i][j] += semiMatrix1[i][z] * (semiMatrix6[z][j] - semiMatrix8[z][j]);
			}

			p4[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p4[i][j] += semiMatrix4[i][z] * (semiMatrix7[z][j] - semiMatrix5[z][j]);
			}

			p5[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p5[i][j] += (semiMatrix1[i][z] + semiMatrix2[i][z]) * semiMatrix8[z][j];
			}

			p6[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p6[i][j] += (semiMatrix3[i][z] - semiMatrix1[i][z]) * (semiMatrix5[z][j] + semiMatrix6[z][j]);
			}

			p7[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p7[i][j] += (semiMatrix2[i][z] - semiMatrix4[i][z]) * (semiMatrix7[z][j] + semiMatrix8[z][j]);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////Создание вспомогательных матриц/////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** semiMatrix9 = new int* [l / 2];
	initMatrix(semiMatrix9, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix9[i] = new int[l / 2];
	}*/
	int** semiMatrix10 = new int* [l / 2];
	initMatrix(semiMatrix10, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix10[i] = new int[l / 2];
	}*/
	int** semiMatrix11 = new int* [l / 2];
	initMatrix(semiMatrix11, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix11[i] = new int[l / 2];
	}*/
	int** semiMatrix12 = new int* [l / 2];
	initMatrix(semiMatrix12, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix12[i] = new int[l / 2];
	}*/

	///////////////////////////////////////////////////////////////////////////////
	////////////Подсчет значений вспомогательных матриц из промежуточных///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			semiMatrix9[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
			semiMatrix10[i][j] = p3[i][j] + p5[i][j];
			semiMatrix11[i][j] = p2[i][j] + p4[i][j];
			semiMatrix12[i][j] = p1[i][j] - p2[i][j] + p3[i][j] + p6[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** M5 = new int* [l];
	for (int i = 0; i < l; i++)
	{
		M5[i] = new int[l];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из вспомогательных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			M5[i][j] = semiMatrix9[i][j];
			M5[i][j + l / 2] = semiMatrix10[i][j];
			M5[i + l / 2][j] = semiMatrix11[i][j];
			M5[i + l / 2][j + l / 2] = semiMatrix12[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выравнивание границ результирующей матрицы/////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int x = 0, f = 100, s = 100;
	for (int i = 0; i < l; i++)
	{
		x = 0;
		for (int j = 0; j < l; j++)
		{
			if (M5[i][j] != 0)
			{
				x++;
				f = 100;
			}
		}
		if (x == 0 && i < f)
		{
			f = i;
		}
	}
	for (int i = 0; i < l; i++)
	{
		x = 0;
		for (int j = 0; j < l; j++)
		{
			if (M5[j][i] != 0)
			{
				x++;
				s = 100;
			}
		}
		if (x == 0 && i < s)
		{
			s = i;
		}
	}

	int** M6 = new int* [f];
	for (int i = 0; i < f; i++)
	{
		M6[i] = new int[s];
		for (int j = 0; j < s; j++)
			M6[i][j] = M5[i][j];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "\nРезультирующая матрица\n\n";
	soutMatrix(M6, f, s);
	/*for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < s; j++)
			cout << M6[i][j] << " ";
		cout << endl;
	}*/

	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Очистка динамической памяти///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	
	for (int i = 0; i < x1; i++)
		delete[] M1[i];
	for (int i = 0; i < x2; i++)
		delete[] M2[i];
	for (int i = 0; i < l; i++)
	{
		delete[] M3[i];
		delete[] M4[i];
		delete[] M5[i];
	}
	for (int i = 0; i < f; i++)
		delete[] M6[i];
	for (int i = 0; i < l / 2; i++)
	{
		delete[] semiMatrix1[i];
		delete[] semiMatrix2[i];
		delete[] semiMatrix3[i];
		delete[] semiMatrix4[i];
		delete[] semiMatrix5[i];
		delete[] semiMatrix6[i];
		delete[] semiMatrix7[i];
		delete[] semiMatrix8[i];
		delete[] semiMatrix9[i];
		delete[] semiMatrix10[i];
		delete[] semiMatrix11[i];
		delete[] semiMatrix12[i];
		delete[] p1[i];
		delete[] p2[i];
		delete[] p3[i];
		delete[] p4[i];
		delete[] p5[i];
		delete[] p6[i];
		delete[] p7[i];
	}
	delete[] M1, M2, M3, M4, M5, M6;
	delete[] semiMatrix1, semiMatrix2, semiMatrix3, semiMatrix4, semiMatrix5, semiMatrix6, semiMatrix7, semiMatrix8, semiMatrix9, semiMatrix10, semiMatrix11, semiMatrix12;
	delete[] p1, p2, p3, p4, p5, p6, p7;
}
void soutMatrix(int** matrix, size_t x, size_t y){//Метод для вывода матрицы.
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void matrixRandFill(int** matrix, size_t x, size_t y) {//Метод для заполнение матрицы случайными значениями.
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			matrix[i][j] = rand() % 10;
}

void matrixFill(int** matrix, size_t x, size_t y) {//Метод заполнения матрицы вручную.
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> matrix[i][j];
}

void initMatrix(int** matrix, int x, int y) {//Метод инициализации матрицы.
	//matrix = new int* [x];
	for (int i = 0; i < x; i++)
		matrix[i] = new int[y];
	//return matrix;
}

void copyMatrix( int** matrix1, int** matrix2, size_t x, size_t y) {//Метод копирования матрицы.
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			matrix1[i][j] = matrix2[i][j];
	}
}
