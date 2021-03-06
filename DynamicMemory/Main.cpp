#include <iostream>
#include <limits>

//����������� �� �������� ��� ����������� ��������� ������ �����, ��������� �������������� ����������
//� ��������� ��������� ����� �������� ������ �� ���� ������ ���������
//����� ������� ���������� - ������������ ��������� ������

//� ����� C++ ��� ������������� ��������� ������ ������������ �������� ����� new
void new_test() {
	//�������� ����� new ���������, ��� ���������� �������� ������ �����������, �.�. �� �� �����, ��� �������� �������������� ����������
	int *i_ptr = new (std::nothrow) int; //new - ���������, ��� ���������� ��������� �� ��������� �����, ������� ������������� ���� ���� ������, ������� ������ ����� ��������� ����� new

	*i_ptr = 3; //������� � �������, ���������� �����������, �� ���������� ���������, ������� ��������� ����� ������� �������������� ���������� ������

	std::cout << i_ptr << " " << *i_ptr << std::endl;

	//��������� new ��������� ���������������� ������ ��� ��������� ������
	int *i_init_ptr = new (std::nothrow) int(5);
	std::cout << *i_init_ptr << std::endl;

	//������������ ������ ����� �������� ���� ����, � ������� ��� ���������, �������������� - ���
	int *i_dynamo_ptr, *i_auto_ptr;
	{
		int i_auto = 3;
		int *i_dynamo = new (std::nothrow) int(5);
		i_auto_ptr = &i_auto;     //�� �������������� ���������� ���������� ����� �����
		i_dynamo_ptr = i_dynamo;  //i_dynamo - ��� ��� �����!
	}

	//std::cout << *i_auto_ptr << std::endl; //��������˨���� ���������!!!
	std::cout << *i_dynamo_ptr << std::endl; //�� ������

	//�.�. ���������� �� ����� ����������, ����� ������ ������ ���� �����������, ������� ������� ��� ��� ����
	//��� ����� ������������ �������� ����� delete
	delete i_dynamo_ptr; //���������� ������ �������
	delete i_init_ptr;
	delete i_ptr;
}

//��������� ����, ��� ������������ ������ �� ����������� ��������� ��������, ��� ����� �������� �������!
int *dynamic_int(int original) {
	int *i_dynamo_copy = new (std::nothrow) int(original);
	return i_dynamo_copy;
}

void new_function_test() {
	int a = 3;
	int *a_copy_ptr = dynamic_int(a);
	std::cout << *a_copy_ptr << std::endl; //�� ������

	//�� �������� ���������� ������ �������
	delete a_copy_ptr;
}

//�������� ����������� ����� ������ �� ������ ��� ���� �������, �� � ��� ������
//��� ����� ������������ new � ����������� ��������
void new_array_test() {
	int user_input;
	std::cout << "How many bytes do you want to allocate?" << std::endl;
	std::cin >> user_input;

	if (user_input < 0) {
		std::cout << "Can't allocate a negative amount of bytes..." << std::endl;
		return;
	}

	unsigned char *user_bytes = new (std::nothrow) unsigned char[user_input];
	if (nullptr == user_bytes)
		std::cout << "Can't allocate " << user_input << " bytes" << std::endl;
	else
		std::cout << "Allocation successfull!" << std::endl;

	delete[] user_bytes; //��� ��, ��� � � ������ � ����� ���������, ������ ��� ������ ����� �����������
	//������ ������� ������������ delete[]
}

//�������� ������ � ������������ ������ ����� ��� ������ ���� ������
void new_array_types() {
	int user_input; //���������� ��������� �������!

	std::cout << "How many elements do you want to allocate?" << std::endl;
	std::cin >> user_input;

	if (user_input < 0) {
		std::cout << "Can't allocate a negative amount..." << std::endl;
		return;
	}

	int *dynamo_array = new (std::nothrow) int[user_input];//����� �������� user_input ����� ���� int, 4*user_input ����
	if (nullptr == dynamo_array) {
		std::cout << "Can't allocate " << user_input << " elements of type int" << std::endl;
		return;
	}

	std::cout << user_input << " elements of type int have been allocated\nThe size of data is " << user_input * sizeof(int) << std::endl;

	delete[] dynamo_array;
}

