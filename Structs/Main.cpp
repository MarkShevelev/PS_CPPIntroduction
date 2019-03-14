#include <iostream>
#include <cstring>

//В некоторых ситуациях объекты не описываются одним числом какого-то типа,
//а рядом характеристик
//Например денежные средства описываются двумя целыми числами: рубли и копейки

//пример работы с рублями и копейками
//т.к. функция не может вернуть два числа, то мы перезаписываем память опосредовано
void sum_currency(int r1, int c1, int r2, int c2, int *r, int *c) { 
	*r = r1 + r2 + (c1 + c2) / 100;
	*c = (c1 + c2) % 100;
}

void sum_currency_test() {
	//необходимо завести четыре переменные
	int r1, c1, r2, c2, r, c;

	//считать в правильном порядке
	std::cout << "Please, enter the first amount rub kop: ";
	std::cin >> r1 >> c1;

	std::cout << "Please, enter the second amount rub kop: ";
	std::cin >> r2 >> c2;

	//затем вызвать функцию, не перепутав порядок аргументов
	sum_currency(r1, c1, r2, c2, &r, &c);

	std::cout << "Summ is " << r << " rub and " << c << " kop" << std::endl;
}

//Так же сложности может вызвать создание массивов из сложных наборов данных
//Например, отрезок на прямой имеет две координаты: начало и конец
//Массив отрезков потребует создание пары массивов, которые будут связаны по индексам

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

//для упрощения работы с такими данными в C/C++ есть специальный инструмент - структуры
//структура - это набор данных объединённых общим именем, которое позволяет оперировать этим набором как целым
void struct_test() {
	struct Point {
		double x, y;
	};

	Point p1; //объявляем переменную с именем Point, под одним именем p1 скрывается сразу два элемента данных типа double
	struct Point p2; //в языке C необходимо добавлять слово struct не только при объявлении структуры, но и при объявлении переменной

	p1.x = 1.0; p1.y = -1.0; //. - оператор декомпозиции, который может по имени выбрать из структуры отдельный элемент

	p2 = p1; //сила структур в том, что с ними допустимы операции как с целым
	std::cout << p2.x << " " << p2.y << std::endl;

	//структуры могут содержать данные разных типов
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

	//структуры можно инициализировать при создании
	Point p3 = { 10.2,-10.4 };
	std::cout << p3.x << " " << p3.y << std::endl;

	Student MarksBarks = { 27,"Mark's Barks",3.1 };
	std::cout << MarksBarks.age << " " << MarksBarks.name << " " << MarksBarks.average << std::endl;

	//структуры могут содержать константы
	struct Name {
		size_t const maxlen;
		char *memory;
	};

	Name new_name = { 10, new (std::nothrow) char[10] };
	//new_name.maxlen = 11;//ошибка компиляции, нельзя изменить константу

	for (size_t pos = 0; pos != new_name.maxlen-1; ++pos)
		new_name.memory[pos] = 'a';
	new_name.memory[new_name.maxlen - 1] = '\0';

	std::cout << new_name.maxlen << " " << new_name.memory << std::endl;
	delete[] new_name.memory;


	//структуры могут содержать другие структуры
	struct Line {
		Point begin, end;
	};

	Line line1 = { {0.,0.}, {1.,1.} };
	std::cout << "Line length: " << sqrt((line1.begin.x - line1.end.x)*(line1.begin.x - line1.end.x) + (line1.begin.y - line1.end.y)*(line1.begin.y - line1.end.y)) << std::endl;

	//структуры даже могут содержать указатели на элементы того же самого типа!
	struct Node {
		Node *left, *righ;
		int data;
	};

	Node deadendA = { nullptr,nullptr,1 }, deadendB = { nullptr,nullptr,-1 };
	Node junction = { &deadendA,&deadendB,0 };
	std::cout << (*junction.left).data << " " << junction.data << " " << (*junction.righ).data << std::endl;

	//для структур определён специальный оператор, упрощающий доступ к данным, которые представленны адресом на структуру
	//(*a).data <=> a->data

	Point p_data = { -1.,1. };
	Point *p_ptr = &p_data;
	std::cout << p_data.x << " " << p_data.y << std::endl;
	std::cout << p_ptr->x << " " << p_ptr->y << std::endl;
}

int main() {
	if (false) sum_currency_test();
	if (false) segments_test();
	if (false) struct_test();

	return 0;
}