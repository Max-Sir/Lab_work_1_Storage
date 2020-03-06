/*12.	 Структура «Склад»: наименование товара, цена, количество, процент торговой надбавки.*/
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include <list>
#include<string>

using namespace std;

namespace own
{
struct Storage
{
	enum type
	{
		Auto=1,Product
	};
	int type;
	union inner
	{
		struct Product_Storage
		{
			friend istream& operator>>(istream& in, Storage& st);
			friend ostream& operator<<(ostream& out, Storage& st);
			void set_name_of_culture(char* name_of_culture);

			void set_quantity_of_products(int quantity_of_products);

			void set_days_from_fresh_condition(int days_from_fresh_condition);

			void set_cost(double cost);

			void set_percent(int percent);

			void get_name_of_culture(char* name_of_culture);

			void get_quantity_of_products(int quantity_of_products);

			void get_days_from_fresh_condition(int days_from_fresh_condition);

			void get_cost(double cost);

			void get_percent(int percent);

			Product_Storage(char* name_of_culture, int quantity_of_products = 0, int days_from_fresh_condition = 2020, double cost = 0, double percent = 0)
			{
				this->name_of_culture = name_of_culture;
				this->quantity_of_products = quantity_of_products;
				this->days_from_fresh_condition = days_from_fresh_condition;
				this->cost = cost;
				this->percent = percent;
			}
		private:
			string name_of_culture;
			int quantity_of_products;
			int days_from_fresh_condition;
			double cost;
			double percent;
			
		}P;

		struct Auto_Storage
		{
			friend istream& operator>>(istream& in,Storage& st);
			friend ostream& operator<<(ostream& out, Storage& st);
			void set_cars_model(char* cars_model);

			void set_quantity_of_cars(int quantity_of_cars);

			void set_year_of_release(int year_of_release);

			void set_cost(double cost);

			void set_percent(int percent);

			void get_cars_model(char* cars_model);

			void get_quantity_of_cars(int quantity_of_cars);

			void get_year_of_release(int year_of_release);

			void get_cost(double cost);

			void get_percent(int percent);

			Auto_Storage(char* cars_model,int quantity_of_cars=0,int year_of_release=2020,double cost=0,double percent=0)
			{
				this->cars_model = cars_model;
				this->quantity_of_cars = quantity_of_cars;
				this->year_of_release = year_of_release;
				this->cost = cost;
				this->percent = percent;
			}
		private:
			string cars_model;
			int quantity_of_cars;
			int year_of_release;
			double cost;
			double percent;
		}A;
	}y;
};


istream& operator >>(istream& in, Storage& st)
{
	if(st.type==Storage::type::Auto)
	{
		in >> st.y.A.cars_model;
		if (st.y.A.cars_model == ";")
		{
			in >> st.y.A.quantity_of_cars;
			in >> st.y.A.year_of_release;
			in >> st.y.A.cost;
			in >> st.y.A.percent;
		}
	}
	else
	{
		in >> st.y.P.name_of_culture;
		if (st.y.P.name_of_culture != ";")
		{
			in >> st.y.P.quantity_of_products;
			in >> st.y.P.days_from_fresh_condition;
			in >> st.y.P.cost;
			in >> st.y.P.percent;
		}
	}
	return in;
}

ostream& operator<<(ostream& out, Storage& st)
{
	if (st.type == Storage::type::Auto)
	{
		out << st.y.A.cars_model;
		out << st.y.A.quantity_of_cars;
		out << st.y.A.year_of_release;
		out << st.y.A.cost;
		out << st.y.A.percent;
	}
	else
	{
		out << st.y.P.name_of_culture;
		out << st.y.P.quantity_of_products;
		out << st.y.P.days_from_fresh_condition;
		out << st.y.P.cost;
		out << st.y.P.percent;
	}
	return out;
}

void Storage::inner::Product_Storage::set_name_of_culture(char* name_of_culture)
{
	this->name_of_culture = name_of_culture;
}

void Storage::inner::Product_Storage::set_quantity_of_products(int quantity_of_products)
{
	this->quantity_of_products = quantity_of_products;
}

void Storage::inner::Product_Storage::set_days_from_fresh_condition(int days_from_fresh_condition)
{
	this->days_from_fresh_condition = days_from_fresh_condition;
}

void Storage::inner::Product_Storage::set_cost(double cost)
{
	this->cost = cost;
}

void Storage::inner::Product_Storage::set_percent(int percent)
{
	this->percent = percent;
}

void Storage::inner::Product_Storage::get_name_of_culture(char* name_of_culture)
{
	this->name_of_culture = name_of_culture;
}

void Storage::inner::Product_Storage::get_quantity_of_products(int quantity_of_products)
{
	this->quantity_of_products = quantity_of_products;
}

void Storage::inner::Product_Storage::get_days_from_fresh_condition(int days_from_fresh_condition)
{
	this->days_from_fresh_condition = days_from_fresh_condition;
}

void Storage::inner::Product_Storage::get_cost(double cost)
{
	this->cost = cost;
}

void Storage::inner::Product_Storage::get_percent(int percent)
{
	this->percent = percent;
}

void Storage::inner::Auto_Storage::set_cars_model(char* cars_model)
{
	this->cars_model = cars_model;
}

void Storage::inner::Auto_Storage::set_quantity_of_cars(int quantity_of_cars)
{
	this->quantity_of_cars = quantity_of_cars;
}

void Storage::inner::Auto_Storage::set_year_of_release(int year_of_release)
{
	this->year_of_release = year_of_release;
}

void Storage::inner::Auto_Storage::set_cost(double cost)
{
	this->cost = cost;
}

void Storage::inner::Auto_Storage::set_percent(int percent)
{
	this->percent = percent;
}

void Storage::inner::Auto_Storage::get_cars_model(char* cars_model)
{
	this->cars_model = cars_model;
}

void Storage::inner::Auto_Storage::get_quantity_of_cars(int quantity_of_cars)
{
	this->quantity_of_cars = quantity_of_cars;
}

void Storage::inner::Auto_Storage::get_year_of_release(int year_of_release)
{
	this->year_of_release = year_of_release;
}

void Storage::inner::Auto_Storage::get_cost(double cost)
{
	this->cost = cost;
}

void Storage::inner::Auto_Storage::get_percent(int percent)
{
	this->percent = percent;
}
}


int menu()
{
	int er;
	cout << "Enter:\n";
	cout << "1-delete\n";
	cout << "2-add\n";
	cout << "3-for change\n";
	cout << "4-for output of notes\n";
	cout << "5-for search \n";
	cout << "6-exit\n";
	cin >> er;
	return er;
}


using own::Storage;

int main(int argc, char* argv[])
{
	list<Storage> l;
	int check_name;

	
	printf("Enter type of new Storage(1-Auto,2-Product): ");
	scanf_s("%d", &check_name);
	fseek(stdin, 0, 2);

	char c = 0;
	while ((int)(c = _getch() - '0') != -22)
		cout << 5;
	
	
}
