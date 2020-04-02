#include <iostream>
#include <random>
#include <exception>
#include <memory>

/* ZAD 1 Jednym z g��wnych cel�w korzystania ze inteligentnych wska�nik�w 
* jest automatyczne zwalnianie przez nie pami�ci.
* Popraw ten program, tak by nie korzysta� z surowych wska�nik�w 
* poprzez zamienienie ich na wska�niki inteligentne.
*/

struct Odd_exception : public std::exception {
	const char* what_is_it() const throw () {
		return "This is odd exception";
	}
};

bool check_if_even(int number) {
	if (number % 2 != 0)
		throw Odd_exception();
	return true;
}

int main()
{
	int* array;
	array = new int[50];
	for (int i = 0; i < 50; i++) {
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> distribution(1,100);
		array[i] = distribution(rng);
	}
	try {
		check_if_even(array[0]);
		delete[]array;
		std::cout << "Pamiec zostala zwolniona!" << std::endl;
	}
	catch (Odd_exception & e) {
		/*Je�li wyst�pi wyj�tek pami�� zajmowana przez wska�niki nie zostanie zwolniona
		i powstanie wyciek pami�ci*/
		std::cout << "Pamiec nie zostanie zwolniona" << std::endl;
	}
	
	return 0;
}