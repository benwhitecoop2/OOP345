//Ben White S# 128269172 Nov 7 2018 - Milestone 1 for OOP345
//#include "Item.h"
//files need to be moved down two folders to meet with solution
#include "Item.h"

Item::Item() {
	name = '\0';
	serialNumber = 0;
	Quantity = 0;
	description = '\0';
	field_width = 0;
}

Item::Item(std::string &record){
	bool more=true;
	size_t position = 0;
	size_t count = 0;
	Utilities extract;

	std::string temp;

	do {
		temp = extract.extractToken(record, position, more);
		position = position+temp.length()+1;

		if (count == 0) {
			name = temp;
		}else if (count == 1) {
			serialNumber = std::stoi(temp);
		}else if (count == 2) {
			Quantity = std::stoi(temp);
		}else if (count == 3) {
			description = temp;
		}

		count++;
	} while (more);


}

const std::string & Item::getName() const{
	return name;
}

const unsigned int Item::getSerialNumber(){
	return serialNumber++;
}

const unsigned int Item::getQuantity(){
	return Quantity;
}

void Item::updateQuantity(){
	if (Quantity>0) {
		Quantity--;
	}
}

void Item::display(std::ostream &ostr, bool full) const{
	ostr << name << std::setw(14-name.length())<< " [" << serialNumber << "] ";
	if (full) {
		if (Quantity>=10) {
			ostr << " Quantity "<< Quantity << " " << " Description: " << description;
		} else {
			ostr << " Quantity "<< Quantity << "  " << " Description: " << description;
		}
	}
	ostr << '\n';
}
