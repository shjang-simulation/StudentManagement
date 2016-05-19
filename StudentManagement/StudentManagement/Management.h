#pragma once

#include <vector>
#include <fstream>
#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string_regex.hpp>
#include <string>
#include <iostream>

class Management
{
public:
	std::string separation_str_;
	std::vector<std::vector<std::string>> data_lines_;

public:
	Management()
		: separation_str_("\t")
	{}

	Management(const std::string filename)
		: separation_str_("\t")
	{
		readANSIFile(filename);
	}

	std::vector<std::string> parseLineToPhrase(const std::string& input_line)
	{
		using namespace std;
		using namespace boost;

		vector<std::string> pharases;
		algorithm::split_regex(pharases, input_line, regex("\t"));

		return pharases;
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
		while (std::getline(ifs, input_line))
		{
			data_lines_.push_back(parseLineToPhrase(input_line));
		}
		ifs.close();
	}

	void printPharases(const std::vector<std::string>& phrases)
	{
		for (int i = 0; i < (int)phrases.size(); i++)
		{
			std::cout << "\"" << phrases[i] << "\"";
			if (i != (int)phrases.size() - 1) std::cout << ",";
		}

		std::cout << std::endl;
	}

	
};