#include <fstream>
#include "StudentManagement.h"
#include "StudentData.h"
#include "AnswerData.h"
#include "AnswerManagement.h"
#include "AttendanceManagement.h"

int main()
{
	/*
	//����
	std::string answer = "ch2";
	AnswerManagement ans(answer+".txt");
	ans.writeData(answer+"_answer.txt");
	*/
	
	//�л� ä��
	std::string filename = "score.txt";
	filename = "ch7_Score";
	StudentManagement stu(filename+".txt");
	stu.printAll();
	stu.writeData(filename+"1.txt", "student1.txt");
	stu.writeData(filename+"2.txt", "student2.txt");
	
}