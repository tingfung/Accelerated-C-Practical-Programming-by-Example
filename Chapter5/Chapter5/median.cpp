//median函数的源文件
#include <algorithm>//获取sort的声明
#include <stdexcept>//获取domain_error的声明
#include <vector>//获取vector的声明

using std::domain_error;
using std::sort;
using std::vector;
//计算一个vector<double>对象类型的中值
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size=vec.size();
	if(size==0)
		throw domain_error("median of an empty vector");
	sort(vec.begin(),vec.end());
	
	vec_sz mid=size/2;
	return size%2==0?(vec[mid]+vec[mid+1])/2:vec[mid];
}