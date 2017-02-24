struct Student_info{
	string name;
	double midterm,final;
	vector<double>homework;
};
//����ѧ�������С���ĩ���ԡ���ͥ��ҵ�������ܳɼ�
double grade(double midterm,double final,double homework)
{
	return 0.2*midterm+0.4*final+0.4*homework;
}
//����һ��vector<double>���ͱ�������ֵ
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
//����ѧ�������С���ĩ���ԡ���ͥ��ҵ�����������ܳɼ�
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

//�ж�ѧ���Ƿ񼰸�
bool fgrade(const Student_info& s)
{
	return grade(s)<60;
}
//��һ�γ��Խ�����Ͳ������ѧ���ֿ��������ڴ棩
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
//�ڶ��γ��ԣ�������ȷ�������ܻ��൱��
vector<Student_info>extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::size_type i=0;
	//����ʽ��students��������[0,1)�е�Ԫ��������ĳɼ��Ǽ����
	while(i!=students.size()){
		if (fgrade(students[i])){
			fail.push_back(students[i]);
			students.erase(students.begin()+i);
		}else
			++i;
	}
	return fail;
}
//�汾3���õ���������������Ч����Ȼ���ܺܵ͡�
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