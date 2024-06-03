/*
Nombre: Sebastian Zaragoza Diaz
Matricula: A01286211
Carrera: IDM
Fecha: 20/05/2024
*/

#include "Video.h"

Video::Video(){
    iD = "0000";
    titulo = "Sebastian";
    duracion = 1000;
    genero = "Masculino";
    calificacion = 100;
}
Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}

// Métodos Modificadores
void Video::setID(string _iD){
    iD = _iD;
}
void Video::setTitulo(string _titulo){
    titulo = _titulo;
}
void Video::setDuracion(int _duracion){
    duracion = _duracion;
}
void Video::setGenero(string _genero){
    genero = _genero;
}
void Video::setCalificacion(double _calificacion){
    calificacion = _calificacion;
}

// Métodos de Acceso
string Video::getID(){
    return iD;
}
string Video::getTitulo(){
    return titulo;
}
int Video::getDuracion(){
    return duracion;
}
string Video::getGenero(){
    return genero;
}
double Video::getCalificacion(){
    return calificacion;
}

// Otros Métodos
string Video::str(){
    return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(calificacion);
}