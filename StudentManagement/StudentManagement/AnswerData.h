#pragma once
#include <iostream>
#include <vector>

class AnswerData
{
public:
	std::string question_;
	std::string answer_;
	
public:
	AnswerData(const std::string q, const std::string a)
		: question_(q), answer_(a)
	{}

};