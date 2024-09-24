//14. Переставити стовпці матриці у відповідності до зростання елементів третього рядка.

#include <iostream>
#include <conio.h>
int main()
{
	int n, m, i, j;
	int** mas;
	std::cout << "Input amount of rows (n) and columns (m)" << std::endl;
	std::cin >> n >> m;
	//створюємо динамічний масив
	mas = new int* [n]; //створюємо масив покажчиків
	for (i = 0; i < n; i++)
		mas[i] = new int[m]; //створюємо динамічні строки
	std::cout << "Input " << n << "x" << m << " array elements" << std::endl;
	//заповнюємо масив з клавіатури
	for (i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> mas[i][j];
	// Виведення на экран вихідного масиву
	std::cout << "\nInput array: \n";
	for (i = 0; i < n; i++, std::cout << std::endl)
		for (int j = 0; j < m; j++)
			std::cout << mas[i][j] << "\t";
	// Перевірка на достатню кількість рядків
	if (n < 3 || m < 2) {
		std::cout << "Cannot compare elements on a non-existing row";
	}
	// Сортування стовпців за значеннями третього рядка
	else {
		std::cout << std::endl;
		for (int j = 1; j < m; j++) {
			if (mas[2][j] < mas[2][j - 1]) {
				for (i = 0; i < n; i++) {
					std::cout << "it works\n";
					std::swap(mas[i][j], mas[i][j - 1]);
				}
				j -= 2;
			}
		}
		// Вивід вихідної матриці
		for (i = 0; i < n; i++, std::cout << std::endl)
			for (int j = 0; j < m; j++)
				std::cout << mas[i][j] << "\t";
	}
	// вивільнюємо пам’ять
	for (i = 0; i < n; i++)
		delete[]mas[i];//вивільнюємо строки
	delete[]mas; //вивільнюємо масив покажчиків
	_getch();//затримка екрану
	return 0;
}