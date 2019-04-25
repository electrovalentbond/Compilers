#include <vector>
#include <string>
#include <iostream>
#include <string.h> 
#include <stdio.h> 
using namespace std;


vector<string> split(const string& s, const string& sep)
{
	
	vector<string> v; 
	if(sep!=""){
	
    string::size_type pos1, pos2;
    pos2 = s.find(sep);
    pos1 = 0;
    if(pos2==-1){
    	v.push_back(s);
	}
	else{
	
    while(string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
         
        pos1 = pos2 + sep.size();
        pos2 = s.find(sep, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
	}
	
	}
	else
	{
		string::size_type pos1, pos2;
		pos2 = 1;
    	pos1 = 0;
	for(int i=0;i<s.size();i++){ 
	
  
		v.push_back(s.substr(pos1, pos2-pos1));
         
        pos1 = pos2;
        pos2++;
		
	} 
	
	}
    return v;
}



int main(){

	string s[50];

	int a;
	int k=0;
	while(k<2){
		cin>>s[k];
		k++;
	}



for(int j=0;j<k;j++){

  vector<string> v = split(s[j], ""); 
  for(vector<string>::size_type i = 0; i != v.size(); ++i)
	cout <<v[i] << " ";
  cout << endl;
  
  vector<string>::iterator it = v.begin();
	for(;it != v.end();)
	{
		if(*it == "a")
			//删除指定元素，返回指向删除元素的下一个元素的位置的迭代器
			it = v.erase(it);
		else
			//迭代器指向下一个元素位置
			++it;
	}

  for(vector<string>::size_type i = 0; i != v.size(); ++i)
	cout <<v[i] << " ";
	  cout << endl;

}
	
}
  
