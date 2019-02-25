#include <iostream>
#include <algorithm>

//�������� - ������ ���������� ����
//��������, ��������� ������� ���������� �������� "Hello Recursion!"
void print_infinite() {
	std::cout << "Hello Recursion!" << std::endl;
	print_infinite();  //�������� ������� print_infinite ������ ���� print_infinite, ��� ���������� �������� � ���������� ����
}

/* ������ ����������
while(true) std::cout << "Hello Recursion!" << std::endl;
*/

//���� �� ����� ������������ ��� �� ������� �����, �� ����� ���������� ��������� ������
void print_number(int num) {
	if (0 == num) return; //���������� 0 ��� - ������ �� ������
	std::cout << "Hello Recursion!" << std::endl; //�������� ���� ���
	print_number(num - 1);//�������� �� ���� ��� ������
}
/* ������ � �������������� �����
while(0 != num) {
	std::cout << "Hello Recursion!" << std::endl;
	--num;
}
*/

void simple_recursion_test() {
	if (false) print_infinite(); //���������� ��������
	if (false) print_number(10); //�������� 10 ���
}

//��������� ��������� ����� ������ ��������� ������ � ����������� ����
//�������� �������� �����
template <typename T>
int binary_search_rec(T arr[], int begin, int end, T key) {
	if (1 > end-begin) return -1;  //���� ��������
	int c = (begin + end) / 2;
	if (key > arr[c]) return binary_search_rec(arr, c + 1, end, key); //��� ��������
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
	std::sort(arr, arr + size); //��� ��������� ������ ���������� ����������
	print_array(arr, 20);

	std::cout << "Please, enter the key value: " << std::flush;
	int key;
	std::cin >> key;
	std::cout << binary_search_rec(arr,0, size,key) << std::endl;
}

//��������� �������� - ��������, ��������� ��������� ������� �������� ����������� �����
//��������� �������� ����� ���� �������������� ������������ � ��������

//��������� �������� ��� ���������� ����� ���������
long long fibonacci_naive_rec(int N) {
	if (1 == N || 2 == N) return 1LL;
	return fibonacci_naive_rec(N - 1) + fibonacci_naive_rec(N - 2); //�� ��������� ��������, ��������� �������� - ��������
}

//�������������� � ��������� ��������
long long fibonacci_tail_rec(int N, long long fibNm1, long long fibNm2) {
	if (1 == N) return fibNm2;
	return fibonacci_tail_rec(N - 1, fibNm1 + fibNm2, fibNm1); //����� ���� � ��������, ������� ����������� �� ������ - �������� ���������
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

