#ifndef MY_EXCEPTION_HPP_INCLUDED
#define MY_EXCEPTION_HPP_INCLUDED

#include <exception>
#include <string>

final struct MyException : public std::exception
{
	public:
		// Constructors:
			explicit MyException(const std::string& whatArg, const char* file, const char* function, unsigned int line) :
				std::exception(whatArg),
				whatArg_ (whatArg)
			{
				whatArg += std::string("\nIn file: "	) + std::string(	file);
				whatArg += std::string("\nIn function: ") + std::string(function);
				whatArg += std::string("\nIn line: "	) + std::to_string( line);	
			}

			explicit MyException(const std::string& whatArg, const char* file, const char* function, unsigned int line, const std::exception& deeperException) :
				MyException(whatArg, file, function, line)
			{
				whatArg += std::string("\n\nCaused by:\n") + std::string(deeperException.what());
			}

			explicit MyException(const char* whatArg, const char* file, const char* function, unsigned int line) :
				MyException(std::string(whatArg), file, function, line)
			{}

			explicit MyException(const char* whatArg, const char* file, const char* function, unsigned int line, const std::exception& deeperException) :
				MyException(std::string(whatArg), file, function, line, deeperException)
			{}

			
			~MyException() override;

		// Functions:
			const char* what() const noexcept override
			{
				return whatArg_;
			}

	private:
		// Variables:
			std::string whatArg_;
};

#endif /*MY_EXCEPTION_HPP_INCLUDED*/