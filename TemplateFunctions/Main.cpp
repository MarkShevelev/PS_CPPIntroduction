/**
 * ������� �������
 * */

#include <iostream>

//���������� ��� �������, ������� �������� �� ������ ���������� ��������
void overload_print_array(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void overload_print_array(double arr[], int size) {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

//��� ������� ���� ������ ���� � �� ��
//�� ����������� �������� ����, ��� �������� � ������������� ����������� ���
//������� ������� ��������� �� ����� �������������

template <typename T> //������ �������������� ����������� ���������� �����������,
//��� ������� ���� - ������, � ������������� T �������� ��� ����
void template_print_array(T arr[], int size) {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void template_test() {
	int i_arr[5] = { 1,2,3,4,5 };
	double d_arr[5] = { 1.1,2.2,3.3,4.4,5.5 };

	overload_print_array(i_arr, 5); //����� ���������� ������� ������������� �������
	overload_print_array(d_arr, 5);

	template_print_array(i_arr,5); //����� ���������� ��������� �������
	template_print_array(d_arr,5);
}

//������ ������� (��������� �������) �� �������� ��������� ��������
//������ ������� - ��� ����������� �������������� �����������,
//�� ������ ������� ���������� ������ ��������� �������.
//�� ���� ������� ��������� ������� ������ ������ ���� �������� � ���� ��������� ����
//� �� ����� ���� �������������� ��������������.
//�� ��� �� ������� ��������� ������� ������ ��������.

//��������� ���������� ����� ���� �� ������ ��� ����, �� � ��������

template <int Size>
int sumof(int arr[]) {
	int sum = 0;
	for (int i = 0; i < Size; ++i)
		sum += arr[i];
	return sum;
}

//������� ����� ����� ��������� ��������� ����������
template <int Doubles, typename T>
T doubles(T in) {
	for (int i = 1; i < Doubles; ++i)
		in += in;
	return in;
}

void template_test2() {
	int arr[5] = { 1,2,3,4,5 };
	std::cout << sumof<5>(arr) << std::endl; //����� ���������� �� ����� ���������� �������� ���������, ��� �������� ������� ������� ���� � ������� �������

	double d = 1.56;
	std::cout << doubles<5>(d) << std::endl;

	int i = -3;
	std::cout << doubles<3>(i) << std::endl;
}

//����������� ������ �� ������ ������� � ������, �������� ������ � ����� int
void copy_array(int dst[], int src[], int size) {
	for (int i = 0; i < size; ++i)
		dst[i] = src[i];
}

//��������� ������� �������� � ����� ����� ������!
template <typename T>
void tpl_copy_array(T dst[], T src[], int size) {
	for (int i = 0; i < size; ++i)
		dst[i] = src[i];
}

//������ ��� ��������, ������� ���������� ��������� �������, ������ ����������
//�� �� ����� ������� ����� ��� T1 ��� T2 �������� "����"
template <typename T1, typename T2>
/*?*/auto tpl_sum(T1 a, T2 b) { //����� �� ����������� ������ ����� ���� �������� ����� auto
	return a + b;
}

//auto ��������, ��� ������������ ��� ����� �������� ������������

//�������� ����� auto ����� ������������ � � �����������
void tempate_test3() {
	auto variable = 3; //���������� �������� ��� int
	auto another_variable = 3.1; //���������� �������� ��� double
	auto third_variable = 3.1f; //���������� �������� ��� float
	auto string = "Hello";  //���������� �������� ��� ������ �������� char[]

	std::cout
		<< variable << " "
		<< another_variable << " "
		<< third_variable << " "
		<< string << " "
		<< std::endl;
}

//�������, ������� ��������� �������� � ������� ��� ������ ���� ������
template <typename T>
auto tpl_array_sum(T arr[], int size) { //������������ ��� ��������� ����������
	auto sum = arr[0]; //����� ������ ����������, ��� ������� ��������� ����������, ������ �� ���� �������
	for (int i = 1; i < size; ++i)
		sum += arr[i];
	return sum;
}

//���� ��������� ������������� ���������� ��� ������������� �������� �� ������ ��������� �� ��������� �����,
//����������� �������� ����� decltype � ��������� ������������ ���
template <typename T1, typename T2, typename T3>
auto dumb_sum(T1 a, T2 b, T3 c) -> decltype(a+b) { //������ ���������� ������� ���, �������� �� ��������� a+b
	return a + b + c;
}

void template_test4() {
	int a = 3, b = 4;
	double da = 3.1, db = 4.1;

	std::cout << dumb_sum(a, b, db) << std::endl; //����� �����
	std::cout << dumb_sum(a, db, b) << std::endl; //������� �����
}

int main() {
	template_test();
	template_test2();
	tempate_test3();
	template_test4();

	return 0;
}