#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <map>

class Li
{
public:
	Li();
	~Li();
	bool load(string);
	void run();

private:
	const string identifier = "UM-MEAN-C";
};