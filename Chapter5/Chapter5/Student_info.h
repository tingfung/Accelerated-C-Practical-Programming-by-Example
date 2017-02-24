#ifndef GUARD_Student_info
#define GUARD_Student_info

//Student_info.h
#include <iostream>
#include <string>
#include <vector>

//学生结构
struct Student_info{
	string name;
	double midterm, final; //期中、期末成绩
	vector<double>homework;
};

bool compare(const Student_info&,const Student_info&);
std::istream& read(std::istream&,Student_info&);
std::istream& read_hw(std::istream&,std::vector<double>&);
#endif