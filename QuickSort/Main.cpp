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

	// ����������� ������, ���� ����, ��� �����������
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

//� �������������� �������� ������ ������������� ��������� ��������
//������: ���� ����� �����, ��������� ���������� ����� ���� ����� + � - ����� �������, ����� ���������� �������� �����, ���� ��� ��������
//������� ���������
bool signs_rec(int nums[], int size, char signs[], int pos, int key) {
	if (size == pos) { //���� ���� ������ ������ ��������, �� ���������� ����� - ���� ��������
		int sum = 0;
		for (int i = 0; i != size; ++i)
			sum += '-' == signs[i] ? -nums[i] : nums[i];
		return sum == key;
	}

	signs[pos] = '+'; //������� ��������� �� ����������� ������� +
	if (signs_rec(nums, size, signs, pos + 1, key)) return true; //���� ����� ���������� - �����������

	signs[pos] = '-'; //���� �� ����� � ������, ������� �� ������ -
	if (signs_rec(nums, size, signs, pos + 1, key)) return true;

	return false; //���� ��� �������� �� ���� ����������, ���������� ���������
}

void numbers_and_signs_test() {
	int const size = 10;
	int arr[size];
	srand(43);
	random_array(arr, size);
	print_array(arr, size);

	int key;
	std::cout << "Please, enter the number to construct: ";
	std::cin >> key;

	char signs[size];
	if (signs_rec(arr, size, signs, 0, key)) {
		for (int i = 0; i != size; ++i)
			std::cout << signs[i] << arr[i] << " ";
		std::cout << "= " << key << std::endl;
	}
	else {
		std::cout << "Key is imposible to construct" << std::endl;
	}
}

int main() {
	if (false) quick_sort_test();
	if (true) numbers_and_signs_test();

	return 0;
}