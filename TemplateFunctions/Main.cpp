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

int main() {
	template_test();
	template_test2();

	return 0;
}