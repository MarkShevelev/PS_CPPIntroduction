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

	overload_print_array(i_arr, 5);
	overload_print_array(d_arr, 5);

	template_print_array(i_arr,5);
	template_print_array(d_arr,5);
}

int main() {
	template_test();

	return 0;
}