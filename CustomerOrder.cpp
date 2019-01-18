#include "CustomerOrder.h"
#include "Utilities.h"
#include "Item.h"
#include <vector>

CustomerOrder::CustomerOrder(){
	Name = '\0';
	Product = '\0';
	ItemCount = 0;
	ItemList = nullptr;
	field_width = 0;
}

CustomerOrder::CustomerOrder(std::string& record){
	bool more=true;
	size_t position = 0;
	size_t count = 0;
	Utilities extract;

	std::string temp;

	do {
		temp = extract.extractToken(record, position, more);
		position = position + temp.length() + 1;

		if (count == 0) {
			Name = temp;
		}else if (count == 1) {
			Product = temp;
		}

		count++;
	} while (more);
	
	//getting rows
	ItemCount = count-2;
	position = 0 + (Name.length() + Product.length()+2);
	count = 0;
	//dynamically allocate an array of ItemInfo's the size of the amount of items in the source string
	//note - amount of items is always (total delimiters in string - 2)
	ItemList = new ItemInfo*[ItemCount];
	more = true;
	//get the remaining items in the record
	do {
		temp = extract.extractToken(record, position, more);
		position = position + temp.length() + 1;
		ItemList[count] = new ItemInfo(temp);
		count++;//count should never go above ItemCount
		if (count>ItemCount) {
			more = false;
		}
	} while (more);
}

void CustomerOrder::fillItem(Item& item_, std::ostream & os) {
	for (size_t i = 0;i < ItemCount;i++) {
		if (getItemAtIndex(i)->ItemName==item_.getName()) {
			getItemAtIndex(i)->SerialNumber = item_.getSerialNumber();
			getItemAtIndex(i)->FillState = true;
			//os << "9999 - 3930 - 9999" << '\n';//placeholder!
			os << "Filled " << Name << ", " << Product <<"["<< getItemAtIndex(i)->ItemName <<"]"<< '\n';
			i = ItemCount + 1;
		}
	}
}

CustomerOrder::~CustomerOrder(){
	Name = '\0';
	Product = '\0';
	ItemCount = 0;
	ItemList = nullptr;
	field_width = 0;

	for (size_t i=0;i < ItemCount;i++) {
		ItemList[i] = nullptr;
		delete ItemList[i];
	}
	ItemList = nullptr;
	delete ItemList;
}

ItemInfo* CustomerOrder::getItemAtIndex(const size_t& index){
	return ItemList[index];
}

CustomerOrder::CustomerOrder(CustomerOrder&& mv) {
	Name = '\0';
	Product = '\0';
	ItemCount = 0;
	ItemList = nullptr;
	field_width = 0;

	*this = std::move(mv);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& mv){
	if (this != &mv) {

		//loop and delete all iteminfo objects
		//delete your 1D array of addresses
		for (size_t i = 0;i < ItemCount;i++) {
			ItemList[i] = 0;
			delete ItemList[i];
		}

		ItemList = nullptr;
		delete ItemList;

		Name = mv.Name;
		Product = mv.Product;
		ItemCount = mv.ItemCount;
		field_width = mv.field_width;
		
		//Transfer Ownership of the data
		ItemList = std::move(mv.ItemList);

		mv.ItemList = nullptr;
	}
	return *this;
}

bool CustomerOrder::getOrderFillState(){
	bool foundUnfilled = true;
	for (size_t i=0;i < ItemCount;i++) {
		if (getItemAtIndex(i)->FillState==false) {
			foundUnfilled = false;
		}
	}
	return foundUnfilled;
}

bool CustomerOrder::getItemFillState(std::string itemName){
	for (size_t i=0;i < ItemCount;i++) {
		if (getItemAtIndex(i)->ItemName==itemName) {
			return getItemAtIndex(i)->FillState;
		}
	}
	//if no item with that name is found
	return false;
}

void CustomerOrder::Display(std::ostream & os){
	os << Name << '\n';
	os << Product << '\n';

	//std::cout << Name << '\n';
	//std::cout << Product << '\n';
	for (size_t i = 0;i < ItemCount;i++) {
		if (ItemList[i]!=nullptr) {
			os << "[0] " << ItemList[i]->ItemName << " - ";
		   // std::cout << "[0] " << ItemList[i]->ItemName << " - ";
			if (getItemFillState(ItemList[i]->ItemName) == true) {
				os << "FILLED" << '\n';
				//std::cout << "FILLED" << '\n';
			}
			else {
				os << "MISSING" << '\n';
				//std::cout << "MISSING" << '\n';
			}
		}
	}
}