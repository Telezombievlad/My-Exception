#include "headers/MyException.hpp"
#include <csdtlib>
#include <iostream>


int main()
{
	try
	{
		throw MyException("Get rect", __FILE__, "int main()", __LINE__);
	}
	catch (const std::exception& ex)
	{
		std::cout << rx.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "unexpected exception" << std::endl;
	}

	std::cin.ignore();

	return EXIT_SUCCESS;
}