#include "headers/MyException.hpp"
#include <cstdlib>
#include <iostream>

using namespace MyExceptionCharStringRepresentation;

int main()
{
	try
	{
		throw Exception("Unfixable bug", __FILE__, __PRETTY_FUNCTION__, __LINE__, 
			  Exception(     "Kind off", __FILE__, __PRETTY_FUNCTION__, __LINE__,
			  Exception(     "No jokes", __FILE__, __PRETTY_FUNCTION__, __LINE__,
			  Exception(          "...", __FILE__, __PRETTY_FUNCTION__, __LINE__,
			  Exception(          "Neh", __FILE__, __PRETTY_FUNCTION__, __LINE__)))));
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "unexpected exception" << std::endl;
	}

	std::cin.ignore();

	return EXIT_SUCCESS;
}