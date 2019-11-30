#include <stdio.h>
#include <iostream>
#include <string>
std::string makeFinalMessage(std::string* codewords, int* data, int numCode, int numErr);

std::string makeFinalMessage(std::string* codewords, int* data, int numCode, int numErr)
{
	
	std::string finalStr = "";
	
	for(int i = 0; i < numCode; i++)
	{
		finalStr += data[i];
	}
	for(int i = 0; i < numErr; i++)
	{
		finalStr += codewords[i];
	}
	if(numCode = 28)
	{
		finalStr += "0000000";
	}
	std::cout << finalStr;
	return finalStr;
	

}
