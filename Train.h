#pragma once
#include<iostream>
using std::istream;
using std::ostream;

#include<string>
using std::string;

#include<vector>
using std::vector;

#include<fstream>
using std::ifstream;
using std::ofstream;

#include<iterator>
#include<algorithm>
#include<set>
using std::set;

class Train
{
public:
	Train() = default;
	~Train() = default;

	string getDest() const { return destination; }
	string getNumber() const { return number; }
	bool getExpress() const { return express; }
	int getHours() const { return hours; }
	int getMin() const { return minutes; }

	const bool operator<(const Train&) const;
	Train& operator=(string str)
	{
		this->destination = str;
		return *this;
	}

	friend ostream& operator<<(ostream&, const Train&);
	friend istream& operator>>(istream&, Train&);

private:
	string destination;
	string number;
	bool express;
	int hours;
	int minutes;
};

ostream& operator<<(ostream& out, const Train& tr)
{
	string exp;
	tr.getExpress() ? exp = " yes " : exp = " no ";

	out << "Destination: " << tr.getDest() << "  Train number:" << tr.getNumber()
		<< "  Express: " << exp << "  HH "
		<< tr.getHours() << "  MM " << tr.getMin() << std::endl;

	return out;
}
istream& operator>>(istream& in, Train& tr)
{
	in >> tr.destination >> tr.number >> tr.express
		>> tr.hours >> tr.minutes;

	return in;
}

const bool Train::operator<(const Train& tr1) const
{
	if (getHours() < tr1.getHours())
		return true;
	else if (getHours() == tr1.getHours())
	{
		if (getMin() < tr1.getMin())
			return true;
		else
			return false;
	}
	else
		return false;
}
