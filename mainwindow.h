#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include<list>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Neurona{
private:
    int id;
    float voltaje;
    int posicion_x;
    int posicion_y;
    int red;
    int blue;
    int green;
public:
    Neurona(){};
    Neurona(int I, float V, int PX, int PY, int R, int G, int B): id(I), voltaje(V), posicion_x(PX), posicion_y(PY), red(R), green(G), blue(B){
          };
    void print(){
        cout<<"Neurona: "<<id<<endl;
        cout<<"voltaje: "<<voltaje<<endl;
        cout<<"posicion_x: "<<posicion_x<<endl;
        cout<<"posicion_y: "<<posicion_y<<endl;
        cout<<"red: "<<red<<" blue: "<<blue<<" green: "<<green<<endl;
    };
    int getId(){return id;}
    float getVoltaje(){return voltaje;}
    int getPosX(){return posicion_x;}
    int getPosY(){return posicion_y;}
    int getRed(){return red;}
    int getBlue(){return blue;}
    int getGreen(){return green;}
};

class admNeurona{
private:
    list<Neurona> listaNeuronas;
public:
    void agregar_inicio(Neurona neurona){
        listaNeuronas.insert(listaNeuronas.begin(), neurona);
    }
    void agregar_final(Neurona neurona){
        listaNeuronas.push_back(neurona);
    }
    void mostrar(){
        for(Neurona neurona : listaNeuronas){
            cout<<"--------------"<<endl;
            neurona.print();
            cout<<"--------------"<<endl;
        }
    }
    list<Neurona>& listaNeurona(){
        return listaNeuronas;
    }
    list<Neurona>& listaClear(){
        listaNeuronas.clear();
        return listaNeuronas;
    }


};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void crearNeuronaInicio();
    void crearNeuronaFinal();
    void mostrar();

private slots:
    void on_openFile_triggered();
    void on_actionRecuperar_triggered();

    void on_MostraTabla_clicked();

    void on_BuscarID_clicked();

    void on_graficarNeurona_clicked();

private:
    Ui::MainWindow *ui;
    admNeurona listaNeuronas;
};

#endif // MAINWINDOW_H
