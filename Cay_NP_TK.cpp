#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std ; 

struct Node{
	int data ; 
	Node *P_right ; 
	Node *P_left ; 
};
void KT_Cay (Node* &t )
{
	t=NULL; 
}
void ThemNode(Node* &t , int x  )
{
	if(t==NULL)
	{
		Node *p=new Node ; 
		p->data= x ; 
		p->P_left = NULL ; 
		p->P_right=NULL ; 
		t=p ; 
	}
	else
	{
		if (t->data>x)	ThemNode (t->P_left,x );
		else if(t->data<x)	ThemNode(t->P_right , x );
	}
}
void XuatCay(Node* &t)
{
	if (t!=NULL)
	{
		cout<<t->data<<" ";
		XuatCay(t->P_left);
		XuatCay(t->P_right);
	}
}
Node* TK(Node* t, int &x)
{
	if (t==NULL)
	return NULL; 
	if(t!=NULL)
	{
		if(x<t->data) TK(t->P_left,x);
		else if(x>t->data)	TK(t->P_right,x);
		else 
		return t; 
		
	}
}
int Docao(Node* t)
{
	int Trai, Phai ; 
	if(t==NULL) return 0; 
		Trai=Docao(t->P_left);
		Phai=Docao(t->P_right);
	if(Trai>Phai) return 1+ Trai;
	return 1+ Phai;
void Menu(Node* &t)
{
	system("cls");
	
	cout<<"---------------------------------MENU----------------------------------------"<<endl;
	cout<<"1.Them phan tu vao cay"<<endl;
	cout<<"2.Xuat cac phan tu cua cay theo cach duyet dau"<<endl;
	cout<<"3.Tim kiem phan tu "<<endl;
	cout<<"4.Tinh do cao "<<endl;
	cout<<"0.Thoat!! "<<endl;
	
while(true)
{
	int LuaChon;
	cout<<"Moi ban nhap phim trong menu :" ; cin>>LuaChon;
	
	if(LuaChon<0||LuaChon>4)
	{
		cout<<"Lua chon khong hop le , vui long chon lai!!"<<endl;
	}
	else if(LuaChon==1)
	{
		int x;
		cout<<"Them phan tu nguyen duong vao cay : ";cin>>x;
		ThemNode(t,x);
	}
	else if(LuaChon==2)
	{
		cout<<"Day phan tu cua cay theo kieu duyet truoc la: ";
		XuatCay(t);
		cout<<"\n";
	}
	else if(LuaChon==0)
	break;
	else if(LuaChon==3)
	{
		Node* p;
		int x ; 
		cout<<"Nhap phan tu muon tim kiem : "; cin>>x ;
		p=TK(t,x);
		if(p!=NULL)
			{
				cout<<"Phan tu "<<x<<" co nam trong cay! \n";	

			}
		else 
			cout<<"Phan tu "<<x<<" khong nam trong cay \n";
		
	}
	else if(LuaChon==4)
	{
		int p ; 
		p=Daocao(t); 
		cout<<p;
		
	}
}
}
int main()
{
	Node* t; 
	KT_Cay(t);
	Menu(t); 
	return 0; 
}

