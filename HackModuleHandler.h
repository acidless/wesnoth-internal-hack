#pragma once
#include "HackModule.h"
#include <vector>

class HackModuleHandler {
private:
	std::vector<HackModule*> hackModules;
public:
	HackModuleHandler(std::vector<HackModule*> _hackModules);

	void initModules();
};