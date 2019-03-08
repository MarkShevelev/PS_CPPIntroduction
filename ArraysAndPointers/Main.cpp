#include <iostream>

//������� ����� �������� � ������������ ������, � ���� ������ ��� ������������ ���������
//����� ����� �� ������?
void array_address_test() {
	int * dynamo_array = new int[10];
	std::cout << dynamo_array << std::endl;
	std::cout << &(dynamo_array[0]) << std::endl; //���������, ���������� � ������� new, �������� ����� ������� �������� �������
	delete[] dynamo_array;
}

//������ ��������� �������
void array_elements_addresses() {
	int auto_array[10];
	int * dynamo_array = new int[10];

	std::cout << &(auto_array[0]) << " " << &(dynamo_array[0]) << '\n';
	std::cout << &(auto_array[1]) << " " << &(dynamo_array[1]) << '\n';
	std::cout << &(auto_array[2]) << " " << &(dynamo_array[2]) << '\n';
	//�������� �����, ��� ������ ��������� ���� ������� ������ � ����������� ����� �� 4, �.�. �� ���-�� ���� � ����

	delete[] dynamo_array;//���������� ����������� ������ ���������� ����������, ������ auto_array ����� ����� �������������, ��� ������ ���������� ���� ����
}

//������ � ��������� ������� �� �������
void array_elements_access_via_pointers() {
	int auto_array[5] = {45,44,43,42,41};
	int * dynamo_array = new int[5] { -45,-44,-43,-42,-41 };

	int * first_element_ptr = &auto_array[0]; //��������� ���������� �����, ��� & ���������� ���������

	//���������� � ������ ������� �������� ��� �������� ����� �� �������, ������� �������� ��������� � ���������� ���
	//����� �������, �� �������� �� ������ �������
	std::cout << "via pointer: " << *first_element_ptr << " " << *(first_element_ptr + 1) << std::endl;
	std::cout << "via index:   " << auto_array[0] << " " << auto_array[1] << std::endl;

	//���������� ����� � ��� ������������ ������
	first_element_ptr = dynamo_array;
	std::cout << "via pointer: " << *first_element_ptr << " " << *(first_element_ptr + 1) << std::endl;
	std::cout << "via index:   " << dynamo_array[0] << " " << dynamo_array[1] << std::endl;
	
	delete[] dynamo_array;
}

//���� ����� ������� �������� �������, �� ����� �������� ������ �� ������ �������� ����������� ���������� ����������
void array_elements_access_via_arithmetic() {
	int auto_array[5] = { 45,44,43,42,41 };
	int * dynamo_array = new int[5]{ -45,-44,-43,-42,-41 };

	int * first_element_auto = &(auto_array[0]);
	int * first_element_dynamo = &(dynamo_array[0]);

	//���� �� ����� ������� � ������� � �������� X, �� ���������� ��������� � ��������� �� ������ ������� ��� ��������
	int offset;
	std::cout << "Please, enter the index from 0 to 4: " << std::flush;
	std::cin >> offset;
	std::cout << *(first_element_auto + offset) << " " << *(first_element_dynamo + offset) << std::endl; //������ �����������! �������� * ������������ ��������!

	delete[] dynamo_array;
}

//���������� ������ ��� ����������� ��������
void square_brackets() {
	//���������� ������ ���� ��������� ����������� *(ptr+x) <=> ptr[x]
	int auto_array[5] = { 45,44,43,42,41 };
	int * dynamo_array = new int[5]{ -45,-44,-43,-42,-41 };

	int * first_element_auto = &(auto_array[0]);
	int * first_element_dynamo = &(dynamo_array[0]);

	std::cout << auto_array[2] << " <=> " << *(first_element_auto + 2) << std::endl;
	std::cout << dynamo_array[2] << " <=> " << *(first_element_dynamo + 2) << std::endl;

	//�� �������� ���� ��������� ����� �� ��������
	std::cout << 2[auto_array] << " <=> " << *(2 + first_element_auto) << std::endl;
	std::cout << 2[dynamo_array] << " <=> " << *(2 + first_element_dynamo) << std::endl;

	delete[] dynamo_array;
}

//��� ������������� ������������ ������ �� ����� �������� ����� �� ������ �������, ������� �������������� �������� ������ �� �����
//���� ������ �������������� �� ����������� ���������� �����
void array_to_pointer() {
	int auto_array[5] = { 45,44,43,42,41 };
	int * dynamo_array = new int[5]{ -45,-44,-43,-42,-41 };

	int * dynamo_first = dynamo_array;
	int * auto_first = auto_array;

	std::cout << *dynamo_first << " " << *auto_first << std::endl;

	delete[] dynamo_array;
}

//������������� ���������� ��� ������ ������� � �����
void array_walk_via_pointer() {
	int auto_array[5] = { 45,44,43,42,41 };
	int * dynamo_array = new int[5]{ -45,-44,-43,-42,-41 };

	//auto array
	std::cout << " ";
	for (auto begin = auto_array, end = auto_array + 5; begin != end; ++begin)
		std::cout << *begin << "  ";
	std::cout << std::endl;

	//dynamo array
	for (auto begin = dynamo_array, end = dynamo_array + 5; begin != end; ++begin)
		std::cout << *begin << " ";
	std::cout << std::endl;
}

//������������� ���������� � ���������� �������

//�������, ����������� �������� ����� �������
template <typename T>
void print_range(T const * const begin, T const  * const end) {
	for (T const * it = begin; it != end; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void print_range_test() {
	int const auto_array[] = { 1,2,3,4,5,6,7,8,10 };
	int const *dynamo_array = new int[9] {-1, -2, -3, -4, -5, -6, -7, -8, -10};

	print_range(auto_array + 2, auto_array + 7);
	print_range(dynamo_array + 2, dynamo_array + 7);

	delete[] dynamo_array;
}

int main() {
	if (false) array_address_test();
	if (false) array_elements_addresses();
	if (false) array_elements_access_via_pointers();
	if (false) array_elements_access_via_arithmetic();
	if (false) square_brackets();
	if (false) array_to_pointer(); 
	if (false) array_walk_via_pointer();
	if (false) print_range_test();
}