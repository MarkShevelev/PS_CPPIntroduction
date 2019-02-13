/**
* Перегруженные функции
* */

#include <iostream> //cout cin

//В С++ функции, объявляемые программистом, могут иметь одинаковое имя (идентификатор), но различный набор параметров

int my_sum(int x, int y) {
	return x + y;
}

int my_sum(int const arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += arr[i];
	return sum;
}

//Две функции выше имеют одинаковые названия, но разные наборы входящих параметров,
//что допустипо в C++. В этом случае идентификатор my_sum называется перегруженным,
//т.е. за ним числится более одной функции

//может быть сколько угодно перегруженных функций 
//и они не обязаны все определяться в одной единице трансляции
void my_sum(int dst[], int const src[], int size) {
	for (int i = 0; i < size; ++i)
		dst[i] += src[i];
}

//компилятор сам определит, какую перегруженную функцию выбрать,
//опираясь на переданные параметры
void overload_test() {
	int const size = 5;
	int arr[size] = { 1,2,3,4,5 };
	int a = -1, b = -3;

	std::cout << my_sum(arr, size) << " " << my_sum(a, b) << std::endl;
}

//функции с одинаковым идентификатором могут различаться типом параметров или их количеством
int sqr(int x) {
	std::cout << "Int sqr" << std::endl;
	return x * x;
}

double sqr(double x) {
	std::cout << "Double sqr" << std::endl;
	return x * x;
}

int my_max(int a, int b) {
	return b > a ? b : a;
}

int my_max(int a, int b, int c) {
	return my_max(a, my_max(b, c)); //здесь компилятор автоматически подставит вызов my_max с двумя аргументами
}

double my_max(double a, double b) {
	return b > a ? b : a;
}

double my_max(double a, double b, double c) {
	return my_max(a, my_max(b, c)); //здесь компилятор автоматически подставит вызов my_max с двумя аргументами
}

//компилятор выбирает из перегрузок по типу и количеству параметров
void overload_test2() {
	std::cout << "Please enter three integer numbers: " << std::flush;

	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << "Max is: " << my_max(a, b, c) << std::endl;

	std::cout << a << "*" << a << " = " << sqr(a) << std::endl;
	std::cout << b << "*" << b << " = " << sqr(b) << std::endl;
	std::cout << c << "*" << c << " = " << sqr(c) << std::endl;
	

	std::cout << "Please, enter theree double numbers: " << std::flush;
	double da, db, dc;
	std::cin >> da >> db >> dc;
	std::cout << "Max is: " << my_max(da, db, dc) << std::endl;

	std::cout << da << "*" << da << " = " << sqr(da) << std::endl;
	std::cout << db << "*" << db << " = " << sqr(db) << std::endl;
	std::cout << dc << "*" << dc << " = " << sqr(dc) << std::endl;
}

void overload_test3() {
	double d = 1.2;
	int i = 0;
	//при выборе перегруженных функций компилятор не учитывает тип возвращаемого значения
	//double res = my_max(d, i); //ошибка компиляции! невозможно выбрать подходящую функцию
}

//перегруженные функции не могут различаться ТОЛЬКО типом генерируемого значения
/*int hello() {
	return 1;
}

double hello() {
	return 1.1;
}
*/


int main() {
	overload_test();
	overload_test2();
	overload_test3();
}