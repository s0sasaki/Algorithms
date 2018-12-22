#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	int a,b;
	string str;
	stack<int> s;
	while(cin>>str){
		if(str[0]-'0'>=0&&str[0]-'0'<10)
			s.push(stoi(str));
		else if(str=="+"){
			a = s.top();s.pop();
			b = s.top();s.pop();
			s.push(a+b);
		}else if(str=="*"){
			a = s.top();s.pop();
			b = s.top();s.pop();
			s.push(a*b);
		}
		else if(str=="-"){
			a = s.top();s.pop();
			b = s.top();s.pop();
			s.push(b-a);
		}
	}
	cout<<s.top()<<endl;
	return 0;
}
