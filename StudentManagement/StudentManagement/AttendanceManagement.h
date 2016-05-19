#pragma once

#include <vector>
#include <fstream>
#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string_regex.hpp>
#include <string>
#include <iostream>

class AttandenceManagement
{
public:
	std::string separation_str_;

public:
	AttandenceManagement()
		: separation_str_("\t")
	{}

	AttandenceManagement(const std::string filename)
		: separation_str_("\t")
	{
		readANSIFile(filename);
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
			std::cout<<"wow"<<std::endl;


		ifs.close();
	}
};