//��������� � ��������������
void new_with_init() {
	//������������� �������� ��� ���������� ���-�� ���������
	int user_input;
	std::cin >> user_input;
	int *i_ptr = new (std::nothrow) int[user_input] {1, 2, 3, 4, 5}; //������ ���� ��������� ����� ���������������� �������
	for (size_t count = 0; count != 5; ++count)
		std::cout << i_ptr[count] << " ";
	std::cout << std::endl;

	delete[] i_ptr;

	//����� ���������������� ������ ���� ������
	i_ptr = new (std::nothrow) int[2*user_input] {0};

	for (size_t count = 0, end = 2*(size_t)user_input; count != end; ++count)
		std::cout << i_ptr[count] << " ";
	std::cout << std::endl;

	delete[] i_ptr;
}

//������ ������
void memory_leak() {
	//������ ������ - ��������, ����� ������ ���� ������, �� �� ���� ����������, � ����������� ��� � ������������ �������

	size_t counter = 0;
	do {
		//�������� 100Mb ������
		unsigned char *arr = new (std::nothrow) unsigned char[100*1024*1024];
		if (nullptr == arr) break;
		counter += 100;
		std::cout << '\r' << counter << "Mb";
		//�� ���������� ����� ������, ���������� � arr ��������, ������������ ������ ����������
		//���������� ��� �������� ������ ����� ��������� � � ��������� ������ ����������
	} while (true);
	std::cout << std::endl;
}

/* �������� ������
 i) ������� ������������
 ii) ������������ �� ��������� ������
 iii) ������������� ��������� ���� delete/delete[]
*/

//������������� ������������ ������ ��� �������� ������ � ������� ��� ������������ ������������� ��� �����������
//�������� ������� ������� �� ����
int * array_merge(int arr1[], size_t size1, int arr2[], size_t size2) {
	auto new_array = new (std::nothrow) int[size1 + size2];

	for (size_t pos = 0; pos != size1; ++pos)
		new_array[pos] = arr1[pos];

	for (size_t pos = 0; pos != size2; ++pos)
		new_array[pos+size1] = arr2[pos];

	return new_array;
}

//������������ ������ ����������� ���-�� �����
//���� ������������� ����
//������� ����� � �������� �������
void reverse_numbers() {
	int next_number = 0;
	size_t size = 0;
	int *dynamo_array = nullptr;

	do {
		std::cin >> next_number;
		if (!std::cin.good()) { //�������� ��������� ������ �� ������ 
			if (std::cin.bad()) { //��������������� ������
				std::cout << "Unrecoverable error! Programm terminated!" << std::endl;
				return;
			}
			std::cin.clear(); //�������������� ������
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //����� �������� ������
			std::cout << "Input error! Please enter integer number" << std::endl;
			continue;
		}

		if (0 == next_number) break; //���� ����� ���� - ����������

		auto tmp = new (std::nothrow) int[size + 1]; //���������� ������ ���� ������ ������
		if (nullptr == tmp) { //���������, ��� ������ ������ ���� ��������
			std::cout << "Not enough memory" << std::endl;
			break;
		}

		if (nullptr != dynamo_array) { //���� ����� ���������� ������ �� �����, �� ���������� ���������� ������ �� ������ ������ � �����
			for (size_t count = 0; count != size; ++count)
				tmp[count] = dynamo_array[count];
			//������� ������ ������
			delete[] dynamo_array;
		}
		dynamo_array = tmp;

		dynamo_array[size] = next_number;
		++size;
	} while (true);

	for (size_t count = size; count != 0; --count)
		std::cout << dynamo_array[count-1] << " ";
	std::cout << std::endl;

	if (nullptr != dynamo_array) delete[] dynamo_array; //����������� ������������ ������
}

int main() {
	if (false) new_test();
	if (false) new_function_test();
	if (false) new_array_test();
	if (false) new_array_types();
	if (false) new_with_init();
	if (false) memory_leak();
	if (false) reverse_numbers();

	return 0;
}