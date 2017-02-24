//chapter 7 Samuel
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm> //find_if
#include <cstdlib>
//#include "chapter7_3.h"

using namespace std;
typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection>Grammar;
//如果参数是空白区域则为true，否则为false
bool space(char c)
{
	return isspace(c);
}
//如果参数是空白区域则为false，否则为ture
bool not_space(char c)
{
	return !isspace(c);
}
vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string>ret;
	iter i = str.begin();
	while (i != str.end()) {
		//忽略前段空白
		i = find_if(i, str.end(), not_space);  //在[i,str.end())中根据not_space()查找特定值
											   //找出下一个单词的结尾
		iter j = find_if(i, str.end(), space);
		//复制[i,j)中的字符
		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}
//从一个特定的输入流中读入一个文法
Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;
	//读输入
	while (getline(in,line)){
		//将输入分割成单词
		vector<string>entry = split(line);
		if (!entry.empty())
			//用种类来存储相关联的规则
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}
	return ret;
}
bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<'&&s[s.size() - 1] == '>';
}
//返回[0,n)中的一个随机整数
int nrand(int n)
{
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range");
	const int bucket_size = RAND_MAX / n;
	int r;
	do r = rand() / bucket_size;
	while (r >= n);
	return r;
}
void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
	if (!bracketed(word)) {
		ret.push_back(word);
	}else{
		//为对于word的规则定位
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");
		//获取可能的规则集合
		const Rule_collection& c = it->second;
		//从规则集合中随机选择一条规则
		const Rule& r = c[nrand(c.size())];//选择随机整数
		//递归展开所选定的规则
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_aux(g, *i, ret);
	}
}

vector<string> gen_sentence(const Grammar& g)
{
	vector<string>ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}

int main()
{
	//生成语句
	vector<string> sentence = gen_sentence(read_grammar(cin));
	//输出第一个单词，如果存在
	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty()){
		cout << *it;
		++it;
	}
	cout << endl;
	return 0;
}