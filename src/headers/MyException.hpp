#ifndef MY_EXCEPTION_HPP_INCLUDED
#define MY_EXCEPTION_HPP_INCLUDED

final struct MyException : public std::exception
{
	public:
		// Constructors:
			explicit MyException(const std::string& whatArg, const char* file, const char* function, unsigned int line, const std::exception* deeperException = nullptr);
			explicit MyException(const char* 		whatArg, const char* file, const char* function, unsigned int line, const std::exception* deeperException = nullptr);
			
			~MyException() override;

		// Functions:
			const char* what() const override;

	private:
		// Variables:
			const char* whatArg_;
			const char* file_;
			const char* function_;
			unsigned int line_;
			const std::exception* deeperException_;
};

#endif /*MY_EXCEPTION_HPP_INCLUDED*/