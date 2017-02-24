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
//��������ǿհ�������Ϊtrue������Ϊfalse
bool space(char c)
{
	return isspace(c);
}
//��������ǿհ�������Ϊfalse������Ϊture
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
		//����ǰ�οհ�
		i = find_if(i, str.end(), not_space);  //��[i,str.end())�и���not_space()�����ض�ֵ
											   //�ҳ���һ�����ʵĽ�β
		iter j = find_if(i, str.end(), space);
		//����[i,j)�е��ַ�
		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}
//��һ���ض����������ж���һ���ķ�
Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;
	//������
	while (getline(in,line)){
		//������ָ�ɵ���
		vector<string>entry = split(line);
		if (!entry.empty())
			//���������洢������Ĺ���
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}
	return ret;
}
bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<'&&s[s.size() - 1] == '>';
}
//����[0,n)�е�һ���������
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
		//Ϊ����word�Ĺ���λ
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");
		//��ȡ���ܵĹ��򼯺�
		const Rule_collection& c = it->second;
		//�ӹ��򼯺������ѡ��һ������
		const Rule& r = c[nrand(c.size())];//ѡ���������
		//�ݹ�չ����ѡ���Ĺ���
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
	//�������
	vector<string> sentence = gen_sentence(read_grammar(cin));
	//�����һ�����ʣ��������
	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty()){
		cout << *it;
		++it;
	}
	cout << endl;
	return 0;
}