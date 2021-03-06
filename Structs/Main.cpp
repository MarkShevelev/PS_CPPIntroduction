#include <iostream>
#include <cstring>

//� ��������� ��������� ������� �� ����������� ����� ������ ������-�� ����,
//� ����� �������������
//�������� �������� �������� ����������� ����� ������ �������: ����� � �������

//������ ������ � ������� � ���������
//�.�. ������� �� ����� ������� ��� �����, �� �� �������������� ������ ������������
void sum_money(int r1, int c1, int r2, int c2, int *r, int *c) { 
	*r = r1 + r2 + (c1 + c2) / 100;
	*c = (c1 + c2) % 100;
}

void sum_money_test() {
	//���������� ������� ������ ����������
	int r1, c1, r2, c2, r, c;

	//������� � ���������� �������
	std::cout << "Please, enter the first amount rub kop: ";
	std::cin >> r1 >> c1;

	std::cout << "Please, enter the second amount rub kop: ";
	std::cin >> r2 >> c2;

	//����� ������� �������, �� ��������� ������� ����������
	sum_money(r1, c1, r2, c2, &r, &c);

	std::cout << "Summ is " << r << " rub and " << c << " kop" << std::endl;
}

//��� �� ��������� ����� ������� �������� �������� �� ������� ������� ������
//��������, ������� �� ������ ����� ��� ����������: ������ � �����
//������ �������� ��������� �������� ���� ��������, ������� ����� ������� �� ��������

bool segment_contains(int begin, int end, int point) {
	return point >= begin && point <= end;
}

void segments_intersect(int begin1, int end1, int begin2, int end2, int *begin, int *end) {
	*end = end1 < end2 ? end1 : end2;
	*begin = begin1 > begin2 ? begin1 : begin2;
}

void segments_test() {
	int begin_arr[5] = { 1,2,3,4,5 }, end_arr[5] = { 7,7,7,7,7 };
	int intersect_begin = begin_arr[0], intersect_end = end_arr[0];
	for (int idx = 1; idx != 5; ++idx) {
		int tmp_begin, tmp_end;
		segments_intersect(begin_arr[idx], end_arr[idx], intersect_begin, intersect_end, &tmp_begin, &tmp_end);
		intersect_begin = tmp_begin;
		intersect_end = tmp_end;
	}

	std::cout << "Intersection of the segments is ";
	if (intersect_begin > intersect_end)
		std::cout << "empty!";
	else
		std::cout << "[" << intersect_begin << "," << intersect_end << "]";
	std::cout << std::endl;
}

//��� ��������� ������ � ������ ������� � C/C++ ���� ����������� ���������� - ���������
//��������� - ��� ����� ������ ������������ ����� ������, ������� ��������� ����������� ���� ������� ��� �����
void struct_test() {
	struct Point {
		double x, y;
	};

	Point p1; //��������� ���������� � ������ Point, ��� ����� ������ p1 ���������� ����� ��� �������� ������ ���� double
	struct Point p2; //� ����� C ���������� ��������� ����� struct �� ������ ��� ���������� ���������, �� � ��� ���������� ����������

	p1.x = 1.0; p1.y = -1.0; //. - �������� ������������, ������� ����� �� ����� ������� �� ��������� ��������� �������

	p2 = p1; //���� �������� � ���, ��� � ���� ��������� �������� ��� � �����
	std::cout << p2.x << " " << p2.y << std::endl;

	//��������� ����� ��������� ������ ������ �����
	struct Student {
		int age;
		char name[16];
		double average;
	};

	Student Marks;
	Marks.age = 30;
	strcpy(Marks.name, "Mark");
	Marks.average = 4.33;

	Student Barks = Marks;
	std::cout << Barks.age << " " << Barks.name << " " << Barks.average << std::endl;

	//��������� ����� ���������������� ��� ��������
	Point p3 = { 10.2,-10.4 };
	std::cout << p3.x << " " << p3.y << std::endl;

	Student MarksBarks = { 27,"Mark's Barks",3.1 };
	std::cout << MarksBarks.age << " " << MarksBarks.name << " " << MarksBarks.average << std::endl;

	//��������� ����� ��������� ���������
	struct Name {
		size_t const maxlen;
		char *memory;
	};

	Name new_name = { 10, new (std::nothrow) char[10] };
	//new_name.maxlen = 11;//������ ����������, ������ �������� ���������

	for (size_t pos = 0; pos != new_name.maxlen-1; ++pos)
		new_name.memory[pos] = 'a';
	new_name.memory[new_name.maxlen - 1] = '\0';

	std::cout << new_name.maxlen << " " << new_name.memory << std::endl;
	delete[] new_name.memory;


	//��������� ����� ��������� ������ ���������
	struct Line {
		Point begin, end;
	};

	Line line1 = { {0.,0.}, {1.,1.} };
	std::cout << "Line length: " << sqrt((line1.begin.x - line1.end.x)*(line1.begin.x - line1.end.x) + (line1.begin.y - line1.end.y)*(line1.begin.y - line1.end.y)) << std::endl;

	//��������� ���� ����� ��������� ��������� �� �������� ���� �� ������ ����!
	struct Node {
		Node *left, *righ;
		int data;
	};

	Node deadendA = { nullptr,nullptr,1 }, deadendB = { nullptr,nullptr,-1 };
	Node junction = { &deadendA,&deadendB,0 };
	std::cout << (*junction.left).data << " " << junction.data << " " << (*junction.righ).data << std::endl;

	//��� �������� �������� ����������� ��������, ���������� ������ � ������, ������� ������������� ������� �� ���������
	//(*a).data <=> a->data

	Point p_data = { -1.,1. };
	Point *p_ptr = &p_data;
	std::cout << p_data.x << " " << p_data.y << std::endl;
	std::cout << p_ptr->x << " " << p_ptr->y << std::endl;
}

