//////chapter 7 Samuel
////#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//#include <algorithm> //find_if
////
//using namespace std;
//
////��������ǿհ�������Ϊtrue������Ϊfalse
//bool space(char c)
//{
//	return isspace(c);
//}
////��������ǿհ�������Ϊfalse������Ϊture
//bool not_space(char c)
//{
//	return !isspace(c);
//}
//vector<string> split(const string& str)
//{
//	typedef string::const_iterator iter;
//	vector<string>ret;
//	iter i = str.begin();
//	while (i != str.end()) {
//		//����ǰ�οհ�
//		i = find_if(i, str.end(), not_space);  //��[i,str.end())�и���not_space()�����ض�ֵ
//											   //�ҳ���һ�����ʵĽ�β
//		iter j = find_if(i, str.end(), space);
//		//����[i,j)�е��ַ�
//		if (i != str.end())
//			ret.push_back(string(i, j));
//		i = j;
//	}
//	return ret;
//}
/*
//����ָ��������ÿһ���ʵ�ȫ����
map<string, vector<int>>xref(istream& in, vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int>>ret;
	//����һ��
	while (getline(in, line)) {
		++line_number;
		//�������зָ�ɵ���
		vector<string>words = find_words(line);
		//��ס�����ڵ�ǰ�е�ÿһ������
		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
			ret[*it].push_back(line_number);
	}
	return ret;
}

//ʹ�ù�������������-ֵ
int chapter7_3()
{
	//7.3
	//string s;
	//map<string, int>counters;//�洢ÿһ�����ʺ͹����ļ�����
	////�����룬����ÿһ�����ʳ��ֵĴ���
	//while (cin >> s)
	//	++counters[s];
	////��������Լ���ص���Ŀ
	//for (map<string,int>::const_iterator it=counters.begin();it!=counters.end();++it)
	//	cout << (*it).first << "\t" << it->second << endl;
	//return 0;
	
	//Ĭ��ʹ��split������xref
	map<string, vector<int>>ret = xref(cin);
	//������
	for (map<string, vector<int>>::const_iterator it = ret.begin(); it != ret.end(); ++it)
	{
		//�������
		cout << it->first << " occur on line(s): ";
		//�������һ�������б��
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it; //�����һ���б��
		++line_it;
		//��������������ı��
		while (line_it!=it->second.end()){
			cout << "," << *line_it;
			++line_it;
		}
		//��һ�������Ա�ÿһ����������һ���ָ���
		cout << endl;
	}
	return 0;
}
*/