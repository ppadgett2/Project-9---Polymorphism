// Author: Parker Padgett
// Assignment: Project 9 - Polymorphism
// Date: 4/11/2022


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

class Employee {
public: 
	// Sets
	void setType(string text)
	{
		type = text;
	}
	void setFirstName(string text)
	{
		fName = text;
	}
	void setLastName(string text)
	{
		lName = text;
	}
	void setHoursWorked(double num)
	{
		hours = num;
	}
	void setWage(double num)
	{
		wage = num;
	}
	void setDeductions(int number)
	{
		deductions = number;
	}
	// payroll for hourly employee
	void payroll(double wage, double hours, double deductions)
	{
		if (hours > 40)
		{
			oTimeWage = wage * 1.5;
			oTimeHours = hours - 40;
			oTimePay = oTimeWage * oTimeHours;

			gPay = oTimePay + (40 * wage);
		}
		else
		{
			gPay = hours * wage;
		}

		if (deductions <= 0)
			tax = .30;
		else if (deductions <= 1)
			tax = .25;
		else if (deductions <= 2)
			tax = .20;
		else if (deductions <= 3)
			tax = .15;
		else
			tax = .10;

		tax = tax * gPay;

		nPay = gPay - tax;
	}
	// payroll for salary employee
	void payroll(double wage, double deductions)
	{
		gPay = wage;
		nPay = gPay;

		if (deductions <= 0)
			tax = .30;
		else if (deductions <= 1)
			tax = .25;
		else if (deductions <= 2)
			tax = .20;
		else if (deductions <= 3)
			tax = .15;
		else
			tax = .10;

		tax = tax * gPay;

		nPay = gPay - tax;
	}

	// output for hourly employee
	void output(string fName, string lName, double hours, double wage, int deductions, double tax, double oTimeWage, double oTimeHours, double oTimePay, double gPay, double nPay)
	{
		cout << "Name: " << fName << " " << lName << endl;
		cout << "Hourly Wage: $" << wage << endl;
		cout << "Hours Worked: " << hours << endl;
		if (hours > 40)
		{
			cout << "Overtime Hours: " << oTimeHours << endl;
			cout << "Overtime Pay: $" << oTimePay << endl;
		}
		cout << "Number of Deductions: " << deductions << endl;
		cout << "Gross Pay: $" << gPay << endl;
		cout << "Tax: $" << tax << endl;
		cout << "Net Pay: $" << nPay << endl << endl;
	}
	// output for salary employee
	void output(string fName, string lName, double wage, int deductions, double gPay, double tax, double nPay)
	{
		cout << "Name: " << fName << " " << lName << endl;
		cout << "Wage: $" << wage << endl;
		cout << "Number of Deductions: " << deductions << endl;
		cout << "Gross Pay: $" << gPay << endl;
		cout << "Tax: $" << tax << endl;
		cout << "Net Pay: $" << nPay << endl << endl;
	}

	// Gets
	string getType()
	{
		return type;
	}
	string getFirstName()
	{
		return fName;
	}
	string getLastName()
	{
		return lName;
	}
	double getHours()
	{
		return hours;
	}
	double getWage()
	{
		return wage;
	}
	double getOverTimeWage()
	{
		return oTimeWage;
	}
	double getOverTimeHours()
	{
		return oTimeHours;
	}
	double getOverTimePay()
	{
		return oTimePay;
	}
	int getDeductions()
	{
		return deductions;
	}
	double getTax()
	{
		return tax;
	}
	double getGrossPay()
	{
		return gPay;
	}
	double getNetPay()
	{
		return nPay;
	}

private: 
	// Variables
	string type, fName, lName;
	double hours, wage, gPay, nPay, tax, oTimeWage, oTimeHours, oTimePay;
	int deductions;
};


int main()
{
	string temp;
	double num;
	int number, choice;

	Employee info[10];
	for (int a = 0; a <= 1; a++)
	{
		cout << "What type of employee are you? Enter 1 for hourly or 2 for salary. ";
		cin >> choice;

		cout << "What is your first name? ";
		cin >> temp;
		info[a].setFirstName(temp);

		cout << "What is your last name? ";
		cin >> temp;
		info[a].setLastName(temp);

		if (choice == 1)
		{
			cout << "What is your hourly wage? ";
			cin >> num;
			info[a].setWage(num);

			cout << "How many hours did you work? ";
			cin >> num;
			info[a].setHoursWorked(num);
		}
		else
		{
			cout << "What is your wage? ";
			cin >> num;
			info[a].setWage(num);
		}

		cout << "How many deductions do you claim? 0-3? ";
		cin >> number;
		info[a].setDeductions(number);


		// output
		if (choice == 1)
		{
			info[a].payroll(info[a].getWage(), info[a].getHours(), info[a].getDeductions());
			info[a].output(info[a].getFirstName(), info[a].getLastName(), info[a].getHours(), info[a].getWage(), info[a].getDeductions(), info[a].getTax(), info[a].getOverTimeWage(), info[a].getOverTimeHours(), info[a].getOverTimePay(), info[a].getGrossPay(), info[a].getNetPay());

		}
		else
		{
			info[a].payroll(info[a].getWage(), info[a].getDeductions());
			info[a].output(info[a].getFirstName(), info[a].getLastName(), info[a].getWage(), info[a].getDeductions(), info[a].getGrossPay(), info[a].getTax(), info[a].getNetPay());
		}
	}
	

	return 0;
}