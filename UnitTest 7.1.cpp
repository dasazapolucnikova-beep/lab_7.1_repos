#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 7.1/Project 7.1.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71
{
	TEST_CLASS(UnitTest71)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// Створення тестової матриці 2х2
			const int rowCount = 2;
			const int colCount = 2;

			int** Q = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				Q[i] = new int[colCount];
			}

			// Заповнення тестовими даними:
			// Q[0][0] = -5 (задовольняє: від'ємне)
			// Q[0][1] = 4  (НЕ задовольняє: додатне парне)
			// Q[1][0] = 3  (задовольняє: додатне непарне)
			// Q[1][1] = 2  (НЕ задовольняє: додатне парне)
			Q[0][0] = -5;
			Q[0][1] = 4;
			Q[1][0] = 3;
			Q[1][1] = 2;

			int S = 0;
			int k = 0;

			// Виклик функції Calc
			Calc(Q, rowCount, colCount, S, k);

			// Перевірка обчисленої суми (-5 + 3 = -2)
			Assert::AreEqual(-2, S);

			// Перевірка кількості знайдених елементів (2 елементи: -5 і 3)
			Assert::AreEqual(2, k);

			// Перевірка обнулення елементів
			Assert::AreEqual(0, Q[0][0]); // задовольняв критерію -> обнулено
			Assert::AreEqual(4, Q[0][1]); // НЕ задовольняв -> залишився 4
			Assert::AreEqual(0, Q[1][0]); // задовольняв критерію -> обнулено
			Assert::AreEqual(2, Q[1][1]); // НЕ задовольняв -> залишився 2

			// Звільнення пам'яті
			for (int i = 0; i < rowCount; i++) {
				delete[] Q[i];
			}
			delete[] Q;
		}
	};
}