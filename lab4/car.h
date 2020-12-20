#pragma once
#include <iostream>

//19. Car: Модель, Номер(код региона, цифровой код, буквенный код), 
//Цвет, Сведения о владельце(Фамилия, Имя, Адрес), Дата последнего техосмотра.
//Создать массив объектов.Вывести : а) список номеров машин, не прошедших техосмотр в этом году, 
//с указанием модели и владельца; б) список номеров машин заданной модели; в) список машин, 
//владельцы которых живут по заданному адресу.
//Разработать класс для описанных ниже объектов.
//Включить в класс методы set(), get(), show().Определить другие необходимые методы

class Person
{	//класс человека
private:
	std::string surname;//фамилмя
	std::string name;//имя
	std::string address;//адрес
public:
	Person(std::string& s, std::string& n, std::string& a)
	{	//конструктор, принимающий три приватных переменных, указанных выше
		set_all(s, n, a);
	}
	std::string get_all() const
	{	//метод для "возвращения" фамилии, имени, адреса; const необходима, чтобы метод никак не изменял НЕконстантные значения, коими вляются наши переменные
		return (surname + " " + name + " " + address);
	}
	std::string get_surname() const
	{	//аналогично предыдущему
		return surname;
	}
	std::string get_name() const
	{	//аналогично предыдущему
		return  name;
	}
	std::string get_address() const
	{	//аналогично предыдущему
		return address;
	}
	void set_all(std::string& s, std::string& n, std::string& a)
	{	//метод ввода (установки) данных о человеке
		surname = s;
		name = n;
		address = a;
	}
};

class Number
{	//класс номера авто
private:
	std::string reg_code;//регион
	std::string numb_code;//цифроыой код
	std::string symb_code;//буквенный код
public:
	Number(std::string& r, std::string& n, std::string& s)
	{	//конструктор, принимающий три приватных переменных, указанных выше
		set_number(r, n, s);
	}
	std::string get_number()
	{	//метод взятия номера, изменяет переменные, поэтому const, как в предыдущих методах, не ставим
		std::string result;
		result = symb_code[0] + numb_code + symb_code[1] + symb_code[2] + reg_code; //a666aa178 
		return result;
	}
	void set_number(std::string& r, std::string& n, std::string& s)
	{	//метод установки номера, принимает регион, цифры и буквы номера
		reg_code = r;
		numb_code = n;
		symb_code = s;
		int i = 0;
		while (reg_code[i] != '\0')
		{	//цикл, пока код символ кода региона не равен нуль-терминатору
			if (reg_code[i] == '0') //если первая цифра региона ноль, то в окончательной версии вывода региона он удалится
				reg_code.erase(i, 1); //удаляем символ нуля
			else
				i++; //шаг цикла
		}
	}
};

class car
{	//основной класс
private://приватные поля(доступ только из методов класса)
	Number* numb;//номер
	Person* person;//всё о человеке
	std::string data;//дата т.о.
	std::string model;//модел
public:
	//ниже - конструктор
	car(std::string& model, std::string& reg, std::string& numb, std::string& symb, std::string& surn, std::string& name, std::string& addr, std::string& data);
	//ниже - метод установки значений переменнх
	void set_all(std::string& model, std::string& reg, std::string& numb, std::string& symb, std::string& surn, std::string& name, std::string& addr, std::string& data);
	std::string get_number() const { return numb->get_number(); };//const метод(в нём нельзя поменять приватные поля и вызывать не const методы) возвращает номер
	std::string get_person() const { return (person->get_surname() + " " + person->get_name()); }; //берем фамилию и имя
	std::string get_address() const { return person->get_address(); }; //берем адресс
	std::string get_data() const { return data; }; //берем дату т.о.
	std::string get_model() const { return model; }; //берем модель авто
	//выводим все это
	void show_all() const;
	void show_number() const;
	void show_data() const;
	void show_model() const;
	void show_person() const;
	void show_addr() const;
	~car(); //деструктор

};
