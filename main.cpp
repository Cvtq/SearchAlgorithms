#include <iostream>
#include <vector>
#include <time.h>
#include "SearchAlgorihtms.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");	
	const size_t n = 10;

	//////////////////////////////////////////////////////////////
	{
		vector<int>	a;
		fillArray(a, n);
		shuffleArray(a);

		cout << "Массив: ";
		print(a);
		cout << endl;

		srand(std::chrono::system_clock::now().time_since_epoch().count());
		size_t pos = rand() % 10;
		int e = a[pos];
		cout << "Элемет для поиска: " << e << "; в массиве под номером " << pos << endl;

		auto t_start = std::chrono::high_resolution_clock::now();		
		int index = linearSearch(a, e);
		auto t_end = std::chrono::high_resolution_clock::now();		
		size_t time = std::chrono::duration_cast<chrono::nanoseconds>(t_end - t_start).count();
		
		cout << "Линейный поиск: " << index << " Время: " << time << " наносекунд" << endl;
		cout << endl;
	}
	
	//////////////////////////////////////////////////////////////
	{
		vector<int>	b;

		// Заполнение массива последовательностью чисел
		fillArray(b, n);		

		cout << "Массив: ";
		print(b);
		cout << endl;
		
		srand(std::chrono::system_clock::now().time_since_epoch().count());
		size_t pos = rand() % 10;
		int e = b[pos];
		cout << "Элемет для поиска: " << e << "; в массиве под номером " << pos << endl;
		
		auto t_start = std::chrono::high_resolution_clock::now();
		int index = binarySearch(b, e, 0, n - 1);
		auto t_end = std::chrono::high_resolution_clock::now();
		size_t time = std::chrono::duration_cast<chrono::nanoseconds>(t_end - t_start).count();
		cout << "Поиск с сужение зоны: " << index << " Время: " << time << " наносекунд" << endl;
		cout << endl;
	}
	//////////////////////////////////////////////////////////////	
	{
		vector<int>	c;
		fillArray(c, n);
		shuffleArray(c);

		cout << "Массив: ";
		print(c);
		cout << endl;

		srand(std::chrono::system_clock::now().time_since_epoch().count());
		size_t pos = rand() % 10;
		int e = c[pos];
		cout << "Элемет для поиска: " << e << "; в массиве под номером " << pos << endl;

		auto t_start = std::chrono::high_resolution_clock::now();
		int index = distributedSearch(c, e);
		auto t_end = std::chrono::high_resolution_clock::now();
		size_t time = std::chrono::duration_cast<chrono::nanoseconds>(t_end - t_start).count();

		cout << "Распределяющий поиск: " << index << " Время: " << time << " наносекунд" << endl;
		cout << endl;
	}
	//////////////////////////////////////////////////////////////	
}