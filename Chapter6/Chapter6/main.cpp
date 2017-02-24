#include <algorithm>

using namespace std;

copy(bottom.begin(),bottom.end(),back_inserter(ret)); //��bottom���뵽retβ��  ��copy�ĵ���������Ӧ��Ϊһ��������

//����URL
vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b=s.begin(),e=s.end();
	//�����������
	while(b!=e)
	{
		//����һ������������://����ĸ
		b=url_beg(b,e);
		//������ҳɹ�
		if(b!=e){
			//��ȡ��URL��ʣ�ಿ��
			iter after=url_end(b,e);
			//��ס���URL
			ret.push_back(string(b,after));
			//��b�ƽ������ұ����е�����URL
			b=after;
		}
	}
	return ret;
}
 