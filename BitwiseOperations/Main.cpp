#include <iostream>
#include <bitset>

//��������� �������� (bitwise operations) ��� ��������, ����������� � ������� �������������� �����

//������� �������������
void bitrepresentaion_test() {
	//����� ����� � ������ ���������� �������� � �������� ����
	//��������, ����� 3 -> 11, � ����� 10 -> 1010

	int user_input; //� ����� ����� ���� int ������������ 32 �������� �������
	std::cin >> user_input;

	std::cout << "Binary representaion of a number " << user_input << " is " << std::endl;
	std::cout << std::bitset<32>(user_input) << std::endl;

	//����������� ��������� ��������� �������� ����� � �������� ����
	int binnum = 0b111011;
	std::cout << binnum << std::endl;
}

//������� �������� ��������� ��������� �������� ��� ������ �����, � �� ������������� �������������� ��������
void bitwiseoperation_test() {
	//�������� ��� ��������� (NOT)
	{
		std::cout << "NOT" << std::endl;
		unsigned a = 0b10010111010010111001001001111011;
		unsigned b = ~a;//���� �������� �� �������, � ������� �� ����
		std::cout << std::bitset<32>(a) << " " << a << std::endl;
		std::cout << std::bitset<32>(b) << " " << b << std::endl;
	}

	//������
	{
		unsigned char initnum = 0b10110101;
		unsigned char left_shift = initnum << 1u; //�����  
		unsigned char right_shift = initnum >> 1u; //������
		std::cout << std::bitset<8>(initnum) << "\n" << std::bitset<8>(left_shift) << " leftshift\n" << std::bitset<8>(right_shift) << " rightshift\n" << std::endl;
		//�� ��������� ����� ��� ������ ������ ����
		//����� ����� �������������� ����� �������� ������������� ����������!!!
		//int i = -2; int j = i << 1; //undefined
	}

	//������ ��������
	//� AND
	{
		std::cout << "AND" << std::endl;
		unsigned char a = 0b00001111, b = 0b11000011;
		unsigned char bitwise_and = a & b;
		std::cout << std::bitset<8>(a) << "\n" << std::bitset<8>(b) << "\n" << std::bitset<8>(bitwise_and) << "\n" << std::endl;
	}

	//��� OR
	{
		std::cout << "OR" << std::endl;
		unsigned char a = 0b00001111, b = 0b11000011;
		unsigned char bitwise_or = a | b;
		std::cout << std::bitset<8>(a) << "\n" << std::bitset<8>(b) << "\n" << std::bitset<8>(bitwise_or) << "\n" << std::endl;
	}

	//����������� ��� XOR
	{
		std::cout << "XOR" << std::endl;
		unsigned char a = 0b00001111, b = 0b11000011;
		unsigned char bitwise_xor = a ^ b;
		std::cout << std::bitset<8>(a) << "\n" << std::bitset<8>(b) << "\n" << std::bitset<8>(bitwise_xor) << "\n" << std::endl;
	}

	//���������
	//<< >> ������
	//�������� ��������� != ==
	//& �
	//^ xor
	//| ���
	//���������� �������� && ||
	{
		int a=1, b=1, c=1;
		if (a&b == a^c|b || b|a|c != a&b^c) std::cout << "true" << std::endl;
		else std::cout << "false" << std::endl;
	}
}

//������, �������� � �������������� ������� ��������

//1) ���������� ��������� ������� ������
void bitset_test() {
	//������ ���������� ���� bool �������� � ������ 1 ����
	bool flag = true;

	//������ � ����� ����� ����� ������� ����� 8 ��������� true/false
	unsigned char set = 0b01011101;
	int pos;
	std::cout << std::bitset<8>(set) << std::endl;
	std::cout << "Choose position to ask: ";
	std::cin >> pos;
	std::cout << std::boolalpha << ((1u << pos& set) != 0) << std::endl;

	std::cout << "Choose position to set 1: ";
	std::cin >> pos;
	set |= 1u << pos;
	std::cout << std::bitset<8>(set) << std::endl;

	std::cout << "Choose position to set 0: ";
	std::cin >> pos;
	set &= 1u << pos;
	std::cout << std::bitset<8>(set) << std::endl;
}

//2) �������, ����� � ������� ����� ����� � �����, ������ �������� �����, ���� �������, ��� ������ ������ ���
void exhaustive_search_test() {
	int arr[10] = { 1,2,3,3,4,-1,5,8,6,-3 };
	int user_num;
	std::cout << "Enter the number to sum up: ";
	std::cin >> user_num;

	unsigned short set = 1;
	for (; set != 0b10000000000; ++set) {
		int sum = 0;
		for (int pos = 0; pos != 10; ++pos)
			sum += (1u << pos & set) != 0 ? arr[pos] : 0;
		if (sum == user_num)
			break;
	}

	if (0b10000000000 == set)
		std::cout << "No such a set to sum up to " << user_num << std::endl;
	else {
		
		for (int pos = 0; pos != 10; ++pos)
			if ((1u << pos & set) != 0)
				std::cout << arr[pos] << " ";
		std::cout << std::endl;
	}
}

//3) ��������� ��������������� �����
void random_generator_test() {
	int init;

	std::cout << "Enter initial number: ";
	std::cin >> init;

	unsigned long long x = init;

	for (int count = 0; count != 100; ++count) {
		x ^= x << 13;
		x ^= x >> 17;
		x ^= x << 5;
		std::cout << x % 1000 << " ";
	}
	std::cout << std::endl;
}

int main() {
	if (false) bitrepresentaion_test();
	if (false) bitwiseoperation_test();
	if (false) bitset_test();
	if (false) exhaustive_search_test();
	if (false) random_generator_test();

	return 0;
}

