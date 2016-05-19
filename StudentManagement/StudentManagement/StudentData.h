#pragma once
#include <string>
#include <vector>

class StudentData
{
public:
	std::string student_id;
	std::string score_;

public:
	StudentData()
		: score_(0)
	{}

	StudentData(const std::vector<std::string>& input)
		: student_id(input[0]), score_(input[1])
	{}
};