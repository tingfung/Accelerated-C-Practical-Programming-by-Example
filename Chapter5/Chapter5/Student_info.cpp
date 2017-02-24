//��Student_info��صĺ�����Դ�ļ�
#include "Student_info.h"

using std::istream;
using std::vector;
bool compare(const Student_info& x,const Student_info& y)
{
	return x.name<y.name;
}

istream& read(istream& is, Student_info& s)
{
	//���벢�洢ѧ���������Լ����С���ĩ���Գɼ�
	is >>s.name>>s.midterm>>s.final;
	read_hw(is,s.homework);
	return is;
}
//���������н���ͥ��ҵ�ĳɼ����뵽һ��vector<double>��
istream& read_hw(std::istream& in,std::vector<double>& hw)
{
	if (in)
	{
		//���ԭ������
		hw.clear();
		//�����ͥ��ҵ�ɼ�
		double x;
		while (in>>x)
			hw.push_back(x);
		//�������ʹ���붯������һ��ѧ����Ч
		in.clear();
	}
}