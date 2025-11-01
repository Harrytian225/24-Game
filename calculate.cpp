#include<iostream>
using namespace std;
int sum;
double a,b,c,d,aa,bb,cc,dd,r,s,t,rr,ss,tt,u,v,uu,vv;

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

double bp(double x,double y,int op){//binary operator
	if(op==1)return x+y;
	if(op==2)return x-y;
	if(op==3)return x*y;
	return x/y;
}

char push_op(int op){
	if(op==1)return '+';
	else if(op==2)return '-' ;
	else if(op==3)return '*' ;
	else return '/' ;
}

bool h(int j,int l){
	for(int n=0;n<2;n++){
		for(int m=1;m<=4;m++){
			pmt3(n);
			double erf=bp(uu,vv,m)-24;
			if(erf>-0.0001 and erf<0.0001){
				if(uu==u and rr==r)cout << "((" << aa << push_op(j) << bb << ")" << push_op(l) << ss << ")" << push_op(m) << vv;
				else if(uu==u and ss==r)cout << "(" << rr << push_op(l) << "(" << aa << push_op(j) << bb << "))" << push_op(m) << vv;
				else if(uu==u and tt==r)cout << "(" << rr << push_op(l) << ss << ")" << push_op(m) << "(" << aa <<  push_op(j) << bb << ")";
				else if(vv==u and rr==r)cout << uu << push_op(m) << "((" << aa << push_op(j) << bb << ")" << push_op(l) << ss << ")";
				else if(vv==u and ss==r)cout << uu << push_op(m) << "(" << rr << push_op(l) << "(" << aa << push_op(j) << bb << "))";
				else cout << "(" << aa << push_op(j) << bb << ")" << push_op(m) << "(" << rr << push_op(l) << ss << ")";
				cout << endl;
				return 1;
			}
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

//第一步，挑两个出来运算，变成3个数
bool f(){
	for(int i=0;i<12;i++){//i代表哪两个数运算
		for(int j=1;j<=4;j++){//j代表运算符号
			pmt1(i);
			r = bp(aa,bb,j) ; s = cc ; t = dd ;
			if(g(j))return 1;		}
	}
	return 0;
}

int main(){
	while(true){
		sum++;
		cin >> a;
		if(a==0)return 0;
		cin >> b >> c >> d;
		cout << "Case #" << sum << ":" << " ";
		if(!f()) cout << "You try it." << endl;
	}
}//一共有5946种情况是无解的