#include "car.h"
#include <string>

car** input(car** vect_car, int& size)
{	//функция ввода данных "базы"
	//строковые переменные модели, даты, региона, цифр, букв, фамилии, имени, адреса, а также флага (признак)
	std::string model, data, reg, numb, symb, surn, name, addr, flag;

	while (true)
	{	//цикл до инструкции досрочноого выхода, вводим необходимые данные
		//при каждом новом вводе будет создаваться новый динамический массив, в который будут заноситься прошлые значения из "старого" массива,
		//в свою очередь старый удаляется, а новый становится "старым"
		std::cout << "Введите модель машины: ";
		std::getline(std::cin, model, '\n');
		std::cout << "Введите регион номера: ";
		std::getline(std::cin, reg, '\n');
		std::cout << "Введите три цифры номера: ";
		std::getline(std::cin, numb, '\n');
		std::cout << "Введите три буквы номера: ";
		std::getline(std::cin, symb, '\n');
		std::cout << "Введите фамилию: ";
		std::getline(std::cin, surn, '\n');
		std::cout << "Введите имя: ";
		std::getline(std::cin, name, '\n');
		std::cout << "Введите адрес: ";
		std::getline(std::cin, addr, '\n');
		std::cout << "Введите дату т.о. (ДД.ММ.ГГГГ): ";
		std::getline(std::cin, data, '\n');
		size++; //увеличиваем размерность динамического массива
		car** new_vect_car = new car * [size]; //вводим новый массив размера size
		new_vect_car[size - 1] = new car(model, reg, numb, symb, surn, name, addr, data); //заносим туда данные
		for (int i = 0; i < size - 1; i++)
		{
			new_vect_car[i] = vect_car[i]; //переприсваиваем значения в новый
		}
		if (vect_car)
			delete[] vect_car; //удаляем старый

		vect_car = new_vect_car; //теперь "новый" массив стал "старым", основным

		std::cout << "Продолжить ввод 1, закончить 0: ";
		std::getline(std::cin, flag, '\n');
		if (flag == "0")
		{
			break;
		}

	}
	return vect_car;
}

void output(car** car, int size)
{	//функция вывода данных
	for (int i = 0; i < size; i++)
	{
		car[i]->show_all(); //обращаемся к методу вывода из класса автомобиль
	}
}

void output_not_T_O(car** car, int size)//по пункту а
{	
	std::cout << "Прошли ТО в этому году:\n";
	std::cout << "_____________________________\n";
	for (int i = 0; i < size; i++)
	{
		std::string check = car[i]->get_data(); //строка получения даты прохождения т.о. из класса автомобиль
		check.erase(0, check.length() - 4);
		if (check != "2020")
		{	//если автомобиль прошел т.о. в 2020-ом году, то для программы он не считается пройденным
			//если т.о. пройден раньше, то выводим данные об авто согласно условию задачи
			car[i]->show_number();
			car[i]->show_model();
			car[i]->show_person();

		}
	}
	std::cout << "_____________________________\n";
}

void output_must_model(car** car, int size)//по пункту б
{	
	std::string model;
	std::cout << "Введите нужную модель: ";
	std::getline(std::cin, model, '\n');
	std::cout << "Номера машин данной модели:\n";
	std::cout << "_____________________________\n";
	for (int i = 0; i < size; i++)
	{
		if (model == car[i]->get_model())
		{

			car[i]->show_number();
		}
	}
	std::cout << "_____________________________\n";

}

void output_to_addr(car** car, int size)//по пункту в
{
	std::string addr;
	std::cout << "Введите адресс проживания: ";
	std::getline(std::cin, addr, '\n');
	std::cout << "Вся информация о машинах и их вледельцах по данному адресу:\n";
	std::cout << "_____________________________\n";
	for (int i = 0; i < size; i++)
	{
		if (addr == car[i]->get_address())
		{

			car[i]->show_all();

		}
	}
	std::cout << "_____________________________\n";

}

int main()
{	//главная функция
	setlocale(LC_ALL, "Rus");
	int size = 0;
	car** vect_car = nullptr; //вводим указатель на указатель на класс car (двумерный массив)
	vect_car = input(vect_car, size); //вводим в него значения
	output_not_T_O(vect_car, size); //выводим значения, согласно пункту а
	output_must_model(vect_car, size); //выводим значения, согласно пункту б
	output_to_addr(vect_car, size); //выводим значения, согласно пункту в
	for (int i = 0; i < size - 1; i++)
	{
		delete vect_car[i]; //очищаем строки массива
	}
	delete[] vect_car; //очищаем сам массив

	return 0;
}
