/** 
* ������������ �������
* */

#include <iostream> //cin cout

//���� ������� ��������, �� ��������� ������� �� ����� ����������� ������� ��������
int my_sum(int x, int y);

//�/C++ ��������������� ����������� ����������� - ����������� �������,
//�.�. � ���������� ��� ����������� ��������������� ��� �������
//�������, ������� ����� ���� �������� ���������� �������� ������ inline
inline
int my_max(int x, int y) {
	return y > x ? y : x;
}
//������������ ������� ������� ���� ��������� ���������� (� �����) � ��� �����, ��� ������������!
//������������ ������� �� ����� ������������ ��������� ����������� ����������!

int main() {
	int userX, userY;
	std::cin >> userX >> userY;

	//����� ������������ ������� �������������� ����� �����, ��� � �������
	std::cout << "max is " << my_max(userX, userY) << std::endl;

	return 0;
}

//������� ������� ��������� ��������� ���������� �� ����������� (����)
int my_sum(int x, int y) {
	return x + y;
}