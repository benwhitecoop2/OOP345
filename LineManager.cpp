#include "LineManager.h"

LineManager::LineManager(std::string& fileName, std::vector<Task*>& _AssemblyLine, std::vector<CustomerOrder>& _ToBeFilled){
	//read the filename and set up all the pNextTasks in the task objects
	std::ifstream input(fileName);
	bool more = true;
	size_t next_pos = 0;
	std::string str;
	while (!input.eof) {
		str = input.get();
	}
	do {
		std::string token,exitTest;
		size_t end_pos = str.find('|', next_pos);
		token = str.substr(next_pos, end_pos - next_pos);
		exitTest = str.substr(next_pos + token.length());
		if (exitTest.empty()) {
			more = false;
		}
		//create a task with the token
		Task tempTask(token);
		_AssemblyLine.push_back(&tempTask);
	} while (more);
	//validate that all the tasks have been linked correctly
	for (size_t i = 0;i < _AssemblyLine.size();i++) {
		if (i+1<_AssemblyLine.size()) {
			_AssemblyLine[i]->setNextTask(*_AssemblyLine[i + 1]);
		}
	}
	//move all CustomerOrder objects into the ToBeFilled queue
	
	//copy all Task objects into the AssemblyLine container
	AssemblyLine = _AssemblyLine;
}

bool LineManager::Run(std::ostream& os){
	return false;
	//if there are any CustomerOrder objects in ToBeFilled, move the last CustomerOrder to the start of the AssemblyLine
	if (!ToBeFilled.empty) {

	}
	//loop through all Tasks on the AssemblyLine and run one cycle of Tasks process
	for (size_t i = 0;i < AssemblyLine.size();i++) {
		AssemblyLine[i]->RunProcess(os);
	}
	//loop through all Tasks on the AssemblyLine and move the CustomerOrder objects down the line

	//hint:if they are completed, pop them off the current task and push them on to the pNextTask

	/*if(*all CustomerOrder objects have been filled){
		return true;
	}else{
		return false;//go around again
	}*/
}
