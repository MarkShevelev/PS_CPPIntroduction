#include <iostream>
#include <cstdlib>

//указатель на указатель, что это?
void pointer_to_pointer() {
	int a = -23; //переменная типа int
	int *ptr = &a; //переменная для хранения адреса на переменную типа int
	//указатель - это тоже переменная, со своей памятью, следовательно у него тоже есть адрес!
	std::cout << &ptr << std::endl;

	//адрес указателя тоже можно сохранить в переменной
	int * * ptr_ptr = &ptr; //объявление переменной говорит нам, что ptr_ptr - это переменная, которая является указателем, хранящим адрес на переменную с типом int *, т.е. другой адрес

	//чтобы получить данные, нам необходимо разыменовать указатель дважды
	std::cout << ptr_ptr << std::endl; //выводит значение переменной ptr_ptr - адрес переменной ptr
	std::cout << *ptr_ptr << std::endl; //выводит значение переменной ptr - адрес переменной a
	std::cout << **ptr_ptr << std::endl; //выводит значение переменной a
}

//массив указателей
void array_of_pointers() {
	//интересный объект - массив указателей
	int * arr[3]; //автоматический массив из трёх адресов
	int a, b, c;
	arr[0] = &a;
	arr[1] = &b;
	arr[2] = &c;

	//присваиваем значения переменным косвенно
	for (size_t pos = 0; pos != 3; ++pos)
		*arr[pos] = 2 * pos;

	//читаем занчения переменных косвенно
	for (size_t pos = 0; pos != 3; ++pos)
		std::cout << *arr[pos] << std::endl;
}

//массив указателей в динамической памяти
void dynamo_array_of_pointers() {
	//ключевое слово new возвращает указатель с типом указанным при запрос
	int* *dynamo_ptr_array = new (std::nothrow) int*[3]; //выделяем массив из трёх указателей в динамической памяти
	//обратите внимание на тип данных у переменной dynamo_ptr_array

	int a, b, c;
	*(dynamo_ptr_array + 0) = &a;//одно разыменование приводит нас в ячейку памяти, где хранится адрес, т.е. данные типа int*
	*(dynamo_ptr_array + 1) = &b;
	*(dynamo_ptr_array + 2) = &c;

	for (size_t pos = 0; pos != 3; ++pos)
		**(dynamo_ptr_array + pos) = 2 * pos;//двойное разыменование даёт доступ к данным

	//преобразуем запись в квадратные скобки по правилу *(ptr + x) => ptr[x]
	//**(dynamo_ptr_array+pos) => *(*(dynamo_ptr_array+pos)+0) => *(dynamo_ptr_array[pos]+0) => dynamo_ptr_array[pos][0]
	for (size_t pos = 0; pos != 3; ++pos)
		std::cout << dynamo_ptr_array[pos][0] << std::endl;

	delete[] dynamo_ptr_array;
}

//двумерный динамический массив
void twodimensional_dynamo_array() {
	//двумерный массив - это набор из нескольких рядов, каждый из которых является массивом
	size_t const row_size = 3;
	int *row1 = new (std::nothrow) int[row_size];
	int *row2 = new (std::nothrow) int[row_size];
	int *row3 = new (std::nothrow) int[row_size];

	//чтобы упростить доступ к рядам, сохраним адреса в отдельном массиве
	int * * rows = new (std::nothrow) int*[3];
	rows[0] = row1; rows[1] = row2; rows[2] = row3;

	//чтобы заполнить такой массив данным достаточно прибегнуть к вложенному циклу
	for (size_t row = 0; row != 3; ++row)
		for (size_t pos = 0; pos != row_size; ++pos)
			rows[row][pos] = 1; //обратите внимание на порядок индексов

	for (size_t row = 0; row != 3; ++row) {
		for (size_t pos = 0; pos != row_size; ++pos)
			std::cout << rows[row][pos] << std::endl;
		std::cout << std::endl;
	}

	//удаление памяти
	delete[] rows;
	delete[] row1;
	delete[] row2;
	delete[] row3;
}

