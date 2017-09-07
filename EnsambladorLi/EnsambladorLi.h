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
	
	map<string, unsigned int> variables;
	map<string, unsigned int> tags;
	map<string, unsigned int> stringSize;
	map<string, unsigned int> arraySize;

	unsigned int nextMemorySlot; //next available data segment
	unsigned int currentByte; //current written byte

	string code;
	char codeSize[2] = { 0,100 };
	char dataSize[2] = { 0,100 };


	void addVar(string); //inserts 2 bytes as an address of any type var indicated
	void addToCode(unsigned int); //writes an unsigned int into 2 bytes
	void addToCode(unsigned int, int); //writes an unsigned int as 4,3,2 or 1 byte depending on the 2nd parameter
	bool validateDirection(unsigned int); //validates that the direction is not out of memory
};