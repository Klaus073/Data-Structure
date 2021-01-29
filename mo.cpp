#include<iostream>
#include<string>
using namespace std;

void implication(string x)
{
    
	if(x=="!p->q")
	{
	
	cout<<"converse is        q->!p"<<endl;
	cout<<"contrapositive is !q->p"<<endl;
	cout<<"inverse is         p->!q"<<endl; 
	}
	else if (x=="p->!q")
	{
	cout<<"converse is      !q->p"<<endl;
	cout<<"contrapositive is q->!p"<<endl;
	cout<<"inverse is       !p->q"<<endl; 	
	}
	else if (x=="p->q")
	{
	cout<<"converse is        q->p"<<endl;
	cout<<"contrapositive is !q->!p"<<endl;
	cout<<"inverse is        !p->!q"<<endl; 	
	}
	else if(x=="!p->!q")
	{
	cout<<"converse is      !q->!p"<<endl;
	cout<<"contrapositive is q->p"<<endl;
	cout<<"inverse is        p->q"<<endl;
	}
	else
	{
		cout<<"enter the correct proposition"<<endl;
	}
}

void contrapositive(string x)
{
	if(x=="!p->q")
	{
	cout<<"implication is !q->p"<<endl;
	cout<<"converse is     p->!q"<<endl;
	cout<<"inverse is      q->!p"<<endl;
	}
	else if (x=="p->!q")
	{
	cout<<"implication is q->!p"<<endl;
	cout<<"converse is   !p->q"<<endl;
	cout<<"inverse is    !q->p"<<endl;
	}
	else if(x=="p->q")
	{
	cout<<"implication is !q->!p"<<endl;
	cout<<"converse is    !p->!q"<<endl;
	cout<<"inverse is      q->q"<<endl;
	}
	else if(x=="!p->!q")
	{
	cout<<"implication is q->p"<<endl;
	cout<<"converse is    p->q "<<endl;
	cout<<"inverse is    !q->!p"<<endl;
	}
	else
	{
		cout<<"enter the correct proposition"<<endl;
	}
	
}
void converse(string x)
{
	if(x=="!p->q")
	{
	cout<<"implication is    q->!p"<<endl;
	cout<<"contrapositive is p->!q"<<endl;
	cout<<"inverse is       !q->p"<<endl;
	}
	else if(x=="p->!q")
	{	
	cout<<"implication is    !q->p"<<endl;
	cout<<"contrapositive is !p->q"<<endl;
	cout<<"inverse is         p->!q"<<endl;
	}
	else if(x=="p->q")
	{
	cout<<"implication is     q->p"<<endl;
	cout<<"contrapositive is !p->!q"<<endl;
	cout<<"inverse is         p->q"<<endl;
	}
	else if(x=="!p->!q")
	{
	cout<<"implication is    !q->!p"<<endl;
	cout<<"contrapositive is  p->q"<<endl;
	cout<<"inverse is         q->p"<<endl;	
	}
	else
	{
		cout<<"enter the correct proposition"<<endl;
	}
}

void inverse(string x)
{
	if(x=="!p->q")
	{
	cout<<"implication is    P->!q"<<endl;
	cout<<"contrapositive is q->!p"<<endl;
	cout<<"converse         !q->p"<<endl;
	}
	else if(x=="p->!q")
	{
	cout<<"implication is    !p->q"<<endl;
	cout<<"contrapositive is !q->p"<<endl;
	cout<<"converse is        q->!p"<<endl;
	}
	else if(x=="p->q")
	{
	cout<<"implication is    !p->!q"<<endl;
	cout<<"contrapositive is  q->p"<<endl;
	cout<<"converse is       !q->!p"<<endl;	
	}
	else if(x=="!p->!q")
	{
	cout<<"implication is     p->q"<<endl;
	cout<<"contrapositive is !q->!p"<<endl;
	cout<<"converse is        q->p"<<endl;
	}
	else
	{
		cout<<"enter the correct proposition"<<endl;
	}
}




int main()
{
string x="";
string y="";

for (;;)
{
	cout<<"enter the value of proposition"<<endl;
cin>>x;
cout<<"enter the form of proposition"<<endl;
cin>>y;


if(y=="implication")
{
implication(x);
	break;
}
else if(y=="contrapositive")
{
	contrapositive(x);
}
else if (y=="inverse")
{
	inverse(x);
}
else if (y=="converse")
{
	converse(x);
}
else
{
	cout<<"enter the correct form of proposition"<<endl;
}

}






return 0;
}