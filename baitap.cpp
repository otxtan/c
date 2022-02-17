#include<iostream>
#include<string>
using namespace std;

class MAYTINH
{
    private:
    string mamay,tenmay;
    float giaban;
    public:
    static float tylekm;

    MAYTINH()
    {
        this->mamay="";
        this->tenmay="";
        this->giaban=0;
    }
    void nhap()
    {
        cout<<"nhap ma may:";
        fflush(stdin);
        getline(cin,mamay);
        cout<<"nhap ten may:";
        fflush(stdin);
        getline(cin,tenmay);
        cout<<"nhap gia ban niem yet:";
        cin>>giaban;
    }
    void xuat()
    {
        cout<<mamay<<"\t"<<tenmay<<"\t"<<giaban<<"\t"<<giabanthucte()<<endl;
    }

    float giabanthucte()
    {
        return giaban-giaban*tylekm;
    

    }
    bool operator <(MAYTINH &b);
};
    bool MAYTINH::operator <(MAYTINH &b)
    {
       return giabanthucte()<b.giabanthucte();
    }
float MAYTINH::tylekm=0.05;

int main()
{
    MAYTINH a;
    a.nhap();
    a.xuat();
    cout<<"\nnhap n:";
    int n;
    cin>>n;
    MAYTINH *b=new MAYTINH [n];
    cout<<"\nnhap thong tin may tinh:\n";
    for (int i=9;i<n;i++)
        b[i].nhap();
    cout <<"\nin thong tin\n";
    for (int i=0;i<n;i++)
    b[i].xuat();

    MAYTINH min=b[0];
   
    cout<<"\n may tinh co gia ban thap nhat la: ";
    for (int i=0;i<n;i++)
    
       if(min<b[i]) min=b[i];
       min.xuat();

}