//����������� ��������� � ��������� ��� ������ ��������� ��������� � ���������� ����� ������ � �������� �� ������ �����
//������ � ��������� ���������� � �������������� ��������

struct Money {
	int rub, kop;
};

Money sum_struct_money(Money a, Money b) {
	return { a.rub + b.rub + (a.kop + b.kop) / 100, (a.kop + b.kop) % 100 };
}

void sum_struct_money_test() {
	//���������� ������� ����� ��� ����������
	Money a, b;

	//���������� ��� � �������������� ������ ����� � ����������
	std::cout << "Please, enter the first amount rub kop: ";
	std::cin >> a.rub >> a.kop;

	std::cout << "Please, enter the second amount rub kop: ";
	std::cin >> b.rub >> b.kop;

	//������� ���������� ����� � ����� �����������, ��� � ��� ������� ��������
	Money res = sum_struct_money(a,b); //��� �������� ���������� �������, �.�. ��������� ��������� ������� ������������ ������

	std::cout << "Summ is " << res.rub << " rub and " << res.kop << " kop" << std::endl;
}

//������������� �������� ��� ������ �� �������� �������, �������� ������������ ��������
struct IntArray {
	int *data; //��������� �� ������������ ������, ��� ����������� ������
	size_t 
		  capacity //����� ����� ���������
		, used;    //����� ���������, ������� ������
};

IntArray new_intarray(size_t initial_capacity) {
	int *memory = new (std::nothrow) int[initial_capacity]; //�������� �������� ������
	return { memory, nullptr == memory ? 0 : initial_capacity, 0 }; //��������� ���� IntArray ����� ������������� ���������������� ���������� ������� ��������
}

void delete_intarray(IntArray &arr) {
	delete[] arr.data;
	arr.capacity = 0;
	arr.used = 0;
}

bool push_intarray(IntArray &arr, int x) {
	if (arr.capacity == arr.used) {
		int *memory = new (std::nothrow) int[arr.capacity * 2 + 1]; //�������� ������ �������� �������
		if (nullptr == memory) return false;

		//�������� ������ � ����� ������
		for (size_t count = 0; count != arr.capacity; ++count)
			memory[count] = arr.data[count];
		delete[] arr.data;
		arr.data = memory;
		arr.capacity = arr.capacity * 2 + 1;
	}

	arr.data[arr.used++] = x;
	return true;
}

bool pop_intarray(IntArray &arr, int &res) {
	if (0 == arr.used) return false;
	res = arr.data[--arr.used];
	return true;
}

void dynamic_intarray_test() {
	IntArray arr = new_intarray(1);
	if (nullptr == arr.data) {
		std::cout << "Can't allocate memory!" << std::endl;
		return;
	}

	int user_input;
	do {
		std::cin >> user_input;
		if (0 == user_input) break;
		if (!push_intarray(arr, user_input)) {
			std::cout << "Not enough memory..." << std::endl;
			break;
		}
	} while (true);

	int output;
	while (pop_intarray(arr,output))
		std::cout << output << " ";
	std::cout << std::endl;

	delete_intarray(arr);
}

int main() {
	if (false) sum_money_test();
	if (false) segments_test();
	if (false) struct_test();
	if (false) sum_struct_money_test();
	if (false) dynamic_intarray_test();

	return 0;
}