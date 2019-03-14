#include <iostream>
#include <cstdlib>

//��������� �� ���������, ��� ���?
void pointer_to_pointer() {
	int a = -23; //���������� ���� int
	int *ptr = &a; //���������� ��� �������� ������ �� ���������� ���� int
	//��������� - ��� ���� ����������, �� ����� �������, ������������� � ���� ���� ���� �����!
	std::cout << &ptr << std::endl;

	//����� ��������� ���� ����� ��������� � ����������
	int * * ptr_ptr = &ptr; //���������� ���������� ������� ���, ��� ptr_ptr - ��� ����������, ������� �������� ����������, �������� ����� �� ���������� � ����� int *, �.�. ������ �����

	//����� �������� ������, ��� ���������� ������������ ��������� ������
	std::cout << ptr_ptr << std::endl; //������� �������� ���������� ptr_ptr - ����� ���������� ptr
	std::cout << *ptr_ptr << std::endl; //������� �������� ���������� ptr - ����� ���������� a
	std::cout << **ptr_ptr << std::endl; //������� �������� ���������� a
}

//������ ����������
void array_of_pointers() {
	//���������� ������ - ������ ����������
	int * arr[3]; //�������������� ������ �� ��� �������
	int a, b, c;
	arr[0] = &a;
	arr[1] = &b;
	arr[2] = &c;

	//����������� �������� ���������� ��������
	for (size_t pos = 0; pos != 3; ++pos)
		*arr[pos] = 2 * pos;

	//������ �������� ���������� ��������
	for (size_t pos = 0; pos != 3; ++pos)
		std::cout << *arr[pos] << std::endl;
}

//������ ���������� � ������������ ������
void dynamo_array_of_pointers() {
	//�������� ����� new ���������� ��������� � ����� ��������� ��� ������
	int* *dynamo_ptr_array = new (std::nothrow) int*[3]; //�������� ������ �� ��� ���������� � ������������ ������
	//�������� �������� �� ��� ������ � ���������� dynamo_ptr_array

	int a, b, c;
	*(dynamo_ptr_array + 0) = &a;//���� ������������� �������� ��� � ������ ������, ��� �������� �����, �.�. ������ ���� int*
	*(dynamo_ptr_array + 1) = &b;
	*(dynamo_ptr_array + 2) = &c;

	for (size_t pos = 0; pos != 3; ++pos)
		**(dynamo_ptr_array + pos) = 2 * pos;//������� ������������� ��� ������ � ������

	//����������� ������ � ���������� ������ �� ������� *(ptr + x) => ptr[x]
	//**(dynamo_ptr_array+pos) => *(*(dynamo_ptr_array+pos)+0) => *(dynamo_ptr_array[pos]+0) => dynamo_ptr_array[pos][0]
	for (size_t pos = 0; pos != 3; ++pos)
		std::cout << dynamo_ptr_array[pos][0] << std::endl;

	delete[] dynamo_ptr_array;
}

//��������� ������������ ������
void twodimensional_dynamo_array() {
	//��������� ������ - ��� ����� �� ���������� �����, ������ �� ������� �������� ��������
	size_t const row_size = 3;
	int *row1 = new (std::nothrow) int[row_size];
	int *row2 = new (std::nothrow) int[row_size];
	int *row3 = new (std::nothrow) int[row_size];

	//����� ��������� ������ � �����, �������� ������ � ��������� �������
	int * * rows = new (std::nothrow) int*[3];
	rows[0] = row1; rows[1] = row2; rows[2] = row3;

	//����� ��������� ����� ������ ������ ���������� ���������� � ���������� �����
	for (size_t row = 0; row != 3; ++row)
		for (size_t pos = 0; pos != row_size; ++pos)
			rows[row][pos] = 1; //�������� �������� �� ������� ��������

	for (size_t row = 0; row != 3; ++row) {
		for (size_t pos = 0; pos != row_size; ++pos)
			std::cout << rows[row][pos] << std::endl;
		std::cout << std::endl;
	}

	//�������� ������
	delete[] rows;
	delete[] row1;
	delete[] row2;
	delete[] row3;
}

//��������� ���������� ������� ������������ ��������
void anysize_twodimensional_dynamo_array() {
	int user_rows, user_cols;
	std::cout << "Please, enter the field dimensions x and y: ";
	std::cin >> user_cols >> user_rows;

	//������� ������ ������, ��� ����� ������� ������
	char * * field = new (std::nothrow) char*[user_rows];
	//������ �������� ���-�� �����
	for (int row_count = 0; row_count != user_rows; ++row_count)
		field[row_count] = new (std::nothrow) char[user_cols]; //������ ��� ������� �� ��������� ���� char

	//��������� ����������
	for (int row_count = 0; row_count != user_rows; ++row_count)
		for (int col_count = 0; col_count != user_cols; ++col_count)
			field[row_count][col_count] = 'a' + (row_count*user_cols + col_count) % 13;

	//�������� ��������
	for (int row_count = 0; row_count != user_rows; ++row_count) {
		for (int col_count = 0; col_count != user_cols; ++col_count)
			std::cout << field[row_count][col_count] << " ";
		std::cout << std::endl;
	}

	//�������� ������
	//������� ������ ��� � �����������
	for (int row_count = 0; row_count != user_rows; ++row_count)
		delete[] field[row_count];
	//����� ������, �������� ������
	delete[] field;
}

