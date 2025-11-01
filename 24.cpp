#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
const int N=1000000;
bool format_err,ans_err,exp_err,err;
int sum;
bool vis[4];
double a,b,c,d,aa,bb,cc,dd,r,s,t,rr,ss,tt,u,v,uu,vv,tst[100];
string str1,str2,str3,str4,str5;
char str[100];

ifstream fin1("24.in");
ifstream fin2("24.ans");

bool isnum(char c){
	if(c-'0'>=0 and c-'0'<=9)return 1;
	else return 0;
}

bool isop(char c){
	if(c=='+' or c=='-' or c=='*' or c=='/')return 1;
	else return 0;
}

bool isbk(char c){
	if(c=='(' or c==')')return 1;
	else return 0;
}

char tf(double d){//把栈顶非数字元素转化为相应的字符
	return char(d+N);
}

bool match(int t){
	if(t==a and !vis[0])     { vis[0]=1 ; return 1; }
	else if(t==b and !vis[1]){ vis[1]=1 ; return 1; }
	else if(t==c and !vis[2]){ vis[2]=1 ; return 1; }
	else if(t==d and !vis[3]){ vis[3]=1 ; return 1; }
	else return 0;
}

void pmt1(int i){
	if(i==0){aa=a;bb=b;cc=c;dd=d;}
	if(i==1){aa=a;bb=c;cc=b;dd=d;}
	if(i==2){aa=a;bb=d;cc=c;dd=b;}
	if(i==3){aa=b;bb=a;cc=c;dd=d;}
	if(i==4){aa=b;bb=c;cc=a;dd=d;}
	if(i==5){aa=b;bb=d;cc=c;dd=a;}
	if(i==6){aa=c;bb=a;cc=b;dd=d;}
	if(i==7){aa=c;bb=b;cc=a;dd=d;}
	if(i==8){aa=c;bb=d;cc=a;dd=b;}
	if(i==9){aa=d;bb=a;cc=c;dd=b;}
	if(i==10){aa=d;bb=b;cc=c;dd=a;}
	if(i==11){aa=d;bb=c;cc=a;dd=b;}
}

void pmt2(int k){
	if(k==0){rr=r;ss=s;tt=t;}
	if(k==1){rr=r;ss=t;tt=s;}
	if(k==2){rr=s;ss=r;tt=t;}
	if(k==3){rr=s;ss=t;tt=r;}
	if(k==4){rr=t;ss=s;tt=r;}
	if(k==5){rr=t;ss=r;tt=s;}
}

void pmt3(int n){
	if(n==0){uu=u;vv=v;}
	if(n==1){uu=v;vv=u;}
}

double bp(double x,double y,int op){
	if(op==1)return x+y;
	if(op==2)return x-y;
	if(op==3)return x*y;
	return x/y;
}

bool h(int j,int l){
	for(int n=0;n<2;n++){
		for(int m=1;m<=4;m++){
			pmt3(n);
			double erf=bp(uu,vv,m)-24;
			if(erf>-0.0001 and erf<0.0001)return 1;
		}	
	}
	return 0;
}

bool g(int j){
	for(int k=0;k<6;k++){
		for(int l=1;l<=4;l++){
			pmt2(k);
			u = bp(rr,ss,l); v = tt;	
			if(h(j,l))return 1;
		}
	}
	return 0;
}

bool f(){
	for(int i=0;i<12;i++){
		for(int j=1;j<=4;j++){
			pmt1(i);
			r=bp(aa,bb,j);s=cc;t=dd;
			if(g(j))return 1;		
		}
	}
	return 0;
}

