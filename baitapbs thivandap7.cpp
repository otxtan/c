#include <iostream>
#include<string>
using namespace std;


struct hanghoa
{
    int ma;
    string ten;
    float gianhap,giaxuat;
};
struct node{
    node *next;
    hanghoa data;
    node *prev;
};
struct list 
{
    node *head;
    node *tail;
};

bool ktrong(list ds)
{
    if(ds.head==NULL)
    return true;
    return false;
}
void khoitao(list &ds)
{
    ds.head=ds.tail=NULL;
}
node *taonode(hanghoa hh)
{
    node *p=new node;
    if(p==NULL)
        {
            cout<<"dung luong khong du";
            return p;
        }
    else 
        {
            p->next=p->prev=NULL;
            p->data=hh;
            return p;
        }
}

void chencuoi(list &ds,node *p)
{
    if(ktrong(ds)==true)
    {
        ds.head=ds.tail=p;
    }
    else 
    {
        ds.tail->next=p;
        p->prev=ds.tail;
        ds.tail=p;

    }
}
void xoatruoctail(list &ds)
{
    if(ktrong(ds)==false)
    {
        node *p;
        p=ds.tail->prev;
        p->prev->next=ds.tail;
        ds.tail->prev=p->prev;
        delete p;

    }
}

void duyetlist(list ds)
{
    
    for(node *p=ds.head;p!=NULL;p=p->next)
    {
        cout<<"ma: "<<p->data.ma<<"\t"
        <<"ten: "<<p->data.ten<<"\t"
        <<"gia nhap: "<<p->data.gianhap<<"\t"
        <<"gia xuat: "<<p->data.giaxuat<<endl;
    }
}
int main()
{
    list ds;
    hanghoa hh;
    khoitao(ds);
    int n;
    cout<<"nhap so phan tu:";
    cin>>n;
    for(int i=0;i<n;i++)
    {   
        cout<<"nhap ma:";
        cin>>hh.ma;
        cin.ignore();
        cout<<"nhap ten:";
        getline(cin,hh.ten);
        cout<<"nhap gia nhap:";
        cin>>hh.gianhap;
        
        cout<<"nhap gia xuat:";
        cin>>hh.giaxuat;
        node *p=taonode(hh);
        if(p!=NULL)
            chencuoi(ds,p);

    }
    duyetlist(ds);
    cout<<"xoa truoc node cuoi";
    xoatruoctail(ds);
    duyetlist(ds);
}