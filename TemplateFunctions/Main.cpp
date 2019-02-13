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

int main() {
	template_test();
	template_test2();

	return 0;
}