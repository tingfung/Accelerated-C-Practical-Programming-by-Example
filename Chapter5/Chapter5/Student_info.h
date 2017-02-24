#ifndef GUARD_Student_info
#define GUARD_Student_info

//Student_info.h
#include <iostream>
#include <string>
#include <vector>

//ѧ���ṹ
struct Student_info{
	string name;
	double midterm, final; //���С���ĩ�ɼ�
	vector<double>homework;
};

bool compare(const Student_info&,const Student_info&);
std::istream& read(std::istream&,Student_info&);
std::istream& read_hw(std::istream&,std::vector<double>&);
#endif