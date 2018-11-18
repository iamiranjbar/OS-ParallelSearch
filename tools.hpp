#ifndef TOOLS_HPP
#define TOOLS_HPP 

#include <iostream>
#include <vector>

class Tools{
public:
	static std::vector<std::string> split(std::string statement , const char* delimeters);
private:
	Tools();
};

#endif