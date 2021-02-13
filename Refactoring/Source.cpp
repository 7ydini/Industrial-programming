#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void soutMatrix(int** matrix, size_t x, size_t y);//Метод для вывода матрицы.
void matrixRandFill(int** matrix, size_t x, size_t y);//Метод для заполнение матрицы случайными значениями.
void matrixFill(int** matrix, size_t x, size_t y);//Метод для заполнения матрицы вручную.
void initMatrix(int** matrix, int x, int y);//Метод для инициализации матрицы х у - размерность
void copyMatrix(int** matrix1, int** matrix2, size_t x, size_t y, size_t k, size_t l);//Метод копирования матрицы. Где x y размерность, а k l - смещение.
void initFillMatrix(int** matrix, size_t x, size_t l);//Метод создания и заполнения матрицы нулями
int borderMatrix(int** matrix, size_t k, size_t l);//Метод определяющий границы матрицы
void delMatrix(int** matrix, size_t k);//Метод удаления матрицы


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
		cout << "x : ";
		cin >> x1;
		cout << "y : ";
		cin >> y1;
	} while (x1 <= 0 || y1 <= 0);
	do
	{
		cout << "Дважды введите размеры второй матрицы(х, у)\n";
		cout << "x : ";
		cin >> x2;
		cout << "y : ";
		cin >> y2;
	} while (x2 <= 0 || y2 <= 0);
	int** Matrix1 = new int* [x1];
	initMatrix(Matrix1, x1, y1);
	int** Matrix2 = new int* [x2];
	initMatrix(Matrix2, x2, y2);
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
		matrixFill(Matrix1, x1, y1);//Метод заполнения матрицы вручную.


		/*for (int i = 0; i < x1; i++)
			for (int j = 0; j < y1; j++)
				cin >> M1[i][j];*/


		matrixFill(Matrix2, x2, y2);//Метод заполнения матрицы вручную.


		/*for (int i = 0; i < x2; i++)
			for (int j = 0; j < y2; j++)
				cin >> M2[i][j];*/


		cout << "\nМатрица 1\n\n";
		soutMatrix(Matrix1, x1, y1);//Метод для вывода матрицы.


		/*for (int i = 0; i < x1; i++)
		{
			for (int j = 0; j < y1; j++)
				cout << M1[i][j] << " ";
			cout << endl;
		}*/
		cout << "\nМатрица 2\n\n";
		soutMatrix(Matrix2, x2, y2);//Метод для вывода матрицы.


		/*for (int i = 0; i < x2; i++)
		{
			for (int j = 0; j < y2; j++)
				cout << M2[i][j] << " ";
			cout << endl;
		}*/
		break;
	case 2:
		matrixRandFill(Matrix1, x1, y1);//Метод для заполнение матрицы случайными значениями.


		/*for (int i = 0; i < x1; i++)
			for (int j = 0; j < y1; j++)
				M1[i][j] = rand() % 10;*/


		matrixRandFill(Matrix2, x2, y2);


		/*for (int i = 0; i < x2; i++)
			for (int j = 0; j < y2; j++)
				M2[i][j] = rand() % 10;*/


		cout << "\nМатрица 1\n\n";
		soutMatrix(Matrix1, x1, y1);


		/*for (int i = 0; i < x1; i++)
		{
			for (int j = 0; j < y1; j++)
				cout << M1[i][j] << " ";
			cout << endl;
		}
		*/


		cout << "\nМатрица 2\n\n";
		soutMatrix(Matrix2, x2, y2);


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
	int** Matrix3 = new int* [l];
	initFillMatrix(Matrix3, l, l);
	int** Matrix4 = new int* [l];
	initFillMatrix(Matrix4, l, l);
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
	copyMatrix(Matrix3, Matrix1, x1, y1, 0, 0);
	/*for (int i = 0; i < x1; i++)
	{
		for (int j = 0; j < y1; j++)
			M3[i][j] = M1[i][j];
	}*/
	copyMatrix(Matrix4, Matrix2, x2, y2, 0, 0);
	/*for (int i = 0; i < x2; i++)
	{
		for (int j = 0; j < y2; j++)
			M4[i][j] = M2[i][j];
	}*/
	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	soutMatrix(Matrix3, l, l);
	/*for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
			cout << M3[i][j] << " ";
		cout << endl;
	}*/
	cout << "\nМатрица 2\n\n";
	soutMatrix(Matrix4, l, l);
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
	copyMatrix(semiMatrix1, Matrix3, l / 2, l / 2, 0, 0);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix1[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix1[i][j] = M3[i][j];
	}*/
	int** semiMatrix2 = new int* [l / 2];
	initMatrix(semiMatrix2, l / 2, l / 2);
	copyMatrix(semiMatrix2, Matrix3, l / 2, l / 2, 0, l/2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix2[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix2[i][j] = M3[i][j + l / 2];
	}*/


	int** semiMatrix3 = new int* [l / 2];
	initMatrix(semiMatrix3, l / 2, l / 2);
	copyMatrix(semiMatrix3, Matrix3, l / 2, l / 2, l/2, 0);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix3[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix3[i][j] = M3[i + l / 2][j];
	}*/
	int** semiMatrix4 = new int* [l / 2];
	initMatrix(semiMatrix4, l / 2, l / 2);
	copyMatrix(semiMatrix4, Matrix3, l / 2, l / 2, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix4[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix4[i][j] = M3[i + l / 2][j + l / 2];
	}*/
	int** semiMatrix5 = new int* [l / 2];
	initMatrix(semiMatrix5, l / 2, l / 2);
	copyMatrix(semiMatrix5, Matrix4, l / 2, l / 2, 0, 0);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix5[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix5[i][j] = M4[i][j];
	}*/
	int** semiMatrix6 = new int* [l / 2];
	initMatrix(semiMatrix6, l / 2, l / 2);
	copyMatrix(semiMatrix6, Matrix4, l / 2, l / 2, 0, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix6[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix6[i][j] = M4[i][j + l / 2];
	}*/
	int** semiMatrix7 = new int* [l / 2];
	initMatrix(semiMatrix7, l / 2, l / 2);
	copyMatrix(semiMatrix7, Matrix4, l / 2, l / 2, l / 2, 0);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix7[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix7[i][j] = M4[i + l / 2][j];
	}*/
	int** semiMatrix8 = new int* [l / 2];
	initMatrix(semiMatrix8, l / 2, l / 2);
	copyMatrix(semiMatrix8, Matrix4, l / 2, l / 2, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		semiMatrix8[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			semiMatrix8[i][j] = M4[i + l / 2][j + l / 2];
	}*/


	///////////////////////////////////////////////////////////////////////////////
	////////////////////////Создание промежуточных матриц//////////////////////////
	///////////////////////////////////////////////////////////////////////////////


	int** intermediateMatrix1 = new int* [l / 2];
	initMatrix(intermediateMatrix1, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		p1[i] = new int[l / 2];
	}*/
	int** intermediateMatrix2 = new int* [l / 2];
	initMatrix(intermediateMatrix2, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		p2[i] = new int[l / 2];
	}*/
	int** intermediateMatrix3 = new int* [l / 2];
	initMatrix(intermediateMatrix3, l / 2, l / 2);


	/*for (int i = 0; i < l / 2; i++)
	{
		p3[i] = new int[l / 2];
	}*/
	int** intermediateMatrix4 = new int* [l / 2];
	initMatrix(intermediateMatrix4, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		p4[i] = new int[l / 2];
	}*/
	int** intermediateMatrix5 = new int* [l / 2];
	initMatrix(intermediateMatrix5, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		p5[i] = new int[l / 2];
	}*/
	int** intermediateMatrix6 = new int* [l / 2];
	initMatrix(intermediateMatrix6, l / 2, l / 2);
	/*for (int i = 0; i < l / 2; i++)
	{
		p6[i] = new int[l / 2];
	}*/
	int** intermediateMatrix7 = new int* [l / 2];
	initMatrix(intermediateMatrix7, l / 2, l / 2);
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
			intermediateMatrix1[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				intermediateMatrix1[i][j] += (semiMatrix1[i][z] + semiMatrix4[i][z]) * (semiMatrix5[z][j] + semiMatrix8[z][j]);
			}


			intermediateMatrix2[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				intermediateMatrix2[i][j] += (semiMatrix3[i][z] + semiMatrix4[i][z]) * semiMatrix5[z][j];
			}


			intermediateMatrix3[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				intermediateMatrix3[i][j] += semiMatrix1[i][z] * (semiMatrix6[z][j] - semiMatrix8[z][j]);
			}


			intermediateMatrix4[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				intermediateMatrix4[i][j] += semiMatrix4[i][z] * (semiMatrix7[z][j] - semiMatrix5[z][j]);
			}


			intermediateMatrix5[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				intermediateMatrix5[i][j] += (semiMatrix1[i][z] + semiMatrix2[i][z]) * semiMatrix8[z][j];
			}


			intermediateMatrix6[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				intermediateMatrix6[i][j] += (semiMatrix3[i][z] - semiMatrix1[i][z]) * (semiMatrix5[z][j] + semiMatrix6[z][j]);
			}


			intermediateMatrix7[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				intermediateMatrix7[i][j] += (semiMatrix2[i][z] - semiMatrix4[i][z]) * (semiMatrix7[z][j] + semiMatrix8[z][j]);
			}
		}
	}


	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание вспомогательных матриц(semiMatrix)/////////////////
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
			semiMatrix9[i][j] = intermediateMatrix1[i][j] + intermediateMatrix4[i][j] - intermediateMatrix5[i][j] + intermediateMatrix7[i][j];
			semiMatrix10[i][j] = intermediateMatrix3[i][j] + intermediateMatrix5[i][j];
			semiMatrix11[i][j] = intermediateMatrix2[i][j] + intermediateMatrix4[i][j];
			semiMatrix12[i][j] = intermediateMatrix1[i][j] - intermediateMatrix2[i][j] + intermediateMatrix3[i][j] + intermediateMatrix6[i][j];
		}
	}


	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////


	int** Matrix5 = new int* [l];
	initMatrix(Matrix5, l, l);
	/*for (int i = 0; i < l; i++)
	{
		M5[i] = new int[l];
	}*/


	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из вспомогательных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////


	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			Matrix5[i][j] = semiMatrix9[i][j];
			Matrix5[i][j + l / 2] = semiMatrix10[i][j];
			Matrix5[i + l / 2][j] = semiMatrix11[i][j];
			Matrix5[i + l / 2][j + l / 2] = semiMatrix12[i][j];
		}
	}


	///////////////////////////////////////////////////////////////////////////////
	////////////////Выравнивание границ результирующей матрицы/////////////////////
	///////////////////////////////////////////////////////////////////////////////


	int x = 0, f = 100, s = 100;
	f = borderMatrix(Matrix5, l, f);
	/*for (int i = 0; i < l; i++)
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
	}*/
	s = borderMatrix(Matrix5, l, s);
	/*for (int i = 0; i < l; i++)
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
	}*/


	int** Matrix6 = new int* [f];
	initFillMatrix(Matrix6, f, s);
	copyMatrix(Matrix6, Matrix5, f, s, 0, 0);
	/*for (int i = 0; i < f; i++)
	{
		M6[i] = new int[s];
		for (int j = 0; j < s; j++)
			M6[i][j] = M5[i][j];
	}*/


	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////


	cout << "\nРезультирующая матрица\n\n";
	soutMatrix(Matrix6, f, s);
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
	delMatrix(Matrix1, x1);
	delMatrix(Matrix2, x2);
	/*for (int i = 0; i < x1; i++)
		delete[] M1[i];
	for (int i = 0; i < x2; i++)
		delete[] M2[i];*/
	delMatrix(Matrix3, l);
	delMatrix(Matrix4, l);
	delMatrix(Matrix5, l);
	/*for (int i = 0; i < l; i++)
	{
		delete[] M3[i];
		delete[] M4[i];
		delete[] M5[i];
	}*/
	delMatrix(Matrix6, f);
	/*for (int i = 0; i < f; i++)
		delete[] M6[i];*/
	delMatrix( semiMatrix1, l / 2 );
	delMatrix( semiMatrix2, l / 2 );
	delMatrix( semiMatrix3, l / 2 );
	delMatrix( semiMatrix4, l / 2 );
	delMatrix( semiMatrix5, l / 2 );
	delMatrix( semiMatrix6, l / 2 );
	delMatrix( semiMatrix7, l / 2 );
	delMatrix( semiMatrix8, l / 2 );
	delMatrix( semiMatrix9, l / 2 );
	delMatrix( semiMatrix10, l / 2 );
	delMatrix( semiMatrix11, l / 2 );
	delMatrix( semiMatrix12, l / 2 );
	delMatrix( intermediateMatrix1, l / 2 );
	delMatrix( intermediateMatrix2, l / 2 );
	delMatrix( intermediateMatrix3, l / 2 );
	delMatrix( intermediateMatrix4, l / 2 );
	delMatrix( intermediateMatrix5, l / 2 );
	delMatrix( intermediateMatrix6, l / 2 );
	delMatrix( intermediateMatrix7, l / 2 );
	/*for (int i = 0; i < l / 2; i++)
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
	}*/
	delete[] Matrix1, Matrix2, Matrix3, Matrix4, Matrix5, Matrix6;
	delete[] semiMatrix1, semiMatrix2, semiMatrix3, semiMatrix4, semiMatrix5, semiMatrix6, semiMatrix7, semiMatrix8, semiMatrix9, semiMatrix10, semiMatrix11, semiMatrix12;
	delete[] intermediateMatrix1, intermediateMatrix2, intermediateMatrix3, intermediateMatrix4, intermediateMatrix5, intermediateMatrix6, intermediateMatrix7;
}
void soutMatrix(int** matrix, size_t x, size_t y) {//Метод для вывода матрицы.
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


void initFillMatrix(int** matrix, size_t x, size_t y) {
	for (int i = 0; i < x; i++)
	{
		matrix[i] = new int[y];
		for (int j = 0; j < y; j++)
			matrix[i][j] = 0;
	}
}


void initMatrix(int** matrix, int x, int y) {//Метод инициализации матрицы.
	//matrix = new int* [x];
	for (int i = 0; i < x; i++)
		matrix[i] = new int[y];
	//return matrix;
}


void copyMatrix(int** matrix1, int** matrix2, size_t x, size_t y, size_t k, size_t l) {//Метод копирования матрицы. Где x y размерность, а k l - смещение.
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			matrix1[i][j] = matrix2[i + k][j + l];
	}
}


int borderMatrix(int** matrix, size_t k, size_t l) {//Метод определяющий границы матрицы
	for (int i = 0; i < k; i++)
	{
		int x = 0;
		for (int j = 0; j < k; j++)
		{
			if (matrix[i][j] != 0)
			{
				x++;
				l = 100;
			}
		}
		if (x == 0 && i < l)
		{
			l = i;
		}
	}
	return l;
}

void delMatrix(int** matrix, size_t k) {//Метод удаления матрицы
	for (int i = 0; i < k; i++)
		delete[] matrix[i];
}