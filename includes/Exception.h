//
// Created by Harriet Barrett on 14/02/2020.
//
#ifndef LAB_1_V2_EXCEPTION_H
#define LAB_1_V2_EXCEPTION_H

#include <string>

class Exception : public std::exception
{
private:
	char * errorMessage;
public:
	Exception(char *errorMessage);

	char *getErrorMessage() const;
};



class UserInputException : public Exception
{
public:
	UserInputException(char *errorMessage);
};

#endif //LAB_1_V2_EXCEPTION_H
