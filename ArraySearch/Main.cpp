/**
 * ����� � �������
 * */

#include <iostream>
#include <algorithm> //sort
#include <cstdlib>

//�������� ����� ��� ������� �������
//������� ���� �������� �������� � ������� � ���������� ��� ������,
//���� ������� �� ������, ���������� ������ �� �������� �������
int my_linear_search(int key, int arr[], int size) {
	int i = 0;
	for (; i < size; ++i)
		if (arr[i] == key) break;
	return i;
}

//�������� ����� ��������� �������� ������� ����������� �������, ���� ������ ������� ����������� �������
int my_binary_search(int key, int arr[], int size) {
	int L = 0, R = size;
	while (L < R) {
		int c = (L + R) / 2;
		if (arr[c] > key) { R = c; continue; }
		if (arr[c] < key) { L = c + 1; continue; }
		return c;
	}
	return size;
}

void random_array(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 101;
}

void print_array(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void search_test() {
	int const size = 20;
	int arr[size];

	srand(40);
	random_array(arr, size);
	std::sort(arr, arr + size); //��� ��������� ������ ���������� ����������
	print_array(arr, 20);

	std::cout << "Please, enter the key value: " << std::flush;
	int key;
	std::cin >> key;
	std::cout << my_linear_search(key, arr, size) << std::endl;
	std::cout << my_binary_search(key, arr, size) << std::endl;
}

int main() {
	search_test();
	return 0;
}