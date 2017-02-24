#include <algorithm>

using namespace std;

copy(bottom.begin(),bottom.end(),back_inserter(ret)); //将bottom插入到ret尾部  ，copy的第三个参数应该为一个迭代器

//查找URL
vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b=s.begin(),e=s.end();
	//检查整个输入
	while(b!=e)
	{
		//查找一个或多个紧跟着://的字母
		b=url_beg(b,e);
		//如果查找成功
		if(b!=e){
			//获取此URL的剩余部分
			iter after=url_end(b,e);
			//记住这个URL
			ret.push_back(string(b,after));
			//将b推进并查找本行中的其他URL
			b=after;
		}
	}
	return ret;
}
 