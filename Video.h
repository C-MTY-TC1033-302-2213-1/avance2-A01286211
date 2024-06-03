/*
Nombre: Sebastian Zaragoza Diaz
Matricula: A01286211
Carrera: IDM
Fecha: 20/05/2024
*/

#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Video{

    protected:
        string iD, titulo, genero;
        int duracion;
        double calificacion;

    public:
        // Métodos Constructores
        Video();
        Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

        // Métodos Modificadores
        void setID(string _iD);
        void setTitulo(string _titulo);
        void setDuracion(int _duracion);
        void setGenero(string _genero);
        void setCalificacion(double _calificacion);

        // Métodos de Acceso
        string getID();
        string getTitulo();
        int getDuracion();
        string getGenero();
        double getCalificacion();

        // Otros Métodos
        virtual std::string str();
};

#endif // VIDEO_H
