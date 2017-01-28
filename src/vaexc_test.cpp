#include "VaException.hpp"

#include <iostream>
#include <cstdlib>

int main()
{
	try
	{
		using namespace VaExc; 
		throw Exception(ArgMsg("Mah message with nuuumbers: %d", 228), 10_line, "Succ"_file, "You"_func, "Get rekt"_msg,
			  Exception("You really suck"_msg));
	}
	catch (VaExc::Exception& exc)
	{
		std::cout << exc.what() << std::endl;
	}

	return EXIT_SUCCESS;
}