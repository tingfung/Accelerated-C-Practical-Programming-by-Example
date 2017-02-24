struct Student_info{
	string name;
	double midterm,final;
	vector<double>homework;
};
//根据学生的期中、期末考试、家庭作业来计算总成绩
double grade(double midterm,double final,double homework)
{
	return 0.2*midterm+0.4*final+0.4*homework;
}
//计算一个vector<double>类型变量的中值
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size=vec.size();
	if (size==0)
		throw domain_error("median of an empty vector");
	sort(vec.begin(),vec.end());
	vec_sz mid=size/2;
	return size%2==0?(vec[mid]+vec[mid-1])/2:vec[mid]
}
//根据学生的期中、期末考试、家庭作业向量来计算总成绩
double grade(double midterm,double final,const vector<double>& hw)
{
	if (hw.size()==0)
		throw domain_error("stuedent has done no homework");
	return grade(midterm,final,median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm,s.final,s.homework);
}

//判断学生是否及格
bool fgrade(const Student_info& s)
{
	return grade(s)<60;
}
//第一次尝试将及格和不及格的学生分开（消耗内存）
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info>pass,fail;
	for (vector<Student_info>::size_type i=0;i!=students.size();++i)
		if(fgrade(students[i]))
			fail.push_back(students[i]);
		else
			pass.push_back(students[i]);
		students=pass;
	students=pass;
	return fail;
}
//第二次尝试：函数正确，但可能会相当慢
vector<Student_info>extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::size_type i=0;
	//不变式：students的索引在[0,1)中的元素所代表的成绩是及格的
	while(i!=students.size()){
		if (fgrade(students[i])){
			fail.push_back(students[i]);
			students.erase(students.begin()+i);
		}else
			++i;
	}
	return fail;
}
//版本3：用迭代器带起索引，效率仍然可能很低。
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter=students.begin();
	while (iter!=students.end()){
		if (fgrade(*iter))	{
			fail.push_back(*iter);
			iter=students.erase(iter);
		}else
			++iter;
	}
	return fail;
}