//������� ���������� �������
void index_array() {
	//������, � ������� �������� ������ ����� - ���������� ���������
	//��-�� ����, ��� ������������� ������ ��� ������������ ������ new ����� �������� � ���������� ������������� ������, �������� ��� ������ ��������� � ����� �������
	int user_rows, user_cols;
	std::cout << "Please, enter the field dimensions x and y: ";
	std::cin >> user_cols >> user_rows;

	char *field_data = new (std::nothrow) char[user_cols*user_rows];
	//������ � field ������ ��������� ���������� ������ ������ :(
	//�� ����� ������� ����������� ������, � �������� ���������� ������ ������ ��������! :)
	char * * field = new (std::nothrow) char*[user_rows];
	//������ ����� ���� ������, ��� ��� �� �������� ������ ������� ������ ��������� ������� field_data
	for (int row_count = 0; row_count != user_rows; ++row_count)
		field[row_count] = field_data + row_count * user_cols;

	//��� ���������� ������� �� ����� �������� ������� � ������
	for (size_t pos = 0; pos != user_cols * user_rows; ++pos)
		field_data[pos] = 'a' + pos % 13;

	//��� ������ �� ����� ��������������� ��������� ��������
	for (int row_count = 0; row_count != user_rows; ++row_count) {
		for (int col_count = 0; col_count != user_cols; ++col_count)
			std::cout << field[row_count][col_count] << " ";
		std::cout << std::endl;
	}

	//�������� ������ ���������� ����� �������
	delete[] field;
	delete[] field_data;
}

//������������� ���������� ������� � �������
//�������� �������� �� ��� ������ - int * * - arr2D �������� ��������, �������� ������ �� ������
int diagonal_sum(int * * arr2D, size_t rows, size_t cols) {
	int sum = 0;
	for (size_t pos = 0; pos < rows && pos < cols; ++pos)
		sum += arr2D[pos][pos];
	return sum;
}

//�������� �������
void diagonal_sum_test() {
	int user_rows, user_cols;
	std::cout << "Please, enter the field dimensions x and y: ";
	std::cin >> user_cols >> user_rows;

	int * * index = new (std::nothrow) int*[user_rows];
	for (size_t row = 0; row != user_rows; ++row)
		index[row] = new (std::nothrow) int[user_cols];

	//��������� ������ ���������� ����������
	srand(56);
	for (size_t row = 0; row != user_rows; ++row)
		for (size_t col = 0; col != user_cols; ++col)
			index[row][col] = rand() % 2;

	//������� �� ������
	for (size_t row = 0; row != user_rows; ++row) {
		for (size_t col = 0; col != user_cols; ++col)
			 std::cout << index[row][col] << " ";
		std::cout << std::endl;
	}

	std::cout << "Diagonal sum: " << diagonal_sum(index, user_rows, user_cols) << std::endl;

	//����������� ������
	for (size_t row = 0; row != user_rows; ++row)
		delete[] index[row];
	delete[] index;
}

//�������������� ��������� ������
void auto_twodimensional_array() {
	int auto_arr2D[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	//int * * ptr = auto_arr2D; //�������������� ����� ����������!
	int * ptr = auto_arr2D[0]; //������ �������������� ���� � ��������� �� ������ ������� ��������

	//�������� ��������� ������
	int * * index = new (std::nothrow) int*[3];
	for (size_t pos = 0; pos != 3; ++pos)
		index[pos] = auto_arr2D[pos]; //�� ��������� ������ ����� � ��������� �������

	//������� �� ������
	for (size_t row = 0; row != 3; ++row) {
		for (size_t col = 0; col != 3; ++col)
			std::cout << index[row][col] << " ";
		std::cout << std::endl;
	}

	//��������� ��������� ������, �� ����� �������� ������ ��������������� ������� � �������
	std::cout << "Diagonal sum: " << diagonal_sum(index, 3, 3) << std::endl;

	delete[] index;
}

int main() {
	if (false) pointer_to_pointer();
	if (false) array_of_pointers();
	if (false) dynamo_array_of_pointers();
	if (false) anysize_twodimensional_dynamo_array();
	if (false) index_array();
	if (false) diagonal_sum_test();
	if (false) auto_twodimensional_array(); 

	return 0;
}