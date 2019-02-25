#include <iostream>
#include <algorithm>

//рекурсия - способ повторения кода
//например, следующая функция бесконечно печатает "Hello Recursion!"
void print_infinite() {
	std::cout << "Hello Recursion!" << std::endl;
	print_infinite();  //вызываем функцию print_infinite внутри кода print_infinite, что фактически приводит к повторению кода
}

/* аналог итерациями
while(true) std::cout << "Hello Recursion!" << std::endl;
*/

//если мы хотим организовать код на подобие цикла, то важно ограничить повторные вызовы
void print_number(int num) {
	if (0 == num) return; //напечатать 0 раз - ничего не делать
	std::cout << "Hello Recursion!" << std::endl; //печатаем один раз
	print_number(num - 1);//печатаем на один раз меньше
}
/* аналог с использованием цикла
while(0 != num) {
	std::cout << "Hello Recursion!" << std::endl;
	--num;
}
*/

void simple_recursion_test() {
	if (false) print_infinite(); //бесконечно печатает
	if (false) print_number(10); //печатает 10 раз
}

//некоторые алгоритмы очень удобно описывать именно в рекурсивном виде
//например двоичный поиск
template <typename T>
int binary_search_rec(T arr[], int begin, int end, T key) {
	if (1 > end-begin) return -1;  //база рекурсии
	int c = (begin + end) / 2;
	if (key > arr[c]) return binary_search_rec(arr, c + 1, end, key); //шаг рекурсии
	if (key < arr[c]) return binary_search_rec(arr, begin, c, key);
	return c;
}

void random_array(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 101;
}

template <typename T>
void print_array(T arr[], int size) {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void search_test() {
	int const size = 20;
	int arr[size];

	srand(40);
	random_array(arr, size);
	std::sort(arr, arr + size); //для бинарного поиска необходима сортировка
	print_array(arr, 20);

	std::cout << "Please, enter the key value: " << std::flush;
	int key;
	std::cin >> key;
	std::cout << binary_search_rec(arr,0, size,key) << std::endl;
}

//Хвостовая рекурсия - рекурсия, последним действием которой является рекурсивный вызов
//хвостовая рекурсия может быть оптимизирована компилятором в итерации

//неудачная рекурсия для вычисления чисел Фибоначчи
long long fibonacci_naive_rec(int N) {
	if (1 == N || 2 == N) return 1LL;
	return fibonacci_naive_rec(N - 1) + fibonacci_naive_rec(N - 2); //не хвостовая рекурсия, последняя операция - сложение
}

//преобразование в хвостовую рекурсию
long long fibonacci_tail_rec(int N, long long fibNm1, long long fibNm2) {
	if (1 == N) return fibNm2;
	return fibonacci_tail_rec(N - 1, fibNm1 + fibNm2, fibNm1); //сумма ушла в параметр, который вычисляется до вызова - рекурсия хвостовая
}

void fibonacci_test() {
	std::cout << "Please, enter the Fibonacci number count: ";
	int N;
	std::cin >> N;

	std::cout << "Please, choose\n\t1) naive rec\n\t2) tail rec\n";
	int choice;
	std::cin >> choice;

	switch (choice) {
	case 1:
		std::cout << fibonacci_naive_rec(N) << std::endl;
		break;
	case 2:
		std::cout << fibonacci_tail_rec(N,1LL,1LL) << std::endl;
	}
}

int main() {
	if (false) simple_recursion_test();
	if (false) search_test();
	if (false) fibonacci_test();
}

