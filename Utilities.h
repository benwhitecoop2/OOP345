//Ben White S# 128269172 Nov 7 2018 - Milestone 1 for OOP345
#pragma once
#include <string>
#include <fstream>
#include <iostream>

	class Utilities {
		size_t field_width;           // maximum field width needed 
		static char delimiter;        // field delimiter character

	public:
		Utilities();
		void setFieldWidth(size_t);
		size_t getFieldWidth() const;
		const std::string extractToken(const std::string&, size_t&, bool&);
		static void setDelimiter(const char);
		const char getDelimiter() const;
	};