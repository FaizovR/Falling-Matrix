//
// Created by Harriet Barrett on 14/02/2020.
//
#ifndef LAB_1_V2_EXCEPTION_H
#define LAB_1_V2_EXCEPTION_H

#include <string>

class Exception : public std::exception
{
private:
	std::string error_message;
public:
	const std::string &getErrorMessage() const;

	Exception(const std::string errorMessage);
};


#endif //LAB_1_V2_EXCEPTION_H
