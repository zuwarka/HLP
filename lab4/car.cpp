#include "car.h"
//файл с "описанием" методов класса car
car::car(std::string& model, std::string& reg, std::string& numb, std::string& symb, std::string& surn, std::string& name, std::string& addres, std::string& data)
{	//конструктор
	this->numb = nullptr; //this - это скрытый указатель; обращение к объекту внутри класса к конкретному его члену
	person = nullptr;
	set_all(model, reg, numb, symb, surn, name, addres, data); //установка переменных
}
void car::set_all(std::string& model, std::string& reg, std::string& numb, std::string& symb, std::string& surn, std::string& name, std::string& addres, std::string& data)
{	//метод установки всех переменнх
	this->model = model; //передаем модель,
	this->data = data; //дату
	if (!this->numb) //если в this->numb еще ничего не имеется,
		this->numb = new Number(reg, numb, symb); //то создаем в нем элементы номера авто
	else
	{
		delete this->numb;
		this->numb = new Number(reg, numb, symb);
	}
	if (!person) //аналогично с номером авто поступаем с человеком
		this->person = new Person(surn, name, addres);
	else
	{
		delete this->person;
		this->person = new Person(surn, name, addres);
	}
}

void car::show_all() const
{	//метод вывода всех данных
	std::cout << "_____________________________\n";
	show_model();
	show_number();
	show_person();
	show_addr();
	show_data();
	std::cout << "_____________________________\n";
}

void car::show_addr() const
{	//метод вывода адреса
	std::cout << "_____________________________\n";
	std::cout << "Address:\t" << get_address() << "\n";
	std::cout << "_____________________________\n";
}

void car::show_person() const
{	//метод вывода фамилии и имени 
	std::cout << "_____________________________\n";
	std::cout << "SN:\t" << get_person() << "\n";
	std::cout << "_____________________________\n";
}

void car::show_number() const
{	//метод вывода номера авто
	std::cout << "_____________________________\n";
	std::cout << "Number:\t" << get_number() << "\n";
	std::cout << "_____________________________\n";
}

void car::show_model() const
{	//метод вывода модели авто
	std::cout << "_____________________________\n";
	std::cout << "Model:\t" << get_model() << "\n";
	std::cout << "_____________________________\n";
}

void car::show_data() const
{	//метод вывода даты т.о.
	std::cout << "_____________________________\n";
	std::cout << "Date T.O:\t" << get_data() << "\n";
	std::cout << "_____________________________\n";
}

car::~car()
{	//деструкор
	if (this->numb)
		delete this->numb;

	if (person)
		delete this->person;
}
