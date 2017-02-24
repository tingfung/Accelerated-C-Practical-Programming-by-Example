//////chapter 7 Samuel
////#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//#include <algorithm> //find_if
////
//using namespace std;
//
////如果参数是空白区域则为true，否则为false
//bool space(char c)
//{
//	return isspace(c);
//}
////如果参数是空白区域则为false，否则为ture
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
//		//忽略前段空白
//		i = find_if(i, str.end(), not_space);  //在[i,str.end())中根据not_space()查找特定值
//											   //找出下一个单词的结尾
//		iter j = find_if(i, str.end(), space);
//		//复制[i,j)中的字符
//		if (i != str.end())
//			ret.push_back(string(i, j));
//		i = j;
//	}
//	return ret;
//}
/*
//查找指向输入中每一单词的全部行
map<string, vector<int>>xref(istream& in, vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int>>ret;
	//读下一行
	while (getline(in, line)) {
		++line_number;
		//将输入行分割成单词
		vector<string>words = find_words(line);
		//记住出现在当前行的每一个单词
		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
			ret[*it].push_back(line_number);
	}
	return ret;
}

//使用关联计数器：键-值
int chapter7_3()
{
	//7.3
	//string s;
	//map<string, int>counters;//存储每一个单词和关联的计数器
	////读输入，跟踪每一个单词出现的次数
	//while (cin >> s)
	//	++counters[s];
	////输出单词以及相关的书目
	//for (map<string,int>::const_iterator it=counters.begin();it!=counters.end();++it)
	//	cout << (*it).first << "\t" << it->second << endl;
	//return 0;
	
	//默认使用split来调用xref
	map<string, vector<int>>ret = xref(cin);
	//输出结果
	for (map<string, vector<int>>::const_iterator it = ret.begin(); it != ret.end(); ++it)
	{
		//输出单词
		cout << it->first << " occur on line(s): ";
		//后面跟随一个或多个行编号
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it; //输出第一个行编号
		++line_it;
		//如果有则输出多余的编号
		while (line_it!=it->second.end()){
			cout << "," << *line_it;
			++line_it;
		}
		//换一个新行以便每一个单词与下一个分隔开
		cout << endl;
	}
	return 0;
}
*/