void anls(){
	stack<double> stk;//char类型的话中间过程的double类型量存不进去
	while(!stk.empty())stk.pop();
	char c,str[100];
	int j=0,qq=0;
	while(fin2.get(c)){
		str[j]=c;
		if(c=='\n'){qq=1;break;}
		j++;
	}
	if(qq==0)str[j]='\n';
	if(str[0]!='C' or str[1]!='a' or str[2]!='s' or str[3]!='e' or str[4]!=' ' or str[5]!='#' or !isnum(str[6])){format_err=1;return;}
	int point=7,add=str[6]-'0';
	while(isnum(str[point])){
		add=10*add+str[point]-'0';
		point++;
	}
	if(add!=sum){format_err=1;return;}
	if(str[point]!=':' or str[point+1]!=' '){format_err=1;return;}
	if(!f()){
		char ss[20];
		char rr[] = "You try it.";
		for(int cnt=point+2;cnt<j-1;cnt++)ss[cnt]=str[cnt];
		if(!strcmp(ss,rr))ans_err=1;
		return;
	}
	
	int i=point+2;
	while(true){
		c=str[i];
		if(c=='\n')break;
		if(!isnum(c) and !isop(c) and !isbk(c) and c!=' '){exp_err=1;return;}
		if(c=='(' ){
			if(!stk.empty()){
				if(stk.top()+N/2>0){exp_err=1;return;}
			}						
			stk.push(double(c-N));
		}
		if(isop(c)){
			if(stk.empty()){exp_err=1;return;}
			if(isop(tf(stk.top())) or tf(stk.top())=='('){exp_err=1;return;}
			if(c=='*' or c=='/')stk.push(double(c-N));
			else{
				double v1 = stk.top();
				stk.pop();
				if(stk.empty())stk.push(v1);
				else{
					double v2 = stk.top();
					char v0 = char(v2+N);
					if(v0=='(')stk.push(v1);
					else{
						stk.pop();
						if(v0=='+'){
							double v3 = stk.top();
							stk.pop();
							stk.push(v1+v3);
						}
						else if(v0=='-'){
							double v3 = stk.top();
							stk.pop();
							stk.push(v3-v1);
						}
					}
				}
				stk.push(double(c-N));
			}
		}
		if(c==')'){
			if(stk.empty()){exp_err=1;return;}
			double x = stk.top();
			stk.pop();
			if(x+N/2<0){exp_err=1;return;}
			if(stk.empty()){exp_err=1;return;}
			double y = stk.top();
			stk.pop();
			char yy = char(y+N);
			if(yy=='(')stk.push(x);
			if(isop(yy)){
				double z = stk.top();
				stk.pop();
				if(stk.empty()){exp_err=1;return;}
				else stk.pop();
				if(yy=='+')stk.push(z+x);
				if(yy=='-')stk.push(z-x);
				if(yy=='*')stk.push(z*x);
				if(yy=='/')stk.push(z/x);
			}
			
		}
		if(isnum(c)){//如果读入一个1，得判断是不是十位数
			if(c == '0'){format_err = 1;return;}//如果首位是0怎么处理？认为首位不能是0，否则就算format_err
			double t;
			if(isnum(str[i+1])) t = double(10*(c-'0')+(str[i+1]-'0'));
			else t=double(c-'0');
			if(!match(t)){format_err=1;return;}
			if(stk.empty())stk.push(t);
			else if(tf(stk.top())=='(' or tf(stk.top())=='+' or tf(stk.top())=='-')stk.push(t);
			else if(tf(stk.top())==')'){exp_err=1;return;}
			else{
				double tp=stk.top();
				if(tp>0){exp_err=1;return;}
				stk.pop();
				double w = stk.top();
				stk.pop();
				if(tf(tp)=='*') w = w * t;
				else w = w/t;
				stk.push(w);
			}
			if(isnum(str[i+1]))i++;
		}
		i++;
		/*
		int pt1=0;
		while(!stk.empty()){
			tst[pt1]=stk.top();
			cout<<stk.top()<<endl;
			stk.pop();
			pt1++;
		}
		cout << endl;
		while(pt1>0){
			pt1--;
			stk.push(tst[pt1]);		
		}	
		*/
	}
	//之后的stk中，无'('，可能是单独的数，也可能是两数加减
	double ans = stk.top();
	//cout<< ans << endl;
	stk.pop();
	if(!stk.empty()){
		char uu = char(stk.top()+N);
		if(uu=='('){exp_err=1;return;}
		stk.pop();
		double temp = stk.top();
		stk.pop();
		if(uu=='+')ans+=temp;
		else if(uu=='-')ans=temp-ans;
		else if(uu=='*')ans*=temp;
		else ans=temp/ans;
		if(!stk.empty()){exp_err=1;return;}
		//cout << ans << endl;
	}
	double erf=ans-24;	
	if(erf<-0.0001 or erf>0.0001)ans_err=1;	
}

int main(){
	while(true){
		sum++;
		format_err=0;ans_err=0;exp_err=0;
		vis[0]=0;vis[1]=0;vis[2]=0;vis[3]=0;
		fin1 >> a;
		if(a==0){
			if(err==0)cout << "all correct!" << endl;
			return 0;
		}
		else{
			fin1 >> b >> c >> d;
			//fin2 >> str1 >> str2;
			//if(str1!="Case" or str2[0]!='#' or str2[1]-'0'!=sum or str2[2]!=':'){cout<<"???"<<endl;format_err=1;}
			anls();
		}
		if(format_err==1 or exp_err==1 or ans_err==1){
			err=1;
			if(format_err==1)cout << "No." << sum << " format error" << endl;
			else if(exp_err==1)cout << "No." << sum << " expression error" << endl;
			else if(ans_err==1)cout << "No." << sum << " wrong answer" << endl;
		}	
	}
}
