#ifndef HEADER_GUARD_STD_STRING_REPRESENTATION_EXCEPTION_HPP_INCLUDED
#define HEADER_GUARD_STD_STRING_REPRESENTATION_EXCEPTION_HPP_INCLUDED

#include <exception>
#include <string>

namespace MyExceptionStdStringRepresentation
{
	struct Exception final : public std::exception
	{
	public:
		// Constructors:
			explicit MyException(const std::string& whatArg, const char* file, const char* function, unsigned int line) :
				whatArg_ (whatArg)
			{
				whatArg_ =  std::string("Exception: "	 ) + whatArg_; 
				whatArg_ += std::string("\nIn file: "	 ) + std::string(	 file);
				whatArg_ += std::string("\nIn function: ") + std::string(function);
				whatArg_ += std::string("\nIn line: "	 ) + std::to_string( line);	
			}

			explicit MyException(const std::string& whatArg, const char* file, const char* function, unsigned int line, const std::exception& deeperException) :
				MyException(whatArg, file, function, line)
			{
				whatArg_ += std::string("\n\nCaused by:\n") + std::string(deeperException.what());
			}

			explicit MyException(const char* whatArg, const char* file, const char* function, unsigned int line) :
				MyException(std::string(whatArg), file, function, line)
			{}

			explicit MyException(const char* whatArg, const char* file, const char* function, unsigned int line, const std::exception& deeperException) :
				MyException(std::string(whatArg), file, function, line, deeperException)
			{}

			virtual ~MyException() override = default;

		// Functions:
			virtual const char* what() const noexcept override
			{
				return whatArg_.c_str();
			}

	private:
		// Variables:
			std::string whatArg_;
	};
}

#endif /*HEADER_GUARD_STD_STRING_REPRESENTATION_EXCEPTION_HPP_INCLUDED*/