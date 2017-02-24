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
	//���벢�洢����ѧ��������
	while(read(cin,record)){
		//�ҳ����������
		maxlen=max(maxlen,record.name.size());
		students.push_back(record);
	}
	//����ĸ˳������ѧ����¼
	sort(students.begin(),students.end(),compare);
	//���������ͳɼ�
	for (vector<Student_info>::size_type i=0;i!=students.size();++i)
	{
		//��������������������maxlen+1���ַ�����
		cout<<students[i].name<<string(maxlen+1-students[i].name.size(),' ');
		//���㲢����ɼ�
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