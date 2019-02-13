/**
 * Шаблоны функций
 * */

#include <iostream>

//рассмотрим две функции, которые печатают на экране содержимое массивов
void overload_print_array(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void overload_print_array(double arr[], int size) {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

//две функции выше делают одно и то же
//но различаются деталями кода, что приводит к необходимости дублировать код
//шаблоны функций избавляют от такой необходимости

template <typename T> //данная синтаксическая конструкция показывает компилятору,
//что функция ниже - шаблон, а идентификатор T заменяет имя типа
void template_print_array(T arr[], int size) {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void template_test() {
	int i_arr[5] = { 1,2,3,4,5 };
	double d_arr[5] = { 1.1,2.2,3.3,4.4,5.5 };

	overload_print_array(i_arr, 5); //здесь вызывается вариант перегруженной функции
	overload_print_array(d_arr, 5);

	template_print_array(i_arr,5); //здесь вызывается шаблонный вариант
	template_print_array(d_arr,5);
}

//Шаблон функции (шаблонная функция) не является настоящей функцией
//Шаблон функции - это специальная синтаксическая конструкция,
//на основе которой компилятор строит настоящую функцию.
//По этой причине шаблонные функции всегда должны быть включены в файл исходного кода
//и не могут быть скомпилированы предварительно.
//По той же причине шаблонные функции всегда встроены.

//Шаблонным параметром может быть не только имя типа, но и значение

template <int Size>
int sumof(int arr[]) {
	int sum = 0;
	for (int i = 0; i < Size; ++i)
		sum += arr[i];
	return sum;
}

//функция может иметь несколько шаблонных параметров
template <int Doubles, typename T>
T doubles(T in) {
	for (int i = 1; i < Doubles; ++i)
		in += in;
	return in;
}

void template_test2() {
	int arr[5] = { 1,2,3,4,5 };
	std::cout << sumof<5>(arr) << std::endl; //когда компилятор не может определить значение параметра, его значение следует указать явно в угловых скобках

	double d = 1.56;
	std::cout << doubles<5>(d) << std::endl;

	int i = -3;
	std::cout << doubles<3>(i) << std::endl;
}

//Копирование данных из одного массива в другой, работает только с типом int
void copy_array(int dst[], int src[], int size) {
	for (int i = 0; i < size; ++i)
		dst[i] = src[i];
}

//Шаблонная функция работает с любым типом данных!
template <typename T>
void tpl_copy_array(T dst[], T src[], int size) {
	for (int i = 0; i < size; ++i)
		dst[i] = src[i];
}

//Иногда тип значения, которое возвращает шаблонная функция, сложно определить
//мы не знаем заранее какой тип T1 или T2 окажется "шире"
template <typename T1, typename T2>
/*?*/auto tpl_sum(T1 a, T2 b) { //тогда мы подставляем вместо имени типа ключевое слово auto
	return a + b;
}

//auto означает, что возвращаемый тип будет определён компилятором

//Ключевое слово auto можно использовать и с переменными
void tempate_test3() {
	auto variable = 3; //переменная получает тип int
	auto another_variable = 3.1; //переменная получает тип double
	auto third_variable = 3.1f; //переменная получает тип float
	auto string = "Hello";  //переменная получает тип массив символов char[]

	std::cout
		<< variable << " "
		<< another_variable << " "
		<< third_variable << " "
		<< string << " "
		<< std::endl;
}

//функция, которая суммирует значения в массиве для любого типа данных
template <typename T>
auto tpl_array_sum(T arr[], int size) { //возвращаемый тип определит компилятор
	auto sum = arr[0]; //здесь создаём переменную, тип которой определит компилятор, исходя из типа массива
	for (int i = 1; i < size; ++i)
		sum += arr[i];
	return sum;
}

//Если возникает необходимость определить тип возвращаемого значения на основе выражения от известных типов,
//применяется ключевое слово decltype и хвостовой возвращаемый тип
template <typename T1, typename T2, typename T3>
auto dumb_sum(T1 a, T2 b, T3 c) -> decltype(a+b) { //просим компилятор вывести тип, опираясь на выражение a+b
	return a + b + c;
}

void template_test4() {
	int a = 3, b = 4;
	double da = 3.1, db = 4.1;

	std::cout << dumb_sum(a, b, db) << std::endl; //целое число
	std::cout << dumb_sum(a, db, b) << std::endl; //дробное число
}

int main() {
	template_test();
	template_test2();
	tempate_test3();
	template_test4();

	return 0;
}