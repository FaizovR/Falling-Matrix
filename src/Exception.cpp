//
// Created by Harriet Barrett on 14/02/2020.
//

#include "../includes/Exception.h"

Exception::Exception(const std::string errorMessage) {
	this->error_message = errorMessage;
}

const std::string &Exception::getErrorMessage() const {
	return error_message;
}
