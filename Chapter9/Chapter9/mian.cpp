#include <vector>
#include <algorithm>
#include "Student_info.h"

using namespace std;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	//�����洢����
	while (record.read(cin)){
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}
	//����ĸ˳������ѧ����¼
	sort(students.begin(), students.end(), compare);
	//д�����ͳɼ�
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		cout << student[i].name() << string(maxlen + 1 - students.grade());
	}
}