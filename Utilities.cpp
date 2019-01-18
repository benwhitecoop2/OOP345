//Ben White S# 128269172 Nov 7 2018 - Milestone 1 for OOP345
#include "Utilities.h"


char Utilities::delimiter = '\0';

Utilities::Utilities(){
	field_width = 1;
}

void Utilities::setFieldWidth(size_t fw){
	field_width = fw;
}

size_t Utilities::getFieldWidth() const{
	return field_width;
}

const std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more){
	std::string token;
	std::string exitTest;

	size_t end_pos = str.find(delimiter, next_pos);

	token = str.substr(next_pos,end_pos-next_pos);

	if (field_width < token.length()) {
		field_width = token.length();
	}

	exitTest = str.substr(next_pos+token.length());

	if (exitTest.empty()) {
		more = false;
	}

	return token;
}

void Utilities::setDelimiter(const char r){
	delimiter = r;
}

const char Utilities::getDelimiter() const{
	return delimiter;
}
