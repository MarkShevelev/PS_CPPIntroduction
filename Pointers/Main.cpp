#include <iostream>
#include <cstdio>

void address() {
	//� ������ ���������� ���� ������ �����, ��� ��� ����������� � ������ - ����� ������� �� ������
	int i; //���������� ���������� - ���������� ����� � ������� � ������
	//�������� & ��������� ������ ������ �������������� ������
	std::cout << &i << std::endl; //������������� ����/����� C++ ���������� ����� �� ����� �� ����
	printf("%p\n", &i); //����� ������ � ����� C �������������� ����������������� %p

	//����� - ��� ������ ����� �����, ����� ������ � ����������� ������
	size_t address_as_num = (size_t)&i;
	std::cout << address_as_num << std::endl;
	//size_t - ����������� ���������� ��������� ���� ������, ������� ��������� ��������� � ���� ����� ����� �����

	//��� ������ �������� ��������� ����� ���������� ��������, �.�. ������������ ������� ���� ������������ ������������� ���������� � ����� ��������� �� � ��������� ����� ����������� ������
}

void pointer() {
	//��������� - ����������� ��� ����������, ������� ������ ������
	int *ptr; //����������, ������� �������� ����� ����������� �������, ��� ����� ������� �����

	int variable; //������� ������������� ����������
	ptr = &variable; //& ���� �����, = ��������� ����� � ������, ��������� � ptr

	std::cout << "addres = " << &variable << std::endl;
	std::cout << "pointer = " << ptr << std::endl;

	//��������� ��������, ������� �������� ��� ���������, �� ���������� ��� ������ ���������� - �������������
	*ptr = 7; //* �������� ��������� � ������ �� �����, = ����� ������ �� � ptr, � � variable
	std::cout << "pointer = " << ptr << std::endl;
	std::cout << "variable = " << variable << std::endl;
}

//��������� - ��������� ���������� ��� ��������������� ������� � ������, ����������� �������� ������ � ������, ������� �� ����������� ������� ��������� ����
void pointer_inderect(int *a_ptr) {
	//��������� ����, ��� ������� pointer_inderect ��������� � �������� ��������� ���������, ��� ����� ������ ������ � ������, ������� �� ���� �������� � �������
	*a_ptr = 3;
}

//��������� ������ � ���������� ���� �� �����
void variable_direct(int a) {
	a = 3;
}

void pointer_inderect_test() {
	int a; //���������� a ���������� ������ ������ �������
	a = 5;
	std::cout << a << std::endl;

	variable_direct(a);
	std::cout << a << std::endl; //�������� a �� ����������

	pointer_inderect(&a);
	std::cout << a << std::endl; //�.�. � ������� ��������� �����, �� ������� ����� �������� �������� � ������ �� ������
}

//�������, ������������ ��� �������� ������ ����, ��������� ���������
template <typename T>
void swap_any(T *lha, T *rha) {
	auto tmp = *lha;
	*lha = *rha;
	*rha = tmp;
}

template <typename T>
void print_arithmetic(T *ptr) {
	std::cout << ptr << " " << ptr + 1 << " " << ptr - 1 << std::endl;
}

void pointer_arithmetic() {
	//��������� �������� ����������� ���������� ��� �������� � ����� ������
	short sh; short *sh_ptr = &sh;
	int i; int *i_ptr = &i;
	double d; double *d_ptr = &d;

	std::cout << "\nshort:\n"; print_arithmetic(sh_ptr);
	std::cout << "\nint:\n"; print_arithmetic(i_ptr);
	std::cout << "\ndouble:\n"; print_arithmetic(d_ptr);
}

int main() {
	if (false) address();
	if (false) pointer();
	if (false)  pointer_inderect_test();
	if (false) pointer_arithmetic();

	return 0;
}