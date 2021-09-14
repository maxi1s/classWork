#include <iostream>
#include <string.h>
#include "dog.h"
using namespace std;

//реализация
dogs::dogs(string p, string cl, int v, int yb, string sex, int Sherst)
{
	if (p == "" || cl == "" || sex == "" || Sherst < 0 || v <= 0 || yb <= 0) //заданы недопустимые значения полей - объект будет создан со статусом ошибка, чтобы нельзя было его использовать
		Status = Err;
	else {
		Poroda = p;
		YearBirth = yb;
		Ves = v;
		Color = cl;
		Name = "Безымянный кот";
		Status = OK; // всё в порядке, кошка создана
	}
}

string dogs::getPoroda()
{
	return Poroda;
}
string dogs::getSex()
{
	return Sex;
}
int dogs::getSherst()
{
	return Sherst;
}

int dogs::getYearBirth()
{
	return YearBirth;
}

int dogs::getVes()
{
	return Ves;
}

string dogs::getColor()
{
	return Color;
}

string dogs::getName()
{
	return Name;
}

bool dogs::getStatus()
{
	return Status;
}


bool dogs::ChangeVes(int v)
{
	int tmpV = Ves + v;
	bool result = (tmpV >= 0); //не может у кошки быть отрицательный вес
	if (result) Ves = tmpV; // вес остался положительным и изменился на величину v
	return result; // вес не изменится, а метод вернет ложь
}

bool dogs::setUpVes(int v) //кошка может увеличить вес
{
	if (v <= 0) //отсекаем возможность ввести отрицательный шаг изменения веса, в противном случае можно вместо увеличения веса получить его уменьшение
		return false;
	else return ChangeVes(v);
}

bool dogs::setDownVes(int v) //кошка может уменьшить вес
{
	if (v <= 0) //отсекаем возможность ввести отрицательный шаг изменения веса, в противном случае можно вместо уменьшенияя веса получить его увеличение
		return false;
	else return ChangeVes(-v);
}
bool dogs::setStrichka(int NewStriska) {
	int result = Sherst + NewStriska;
	return result;
}

bool dogs::setName(string nm) //кошка дали имя, или изменили его
{
	if (nm == "")   // нельзя дать кошке пустое имя
		return false;
	else {
		Name = nm;
		return true;
	}


}

void dogs::Go()    // кошка идет. 
{
	cout << Name.c_str() << " пошел гулять\n";
	cout << "@  \n";
	cout << "   @\n";
	cout << "@  \n";
	cout << "   @\n";
}

void dogs::Voice() // кошка мяукает. 
{
	cout << Name.c_str() << " сказал " << "M-r-r-r!\n";
}

void dogs::Print() // вывод информации о конкретном объекте класса Кошка. Вывести можно информацию только о правильной кошке
{
	cout << "\nЭкземпляр класса Кошки: " << "Имя - " << Name.c_str() << ", порода - " << Poroda.c_str() << ",\n";
	cout << "год рождения - " << YearBirth << ", вес - " << Ves << ".\n";
	cout << "Ах да, и цвет шёрстки - " << Color.c_str() << "\n\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	//неправильно созданная кошка
	cout << "Создать 1-й объект кошка и поработать с ней\n";
	dogs Cat1("", "", -3, 2016); // создаем экземпляр класса Кошка, на задаем неверное значение вес
	//пытаемся с ней поработать
	if (Cat1.getStatus() != OK) // прежде чем начать работу с объектом проверяем - создан он или нет 
	{
		cout << "Кошка не создана!\n";
	}
	else {
		Cat1.setName("Барсик");
		Cat1.Print();
		Cat1.Voice();
		Cat1.Go();
		if (Cat1.setDownVes(-5))
			cout << Cat1.getName().c_str() << " похудел на " << Cat1.getVes() << "кг. \n";
		else cout << "Ошибка ввода при уменьшении веса кота " << Cat1.getName().c_str() << "!\n";
	}


	cout << "\nСоздать 2-й объект кошка и поработать с ней\n"; // создаем экземпляр класса Кошка
	dogs Cat2("Перс", "Белый", 2, 2015);

	if (Cat2.getStatus() != OK) // прежде чем начать работу с объектом проверяем - создан он или нет 
	{
		cout << "Кошка не создана!\n";
	}
	else {
		Cat2.setName("Мурзик");
		Cat2.Print();
		Cat2.Voice();
		Cat2.Go();
		int StepV; //шаг изменения веса

		StepV = -1; //посадили на диету, но не правильно
		if (Cat2.setDownVes(StepV))
			cout << Cat2.getName().c_str() << " похудел на " << Cat2.getVes() << " кг. \n";
		else cout << "Ошибка ввода при уменьшении веса кота " << Cat2.getName().c_str() << "!\n";
		StepV = 1;//посадили на диету правильно
		if (Cat2.setDownVes(StepV))
			cout << Cat2.getName().c_str() << " похудел на " << Cat2.getVes() << " кг. \n";
		else cout << "Ошибка ввода при уменьшении веса кота " << Cat2.getName().c_str() << "!\n";

		StepV = -1; // стали кормить, но не правильно
		if (Cat2.setUpVes(StepV))
			cout << Cat2.getName().c_str() << " поправился на " << Cat2.getVes() << " кг. \n";
		else cout << "Ошибка ввода при увеличении веса кота " << Cat2.getName().c_str() << "!\n";
		StepV = 1; //кормят правильно
		if (Cat2.setUpVes(StepV))
			cout << Cat2.getName().c_str() << " поправился на " << Cat2.getVes() << " кг. \n";
		else cout << "Ошибка ввода при увеличении веса кота " << Cat2.getName().c_str() << "!\n";
	}

	cout << "\nСоздать 3-й объект кошка и поработать с ней\n"; // создаем экземпляр класса Кошка
	dogs Cat3("Сиамка", "Серая", 3, 2001);

	if (Cat3.getStatus() != OK) // прежде чем начать работу с объектом проверяем - создан он или нет 
	{
		cout << "Кошка не создана!\n";
	}
	else Cat3.Print();

	//А теперь все кошки будут что-то делать вместе!
	cout << "\n\n А теперь все кошки будут что-то делать вместе!\n\n";
	dogs* lCats;
	lCats = new dogs[3];

	lCats[0] = Cat1;
	lCats[1] = Cat2;
	lCats[2] = Cat3;

	for (int i = 0; i < 3; i++)  // Цикл организован таким образом, что если кошка задана неправильно, то сделать с ней ничего нельзя
		if (lCats[i].getStatus() == OK)
		{
			lCats[i].Voice();
			lCats[i].Go();
		}

	system("pause");
	return 0;
}