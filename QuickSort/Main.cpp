#include <iostream>

template <typename T>
void swap_elements(T arr[], int i, int j) {
	auto tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

template <typename T>
void quick_sort(T arr[], int begin, int end) {
	auto p = arr[(begin + end) / 2];
	int L = begin, R = end;
	do {
		while (arr[L] < p) ++L;
		while (arr[R] > p) --R;
		if (L <= R) {
			swap_elements(arr, L, R);
			++L;
			--R;
		}
	} while (L <= R);

	// рекурсивные вызовы, если есть, что сортировать
	if (R > begin) quick_sort(arr, begin, R);
	if (end > L) quick_sort(arr, L, end);
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

void quick_sort_test() {
	int const size = 20;
	int arr[size];

	srand(43);
	random_array(arr, size);
	print_array(arr, size);

	quick_sort(arr, 0, size-1);
	print_array(arr, size);
}

int main() {
	if (false) quick_sort_test();

	return 0;
}