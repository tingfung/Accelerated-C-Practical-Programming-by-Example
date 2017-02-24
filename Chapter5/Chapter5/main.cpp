#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using namespace std;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen=0;
	//读入并存储所有学生的数据
	while(read(cin,record)){
		//找出最长姓名长度
		maxlen=max(maxlen,record.name.size());
		students.push_back(record);
	}
	//按字母顺序排列学生记录
	sort(students.begin(),students.end(),compare);
	//输入姓名和成绩
	for (vector<Student_info>::size_type i=0;i!=students.size();++i)
	{
		//输出姓名，将姓名填充至maxlen+1个字符长度
		cout<<students[i].name<<string(maxlen+1-students[i].name.size(),' ');
		//计算并输出成绩
		try
		{
			double final_grade=grade(students[i]);
			streamsize prec=cout.precision();
			cout<<setprecision(3)<<final_grade<<setprecision(prec);
		}
		catch (domain_error e)
		{
			cout<<e.what();
		}
		cout<<endl;
	}
	return 0;
}