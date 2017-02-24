#include <string>
#include <vector>

class Student_info{
public:
	//�����ṩ�Ľӿ�
	Student_info();
	Student_info(std::istream&);
	bool valid() const { return !homework.empty(); }
	double grade() const;
	std::istream& read(std::istream&);
	std::string name() const { return n; }

private:
	//���͵�ʵ��
	std::string n;
	double midterm, final;
	std::vector<double> homework;

};


/*struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;

	std::istream& read(std::istream&);
	double grade() const;
};*/

std::istream & Student_info::read(std::istream & in)
{
	// TODO: �ڴ˴����� return ���
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}

double Student_info::grade() const
{
	return::grade{midterm,final,homework}; //::����һ������֮ǰ����������Ҫ������Ƶ�ĳһ���汾������汾����Ϊ�κ�����ĳ�Ա��ȫ�ֱ�����
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}