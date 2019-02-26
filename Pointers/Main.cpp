#include <iostream>
#include <cstdio>

void address() {
	//У каждой переменной есть точное место, где она расположена в памяти - номер коробки на складе
	int i; //объявление переменной - связывание имени с данными в памяти
	//оператор & позволяет узнать точное местоположение данных
	std::cout << &i << std::endl; //перегруженный ввод/вывод C++ определяет вывод на экран по типу
	printf("%p\n", &i); //вывод адреса в языке C осуществляется местозаместителем %p

	//адрес - это просто целое число, номер ячейки в оперативной памяти
	size_t address_as_num = (size_t)&i;
	std::cout << address_as_num << std::endl;
	//size_t - специальное именование числового типа данных, который позволяет сохранить в виде числа любой адрес

	//при разных запусках программы адрес переменной меняется, т.к. операционная система сама оптимизирует использование приложений и может загружать их в различные части оперативной памяти
}

void pointer() {
	//Указатель - специальный тип переменных, которые хранят адреса
	int *ptr; //переменная, которая обладает своей собственной памятью, где можно хранить адрес

	int variable; //обычная целочисленная переменная
	ptr = &variable; //& берёт адрес, = сохраняет адрес в память, связанную с ptr

	std::cout << "addres = " << &variable << std::endl;
	std::cout << "pointer = " << ptr << std::endl;

	//Важнейшая операция, которая доступна для указателя, но недоступна для других переменных - разыменование
	*ptr = 7; //* означает обращение к данным по аресу, = кладёт данные не в ptr, а в variable
	std::cout << "pointer = " << ptr << std::endl;
	std::cout << "variable = " << variable << std::endl;
}

//Указатель - важнейший инструмент для опосредованного доступа к памяти, позволяющий изменять данные в памяти, которая не принадлежит данному фрагменту кода
void pointer_inderect(int *a_ptr) {
	//благодаря тому, что функция pointer_inderect принимает в качестве параметра указатель, она может менять данные в памяти, которая не была выделена в функции
	*a_ptr = 3;
}

//изменение данных в вызывающем коде не будет
void variable_direct(int a) {
	a = 3;
}

void pointer_inderect_test() {
	int a; //переменная a существует только внутри функции
	a = 5;
	std::cout << a << std::endl;

	variable_direct(a);
	std::cout << a << std::endl; //значение a не поменялось

	pointer_inderect(&a);
	std::cout << a << std::endl; //т.к. в функцию передаётся адрес, то функция может изменить занчение в памяти по адресу
}

//функция, обменивающая два значения любого типа, используя указатели
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
	//указатели обладают специальным поведением при сложении с целым числом
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