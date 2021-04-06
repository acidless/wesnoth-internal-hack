#include "HackModule.h"
#include "HackModuleHandler.h"
#include <vector>
#include <Windows.h>

HackModuleHandler::HackModuleHandler(std::vector<HackModule*> _hackModules) : hackModules(_hackModules) {}

void HackModuleHandler::initModules() {
	for (std::vector<HackModule*>::iterator it = hackModules.begin(); it != hackModules.end(); it++) {
		(*it)->execute();
	}
}