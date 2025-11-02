#include <iostream>
using namespace std;
int main(){
    int *px, *py;
    int x, y;
    x=50;
    y=100;
    px=&x;
    py=&y;
    cout<<"x:"<<x<<" y:"<<y<<"\n";
    cout<<"px:"<<px<<" py:"<<py<<"\n";
    cout<<"*px:"<<*px<<" *py:"<<*py<<"\n";
    cout<<"\n";

    *px=y+11;
    cout<<"x:"<<x<<" y:"<<y<<"\n";
    cout<<"px:"<<px<<" py:"<<py<<"\n";
    cout<<"*px:"<<*px<<" *py:"<<*py<<"\n";
    cout<<"\n";

     px=py;
    cout<<"x:"<<x<<" y:"<<y<<"\n";
    cout<<"px:"<<px<<" py:"<<py<<"\n";
    cout<<"*px:"<<*px<<" *py:"<<*py<<"\n";
    cout<<"\n";


    *px=(*px)+4;
    *py=(*py)+8;
    cout<<"x:"<<x<<" y:"<<y<<"\n";
    cout<<"px:"<<px<<" py:"<<py<<"\n";
    cout<<"*px:"<<*px<<" *py:"<<*py<<"\n";
    cout<<"\n";
    return 0;
}
