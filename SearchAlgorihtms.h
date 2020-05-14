#pragma once
#include <iostream>
#include <vector>       // std::vector
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

using namespace std;

// Линейный поиск по ключу. Если элемент найден, возвращает его позицию в массиве.
// Если элемент не найден, вернет -1
template <typename T>
int linearSearch(vector<T> arr, const T& item) {
	for (size_t i = 0; i < arr.size(); i++) {
		if (arr[i] == item) {
			return i;
		}
	}
	return -1;
}

// Поиск с сужением зоны (в упорядоченных массивах)
// left, right - границы поиска
template <typename T>
int binarySearch(vector<T> arr, const T& item, const size_t &left, const size_t& right) {
    if (right >= left) {

        size_t mid = left + (right - left) / 2;

        // Если элемент в центре
        if (arr[mid] == item)
            return mid;

        // Элемент левее центра
        if (arr[mid] > item)
            return binarySearch(arr, item, left, mid - 1);

        // Элемент правее центра
        return binarySearch(arr, item, mid + 1, right);
    }
    // Элемент не найден
    return -1;
}

// Распределяющий поиск
template <typename T>
int distributedSearch(vector<T> arr, const T& item) {
    size_t n = arr.size();

    // Минимальное и максимальное значение
    T min = arr[0];
    T max = arr[0];    
    
    // Поиск min, max
    for (size_t i = 1; i < n; i++) {
        T e = arr[i];
        if (e > max) { max = e; }
        if (e < min) { min = e; }
        
    }

    // Создадим инвентированный массив
    vector<T> arrInv;
    arrInv.resize(max - min + 1);

    // Заполнение инвентированного массива    
    for (size_t i = 0; i < n; i++) {
        arrInv[size_t(arr[i] - min)] = i;
    }
    
    int result = -1;
    // Найдем значение в инвентированном массиве, если оно там есть
    if (item >= min && item <= max) result = arrInv[item - min];

    return result;
}

// Вспомогательные функции
//////////////////////////////////////////////////////////////////////////////

// Перемешивает массив (в поиске не используется)
template <typename T>
void shuffleArray(vector<T> &a) {     
    default_random_engine engine;
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(std::begin(a), std::end(a), engine);
}

// Заполняет массив числами линейно
template <typename T>
void fillArray(vector<T>& a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        a.push_back(i);
    }
}

// Вывод массива
template <typename T>
void print(vector<T> const& arr)
{
    for (int i : arr) {
        cout << i << ' ';
    }
}