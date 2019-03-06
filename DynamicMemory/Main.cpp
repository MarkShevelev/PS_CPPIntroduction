#include <iostream>

//Обыкновенно мы выделяем всю необходимую программе память сразу, используя автоматические переменные
//В некоторых ситуациях нужно выделять память по мере работы программы
//Такой процесс называется - динамическое выделение памяти

//в языке C++ для динамического выделения памяти используется ключевое слово new
void new_test() {
	//ключевое слово new указывает, что необходимо выделить память динамически, т.е. не на стеке, как работают автоматические переменные
	int *i_ptr = new (std::nothrow) int; //new - выражение, оно возвращает указатель со связанным типом, который соответствует тому типу данных, который указан после ключевого слова new

	*i_ptr = 3; //работая с памятью, выделенной динамически, мы используем указатель, который сохраняет адрес точного местоположения выделенной памяти

	std::cout << i_ptr << " " << *i_ptr << std::endl;

	//выражение new позволяет инициализировать данные при выделении памяти
	int *i_init_ptr = new (std::nothrow) int(5);
	std::cout << *i_init_ptr << std::endl;

	//динамическая память может покидать блок кода, в котором она объявлена, автоматическая - нет
	int *i_dynamo_ptr, *i_auto_ptr;
	{
		int i_auto = 3;
		int *i_dynamo = new (std::nothrow) int(5);
		i_auto_ptr = &i_auto;     //от автоматической переменной необходимо брать адрес
		i_dynamo_ptr = i_dynamo;  //i_dynamo - это уже адрес!
	}

	//std::cout << *i_auto_ptr << std::endl; //НЕОПРЕДЕЛЁННОЕ ПОВЕДЕНИЕ!!!
	std::cout << *i_dynamo_ptr << std::endl; //всё хорошо

	//Т.к. компилятор не может определить, когда память должна быть освобождена, следует указать ему это явно
	//для этого используется ключевое слово delete
	delete i_dynamo_ptr; //возвращаем память системе
	delete i_init_ptr;
	delete i_ptr;
}

//благодаря тому, что динамическая память не управляется фигурными скобками, она может покидать функцию!
int *dynamic_int(int original) {
	int *i_dynamo_copy = new (std::nothrow) int(original);
	return i_dynamo_copy;
}

void new_function_test() {
	int a = 3;
	int *a_copy_ptr = dynamic_int(a);
	std::cout << *a_copy_ptr << std::endl; //всё хорошо

	//не забываем возвращать память системе
	delete a_copy_ptr;
}

//выделять динамически можно память не только под один элемент, но и под массив
//для этого используется new с квадратными скобками
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

	delete[] user_bytes; //так же, как и в случае с одним элементом, память под массив нужно освобождать
	//однако следует использовать delete[]
}

//выделять массив в динамической памяти можно для любого типа данных
void new_array_types() {
	int user_input; //количество элементов массива!

	std::cout << "How many elements do you want to allocate?" << std::endl;
	std::cin >> user_input;

	if (user_input < 0) {
		std::cout << "Can't allocate a negative amount..." << std::endl;
		return;
	}

	int *dynamo_array = new (std::nothrow) int[user_input];//будет выделено user_input чисел типа int, 4*user_input байт
	if (nullptr == dynamo_array) {
		std::cout << "Can't allocate " << user_input << " elements of type int" << std::endl;
		return;
	}

	std::cout << user_input << " elements of type int have been allocated\nThe size of data is " << user_input * sizeof(int) << std::endl;

	delete[] dynamo_array;
}

//выделение с инициализацией
void new_with_init() {
	//инициализация возможна для известного кол-ва элементов
	int user_input;
	std::cin >> user_input;
	int *i_ptr = new (std::nothrow) int[user_input] {1, 2, 3, 4, 5}; //первые пять элементов будут инициализированы числами
	for (size_t count = 0; count != 5; ++count)
		std::cout << i_ptr[count] << " ";
	std::cout << std::endl;

	delete[] i_ptr;

	//можно инициализировать нулями весь массив
	i_ptr = new (std::nothrow) int[2*user_input] {0};

	for (size_t count = 0, end = 2*(size_t)user_input; count != end; ++count)
		std::cout << i_ptr[count] << " ";
	std::cout << std::endl;

	delete[] i_ptr;
}

//утечка памяти
void memory_leak() {
	//утечка памяти - ситуация, когда память была занята, но не была возвращена, а возможность для её освобождения утеряна

	size_t counter = 0;
	do {
		//занимаем 100Mb памяти
		unsigned char *arr = new (std::nothrow) unsigned char[100*1024*1024];
		if (nullptr == arr) break;
		counter += 100;
		std::cout << '\r' << counter << "Mb";
		//по завершении цикла данные, хранящиеся в arr теряются, освобождение памяти невозможно
		//постепенно вся имеющася память будет исчерпана и её выделение станет невозможно
	} while (true);
	std::cout << std::endl;
}

/* Типичные ошибки
 i) Двойное освобождение
 ii) Освобождение по неверному адресу
 iii) Использование неверного типа delete/delete[]
*/

int main() {
	if (false) new_test();
	if (false) new_function_test();
	if (false) new_array_test();
	if (false) new_array_types();
	if (false) new_with_init();
	if (true) memory_leak();

	return 0;
}