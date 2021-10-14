#include <iostream>//заголовочный файл ввода-вывода
#include <cstdlib> //заголовочный файл system pause
#include <cstring>
using namespace std;//стандартное пространство имен
class Liquid{
protected:
    float plotn;
public:
    char*name;
    void setPlotn(float plot){
        plotn=plot;//метод изменения плотности
    }
    float getPlotn(){
        return plotn;//метод получения плотности
    }
    Liquid(){
        plotn=0;
        name=new char[256];
        strcpy(name, "");
    }
    Liquid(float plot, char*n){
        plotn=plot;
        name=new char[256];
        strcpy(name, n);
    }
    void print(){
        cout<<"жидкость "<<name<<", плотность:"<<plotn<<endl;
    }
    void enter(){
        name=new char[256];
        cout<<"введите имя и плотность"<<endl;
        cin>>name;
        cin>>plotn;
    }
};
class Alcohol:public Liquid{
private:
    float krep;
public:
    void setKrep(float k){
        krep=k;
    }
    float getKrep(){
        return krep;
    }
     Alcohol():Liquid(){
         krep=0;
    }
    Alcohol(float plot, char*n,float kr):Liquid(plot,n){
        krep=kr;
    }
    void print(){
        cout<<"спиртовая жидкость "<<name<<", плотность:"<<plotn<<" крепость:"<<krep<<endl;
    }
    void enter(){
        name=new char[256];
        cout<<"введите имя и плотность, крепость"<<endl;
        cin>>name;
        cin>>plotn;
        cin>>krep;
    }
};
int main(){//точка входа программы
    setlocale(LC_ALL,"Russian");//русская локализация
    Liquid lq;
    lq.enter();
    lq.print();
    Alcohol alc;
    alc.enter();
    alc.print();
    return 0;
}
