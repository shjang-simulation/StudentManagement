#pragma once
#include <vector>
#include <fstream>
#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string_regex.hpp>
#include <string>
#include <iostream>
#include "StudentData.h"
#include "Management.h"


class StudentManagement : public Management
{
public:
	std::vector<std::vector<int>> class_list_;
	std::string separation_str_;
	//std::vector<std::vector<std::string>> data_lines_;
	std::vector<StudentData> student_data_;

public:
	StudentManagement()
		: separation_str_("\t")
	{}

	StudentManagement(const std::string filename)
		: separation_str_("\t")
	{
		Management::readANSIFile(filename);
		saveData();
	}

	void printAll()
	{
		//for (int ix = 0; ix < data_lines_.size(); ix++)
		//	for (int i = 0; i < data_lines_[ix].size(); i++)
		//		std::cout << data_lines_[ix][i] << std::endl;
				//printPharases(data_lines_[ix]);

		for (int j = 0; j < student_data_.size(); j++)
			std::cout << student_data_[j].student_id << " " << student_data_[j].score_ << std::endl;
	}

	void saveData()
	{
		for (int ix = 0; ix < data_lines_.size(); ix++)
			student_data_.push_back(StudentData(data_lines_[ix]));
	}

	void writeData(const std::string& path, const std::string& student_file)
	{
		std::ifstream fin(student_file);
		std::ofstream ofs(path);

		std::string stu_id;

		int pos;
		while (std::getline(fin, stu_id))
		{
			pos = findStudent(stu_id);
			if (pos == -1)
				ofs << stu_id << "\t" << "0" << std::endl;
			else
				ofs << stu_id << "\t" << student_data_[pos].score_ << std::endl;
		}
		
		fin.close();
		//for (int i = 0; i < (int)student_data_.size(); i++)
		//	ofs << student_data_[i].student_id_ << " " << student_data_[i].quiz_score_ << std::endl;
		ofs.close();
	}

	int findStudent(std::string id)
	{
		for (int i = 0; i < (int)student_data_.size(); i++)
		{
			if (id == student_data_[i].student_id)
				return i;
		}
		return -1;
	}
};