//созданием двумерного массива произвольных размеров
void anysize_twodimensional_dynamo_array() {
	int user_rows, user_cols;
	std::cout << "Please, enter the field dimensions x and y: ";
	std::cin >> user_cols >> user_rows;

	//сначала создаём массив, где будем хранить адреса
	char * * field = new (std::nothrow) char*[user_rows];
	//создаём заданное кол-во рядов
	for (int row_count = 0; row_count != user_rows; ++row_count)
		field[row_count] = new (std::nothrow) char[user_cols]; //каждый ряд состоит из элементов типа char

	//заполняем значениями
	for (int row_count = 0; row_count != user_rows; ++row_count)
		for (int col_count = 0; col_count != user_cols; ++col_count)
			field[row_count][col_count] = 'a' + (row_count*user_cols + col_count) % 13;

	//печатаем значения
	for (int row_count = 0; row_count != user_rows; ++row_count) {
		for (int col_count = 0; col_count != user_cols; ++col_count)
			std::cout << field[row_count][col_count] << " ";
		std::cout << std::endl;
	}

	//удаление памяти
	//сначала каждый ряд в отдельности
	for (int row_count = 0; row_count != user_rows; ++row_count)
		delete[] field[row_count];
	//затем массив, хранящий адреса
	delete[] field;
}

//понятие индексного массива
void index_array() {
	//массив, в котором хранятся адреса рядов - называется индексным
	//из-за того, что распределение памяти при многократном вызове new может привести к неплотному распределению памяти, выгоднее все данные запросить в одном массиве
	int user_rows, user_cols;
	std::cout << "Please, enter the field dimensions x and y: ";
	std::cin >> user_cols >> user_rows;

	char *field_data = new (std::nothrow) char[user_cols*user_rows];
	//однако к field нельзя применять квадратные скобки дважды :(
	//но можно создать специальный массив, к которому применение дважды скобок возможно! :)
	char * * field = new (std::nothrow) char*[user_rows];
	//адреса могут быть любыми, так что мы сохраним адреса позиций внутри основного массива field_data
	for (int row_count = 0; row_count != user_rows; ++row_count)
		field[row_count] = field_data + row_count * user_cols;

	//при заполнении данными мы можем избежать скачков в памяти
	for (size_t pos = 0; pos != user_cols * user_rows; ++pos)
		field_data[pos] = 'a' + pos % 13;

	//при выводе мы можем воспользоваться индексным массивом
	for (int row_count = 0; row_count != user_rows; ++row_count) {
		for (int col_count = 0; col_count != user_cols; ++col_count)
			std::cout << field[row_count][col_count] << " ";
		std::cout << std::endl;
	}

	//удаление памяти становится очень удобным
	delete[] field;
	delete[] field_data;
}

//использование двумерного массива в функции
//обратите внимание на тип данных - int * * - arr2D является массивом, хранящим адреса на строки
int diagonal_sum(int * * arr2D, size_t rows, size_t cols) {
	int sum = 0;
	for (size_t pos = 0; pos < rows && pos < cols; ++pos)
		sum += arr2D[pos][pos];
	return sum;
}

//вызываем функцию
void diagonal_sum_test() {
	int user_rows, user_cols;
	std::cout << "Please, enter the field dimensions x and y: ";
	std::cin >> user_cols >> user_rows;

	int * * index = new (std::nothrow) int*[user_rows];
	for (size_t row = 0; row != user_rows; ++row)
		index[row] = new (std::nothrow) int[user_cols];

	//заполняем массив случайными значениями
	srand(56);
	for (size_t row = 0; row != user_rows; ++row)
		for (size_t col = 0; col != user_cols; ++col)
			index[row][col] = rand() % 2;

	//выводим на печать
	for (size_t row = 0; row != user_rows; ++row) {
		for (size_t col = 0; col != user_cols; ++col)
			 std::cout << index[row][col] << " ";
		std::cout << std::endl;
	}

	std::cout << "Diagonal sum: " << diagonal_sum(index, user_rows, user_cols) << std::endl;

	//освобождаем память
	for (size_t row = 0; row != user_rows; ++row)
		delete[] index[row];
	delete[] index;
}

//автоматический двумерный массив
void auto_twodimensional_array() {
	int auto_arr2D[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	//int * * ptr = auto_arr2D; //преобразование типов невозможно!
	int * ptr = auto_arr2D[0]; //однако преобразование ряда к указателю на первый элемент возможно

	//создадим индексный массив
	int * * index = new (std::nothrow) int*[3];
	for (size_t pos = 0; pos != 3; ++pos)
		index[pos] = auto_arr2D[pos]; //мы сохраняем адреса рядов в индексном массиве

	//выводим на печать
	for (size_t row = 0; row != 3; ++row) {
		for (size_t col = 0; col != 3; ++col)
			std::cout << index[row][col] << " ";
		std::cout << std::endl;
	}

	//используя индексный массив, мы можем передать данные автоматического массива в функцию
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