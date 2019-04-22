#include <vector>
#include <string>
#include <iostream>
#include <string.h> 
#include <stdio.h> 
#include <algorithm>

using namespace std;

string ufin[50];
string re[50];
int k=0;


vector<string> split(const string& s, const string& sep)//拆分字符串 
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




int location(string * d,string s,int k){//定位 
	int i=0;
	for(int i=0;i<k;i++)
	{
	if(d[i].compare(s)==0)
	return i;
	}
	return -1;
}

vector<string>  first(string s){//求first集 
	int l;
	int y=0;
	int count=0;
	int flag=0;
	int con=1;
	vector<string> v; 
	l = location(ufin,s,k);
	vector<string> a = split(re[l], "|"); 
	string text[a.size()];//每段 
	
	
	for(vector<string>::size_type i = 0; i != a.size(); ++i){
			text[i]=a[i];
			
		}
		
		
		for(vector<string>::size_type i = 0; i != a.size(); ++i){
			flag=0;	
			count=0;
			vector<string> b = split(text[i], ""); 
			string ele[b.size()];//每个元素 
			for(vector<string>::size_type j = 0; j != b.size(); ++j){
				ele[j]=b[j];
			}
			
				
			
			for(int x=0;x<k;x++){//判断首位是否为非终结符 
				if(ele[count].compare(ufin[x])==0){
				flag=1;		

				}
			}
			
			
			
			if(flag==1){//首位是非终结符 
		
		
 				 
				vector<string> c = first(ele[count]);//递归 
			
				vector<string>::iterator it = c.begin();
				for(;it != c.end();)
				{
				if(*it == "e")//删除指定元素，返回指向删除元素的下一个元素的位置的迭代器
				{ 
				it = c.erase(it);
				} 
				else
					//迭代器指向下一个元素位置
				++it;
				}
				
				v.insert(v.end(),c.begin(),c.end());
				
				
				
			
			while(count<b.size()&&con==1){
				con=0;
				for(int i;i<b.size();i++)
				cout<<ele[i]<<" ";
			
			for(int x=0;x<k;x++){//判断下一位是否为非终结符 
				if(ele[count+1].compare(ufin[x])==0)
				con=1;
				cout<<"";
				}
				
				if(con==1)
					
					{
					vector<string> c = first(ele[count+1]);	//递归 
					
					vector<string>::iterator it = c.begin();
					for(;it != c.end();)
					{
					if(*it == "e")//删除指定元素，返回指向删除元素的下一个元素的位置的迭代器
					{
					it = c.erase(it);
					count++;//计数 
					}
					else
						//迭代器指向下一个元素位置
					++it;
					}
					
					v.insert(v.end(),c.begin(),c.end());
					
				
					}
				}
			
				
				if(count+1==b.size()&&count>1){
				v.push_back("e");
				}
			
	
			}
			else{//为终结符 
				v.push_back(ele[count]);
				
			
			}
			
			}
	
	return v;
				
}




vector<string>  follow(string s){//求follow集 
int flag=0; 
int con=0;
vector<string> v; 
	if(location(ufin,s,k)==0){
	v.push_back("$");
	}


	for(int h=0;h<k;h++){

	vector<string> a = split(re[h], "|"); 

	string text[a.size()];//每段 
	

	for(vector<string>::size_type i = 0; i != a.size(); ++i){
			text[i]=a[i];
		}
		 
		
	for(vector<string>::size_type i = 0; i != a.size(); ++i){
			flag=0;	

			vector<string> b = split(text[i], ""); 
			string ele[b.size()];//每个元素 
			
			for(vector<string>::size_type j = 0; j != b.size(); ++j){
				ele[j]=b[j];	
			}
			
			
		for(int z=0;z<b.size();z++){	//判断是否存在该非终结符 
				if(ele[z].compare(s)==0){

					
					if(z<b.size()-1){
						
						for(int x=0;x<k;x++){//判断下一位是否为非终结符 
						if(ele[z+1].compare(ufin[x])==0){
																	
							flag=1;		
					
							if(z+1==b.size()){//下一位为最后一位，则加入follow 
								vector<string> d = follow(ufin[h]);	
								v.insert(v.end(),d.begin(),d.end());
							}
						}	
						}
						
						if(flag==1){
							
						vector<string> c = first(ele[z+1]);	
						
						
						vector<string>::iterator it = c.begin();
						for(;it != c.end();)
						{
						if(*it == "e")//删除指定元素，返回指向删除元素的下一个元素的位置的迭代器
						{
						it = c.erase(it);
						/* vector<string> d = follow(ufin[h]);	//有e所以加入follow 
						v.insert(v.end(),d.begin(),d.end());*/
						
						}
						else
						//迭代器指向下一个元素位置
						++it;
						}
					
						v.insert(v.end(),c.begin(),c.end());
					
							
						}
						
						else{
							if(ele[z+1].compare("e")==0){
								
							
								
								vector<string> d = follow(ufin[h]);	
								
								
								v.insert(v.end(),d.begin(),d.end());
							}
							else{
							v.push_back(ele[z+1]);
							}
							
								
						}	
						
						
					
					}
					else{
						v.push_back("$");
					
						vector<string> d = follow(ufin[h]);	
						v.insert(v.end(),d.begin(),d.end());
						
					}
			
				
			}
			
		
	
}
}
	
}
					
return v;				
					

	
			

} 


int main(){

	string s[50];

	int a;
	k=0;
	while(k<6){
		cin>>s[k];
		k++;
	}

	for(int j=0;j<k;j++){
		vector<string> v = split(s[j], "-"); 
		ufin[j]=v[0];
		re[j]=v[1];
		
	}

cout <<"first :"<< " ";
	cout << endl;

for(int j=0;j<k;j++){

  vector<string> v = first(ufin[j]);
  cout <<ufin[j]<< ": ";
 	for(vector<string>::size_type c = 0; c != v.size(); ++c){ 
	cout <<v[c] << " ";

	} 
	cout << endl;
}




cout <<"follow :"<< " ";
	cout << endl;


for(int x=0;x<k;x++){

  vector<string> v = follow(ufin[x]);
  cout <<ufin[x]<< ": ";
  for(vector<string>::size_type c = 0; c != v.size(); ++c){ 
	cout <<v[c] << " ";
	sort(v.begin(),v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    //unique()函数将重复的元素放到vector的尾部 然后返回指向第一个重复元素的迭代器 再用erase函数擦除从这个元素到最后元素的所有的元素

	} 
	cout << endl;

}

	
}
  
