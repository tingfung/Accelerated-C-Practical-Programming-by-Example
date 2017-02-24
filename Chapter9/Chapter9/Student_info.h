#include <string>
#include <vector>

class Student_info{
public:
	//类型提供的接口
	Student_info();
	Student_info(std::istream&);
	bool valid() const { return !homework.empty(); }
	double grade() const;
	std::istream& read(std::istream&);
	std::string name() const { return n; }

private:
	//类型的实现
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
	// TODO: 在此处插入 return 语句
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}

double Student_info::grade() const
{
	return::grade{midterm,final,homework}; //::放在一个名称之前，表明我们要这个名称的某一个版本，这个版本不能为任何事物的成员（全局变量）
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}