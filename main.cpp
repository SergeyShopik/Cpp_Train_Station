#include"Train.h"

int main()
{
	vector<Train> array;
	set<Train> trains;
	ifstream in("trains.txt");

	std::istream_iterator<Train> inIt(in);
	std::istream_iterator<Train> curIt;

	//first option
	//std::copy(inIt, curIt, std::back_inserter(array));
	//std::copy(array.begin(), array.end(), std::ostream_iterator<Train>(std::cout));

	/*std::sort(array.begin(), array.end(), [](const Train& tr, const Train& tr1)
		{
			if (tr.getHours() < tr1.getHours())
				return true;
			else if (tr.getHours() == tr1.getHours())
			{
				if (tr.getMin() < tr1.getMin())
					return true;
				else
					return false;
			}
			else
				return false;
		});*/
	
	// read into associative container, sorting by key performs when adding
	std::copy(inIt, curIt, inserter(trains, trains.begin()));
	std::copy(trains.begin(), trains.end(), back_inserter(array));
	//std::copy(array.begin(), array.end(), std::ostream_iterator<Train>(std::cout));


	/*string city;
	std::cin >> city;
	std::copy_if(array.begin(), array.end(), std::ostream_iterator<Train>(std::cout),
		[city](const Train& tr)
		{
			return tr.getDest() == city;
		});*/

	string whichCity, destReplace;
	std::cout << "Enter city to replace destination: ";
	std::cin >> whichCity >> destReplace;
	std::replace_if(array.begin(), array.end(), [destReplace](const Train& tr) 
		{
			return tr.getDest() == destReplace;
		}, whichCity);

	std::copy(array.begin(), array.end(), std::ostream_iterator<Train>(std::cout));

	return 0;
}