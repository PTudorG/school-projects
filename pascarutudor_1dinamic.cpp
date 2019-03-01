#include<fstream>
#include<iostream>
using namespace std;

int n,k; double v[100];

fstream f("input.dat",ios::in);
fstream g("output.dat",ios::out);

class node{public :
           double my_info;
           class node *my_left;
           class node *my_right;

int read_data()
{
    f>>n;
    for(int i=1;i<=n;i++)
    f>>v[i];
    return 0;
    f.close();

}

        node *make_some_tree(node *this_one, double new_one)
{
 if(this_one==NULL)
 {
     this_one=new node;
     this_one->my_info=new_one;
     this_one->my_right=this_one->my_left=NULL;
     return this_one;
 }

if (this_one->my_info<new_one && this_one->my_info!=0)
                {
                return make_some_tree(this_one->my_right,new_one);
                }
                else this_one->my_right=NULL;
if (this_one->my_info>new_one && this_one->my_info!=0)
                {
                return make_some_tree(this_one->my_left,new_one);
                }
                else this_one->my_left=NULL;
}

int RSD(node *this_one)
{if (this_one!=NULL) {g<<this_one->my_info<<" ";
                      RSD(this_one->my_left);
                      RSD(this_one->my_right);}}

int SRD(node *this_one)
{if (this_one!=NULL) {RSD(this_one->my_left);
                      g<<this_one->my_info<<" ";
                      RSD(this_one->my_right);}}

int SDR(node *this_one)
{if (this_one!=NULL) {RSD(this_one->my_left);
                      RSD(this_one->my_right);
                      g<<this_one->my_info<<" ";}}
};

int main()
{node *r=new node;
r->read_data();
for(int i=1;i<=n;i++)
r=r->make_some_tree(r,v[i]);
r->RSD(r); g<<endl;
r->SRD(r); g<<endl;
r->SDR(r);
g.close();}
