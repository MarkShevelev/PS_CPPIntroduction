#include <iostream> //cin cout
#include <cstdlib>  //srand rand
#include <ctime>  //time


void random_array(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 101;
}

void print_array(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

//простой обмен
void swap_elements(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//пр€мой выбор
void select_sort(int arr[], int size) {
	//ищем положение максимума и обмениваем с крайним элементом
	int max, max_idx;
	for (int i = size-1; i > 0; --i) {
		max = arr[i], max_idx = i;
		for (int j = 0; j < i+1; ++j)
			if (arr[j] > max) {
				max = arr[j];
				max_idx = j;
			}
		swap_elements(arr, i, max_idx);
	}
}

//пузырькова€ сортировка
void buble_sort(int arr[], int size) {
	//перва€ подход
	/*bool proceed;
	do {
		proceed = false;
		for (int idx = 0; idx < size-1; ++idx)
			if (arr[idx] > arr[idx + 1]) {
				swap_elements(arr, idx, idx + 1);
				proceed = true;
			}
	} while (proceed);*/

	//наиболее употребительный вид
	bool proceed = true;
	for (int outer = 1; outer < size - 1 && proceed; ++outer) {
		proceed = false;
		for (int idx = 0; idx < size - outer; ++idx)
			if (arr[idx] > arr[idx + 1]) {
				swap_elements(arr, idx, idx + 1);
				proceed = true;
			}
	}
}

//сортировка вставками
void insert_sort(int arr[], int size) {
	for (int outer = size - 1; outer > 0; --outer) {
		for (int idx = outer-1; idx < size - 1 && arr[idx] > arr[idx + 1]; ++idx)
			swap_elements(arr, idx, idx + 1);
	}
}

void sort_test() {
	int const size = 20;
	int arr[20];

	srand(time(NULL));
	random_array(arr, size);
	print_array(arr, size);
	
	if (false) select_sort(arr, size);
	if (false) buble_sort(arr, size);
	if (false) insert_sort(arr, size);
	print_array(arr, size);
}

int main() {
	sort_test();

	return 0;
}