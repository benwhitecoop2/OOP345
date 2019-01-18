#include "Task.h"
#include <algorithm>

Task::Task(std::string& input){
	pNextTask = nullptr;
	
}

void Task::RunProcess(std::ostream& ostr){//finish this later
	if (!Orders.empty) {
		CustomerOrder temp = Orders.back();
		if (!temp.getOrderFillState()) {//if the order is unfilled 
			temp.fillItem(*this, ostr);
		}//if the order is filled, do nothing
	}
}

bool Task::MoveTask(){
	if (Orders.back.getOrderFillState()) {
		pNextTask->Orders.push_back(Orders.back);//moves order to next task
		Orders.pop_back();//removes moved element
	}
	if (!Orders.empty) {
		return true;
	}else{
		return false;
	}
}

void Task::setNextTask(Task& provided){
	pNextTask = &provided;
}

bool Task::getCompleted(CustomerOrder& src){
	if (Orders.empty) {
		return false;
	}
	else {
		src = std::move(Orders.back());
		return true;
	}
}

void Task::Validate(std::ostream& os){
	//write the name of the item
	os << this->getName() << '\n';
	if (pNextTask) {
		os << pNextTask->getName() <<'\n';
	}
}

Task& Task::operator+=(CustomerOrder&& newOrder){
	Orders.push_front(newOrder);
}
