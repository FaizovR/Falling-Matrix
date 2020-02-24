//
// Created by Harriet Barrett on 14/02/2020.
//

#include "../includes/Exception.h"

Exception::Exception(char *errorMessage) : errorMessage(errorMessage) {}

char *Exception::getErrorMessage() const {
	return errorMessage;
}

UserInputException::UserInputException(char *errorMessage) : Exception(errorMessage) {}
