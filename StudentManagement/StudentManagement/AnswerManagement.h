#pragma once

#include <vector>
#include <fstream>
#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string_regex.hpp>
#include <string>
#include <iostream>
#include "AnswerData.h"

class AnswerManagement
{
public:
	std::string separation_str_;
	std::vector<std::string> question_line_;
	std::vector<std::string> answer_line_;
	std::vector<AnswerData> answer_data_;

public:
	AnswerManagement()
		: separation_str_("\t")
	{}

	AnswerManagement(const std::string filename)
		: separation_str_("\t")
	{
		readANSIFile(filename);
		saveData();
	}

	void readANSIFile(const std::string filename)
	{
		std::ifstream ifs(filename);

		if (!ifs.is_open())
		{
			std::cout << "File was not opened." << std::endl;

			return;
		}

		std::string input_line;

		if (std::getline(ifs, input_line))
			question_line_ = parseLineToPhrase(input_line);
		if (std::getline(ifs, input_line))
			answer_line_ = parseLineToPhrase(input_line);
		
		
		ifs.close();
	}

	std::vector<std::string> parseLineToPhrase(const std::string& input_line)
	{
		using namespace std;
		using namespace boost;

		vector<std::string> pharases;
		algorithm::split_regex(pharases, input_line, regex("\t"));

		return pharases;
	}

	void saveData()
	{
		for (int ix = 0; ix < question_line_.size(); ix++)
		{	
			int index = answer_line_[ix].find("%cs ");
			if(index != -1)
				answer_line_[ix].erase(index, index+4);
			index = 0;
			while (index != -1)
			{
				index = answer_line_[ix].find("%or ", index);
				if (index != -1)
					answer_line_[ix].replace(index, 3, "또는");
			}
			answer_data_.push_back(AnswerData(question_line_[ix], answer_line_[ix]));
		}
	}
	void writeData(const std::string& path)
	{
		std::ofstream ofs(path);

		for (int ix = 0; ix < (int)answer_data_.size(); ix++)
		{
			ofs << ix+1 << ". " << answer_data_[ix].question_ << std::endl;
			ofs << "정답: " << answer_data_[ix].answer_ << std::endl;
		}
		
		ofs.close();
	}
};