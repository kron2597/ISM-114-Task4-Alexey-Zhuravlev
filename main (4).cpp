#include <iostream>//заголовочный файл ввода-вывода
#include <cstdlib> //заголовочный файл system pause
using namespace std;//стандартное пространство имен
class Circle{
public:
    float a;//а-радиус круга
    Circle(float A){//конструктор с параметром
        a=A;//назначаем радиусу параметр
    }
    Circle(){
        a=0;//конструктор по умолчанию - радиус нулевой
    }
    float Square(){
        return 3.1415926*a*a;
    }//площадь
    float Perimetr(){
        return 3.1415926*2*a;//длина окружности (периметр) - равна двум радиусам, множенным на ПИ
    }
    void enter(){
        cout<<"Введите радиус: "<<endl;
        cin>>a;
    }//ввод с клавиатуры
    void print(){
        cout<<"круг радиуса: "<<a<<"; p="<<Perimetr()<<"; s="<<Square()<<endl;
    }//вывод всей информации
};
class Pryamougolnik:public Circle{
public:
    float b;//b-вторая сторона
    Pryamougolnik(float A,float B):Circle(A){//конструктор с параметром
        b=B;//сначала вызвали родительский конструктор, затем инициализировали вторую переменную
    }
    Pryamougolnik():Circle(){
        b=0;//конструктор по умолчанию - все стороны нулевые
    }
    float Square(){
        return a*b;
    }//площадь
    float Perimetr(){
        return 2*a+2*b;
    }
    void enter(){
        cout<<"Введите  a,b: "<<endl;
        cin>>a>>b;
    }//ввод с клавиатуры
    void print(){
        cout<<"параметры прямоугольника: "<<a<<"; "<<b<<"; p="<<Perimetr()<<"; s="<<Square()<<endl;
    }//вывод всей информации
    
};
class Triangle:public Pryamougolnik{
public:
    float c;//c-третья сторона
    Triangle(float A,float B,float C):Pryamougolnik(A,B){//конструктор с параметром
        c=C;//сначала вызвали родительский конструктор, затем инициализировали третью переменную
    }
    Triangle():Pryamougolnik(){
        c=0;//конструктор по умолчанию - все стороны нулевые
    }
    float Square(){
        //формула герона
        float p =(a+b+c)/2.0;// полупериметр
        
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }//площадь
    float Perimetr(){
        return a+b+c;
    }
    void enter(){
        cout<<"Введите  a,b,c: "<<endl;
        cin>>a>>b>>c;
    }//ввод с клавиатуры
    void print(){
        cout<<"параметры треугольника: "<<a<<"; "<<b<<"; "<<c<<"; p="<<Perimetr()<<"; s="<<Square()<<endl;
    }//вывод всей информации
    
};
int main(){//точка входа программы
    setlocale(LC_ALL,"Russian");//русская локализация
    int chose=0;
    cout<<"1-circle,2-pryamougolnik,3-triangle"<<endl;
    cin>>chose;
    if(chose==1){
        Circle a;
        a.enter();
        a.print();
    }
    if(chose==2){
        Pryamougolnik a;
        a.enter();
        a.print();
    }
    if(chose==3){
        Triangle a;
        a.enter();
        a.print();
    }
    return 0;
}
