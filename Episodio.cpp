/*
Nombre: Sebastian Zaragoza Diaz
Matricula: A01286211
Carrera: IDM
Fecha: 20/05/2024
*/

#include "Episodio.h"

// Metodos Constructores
Episodio::Episodio(){
    titulo = "TituloEpisodio";
    temporada = 2;
    calificacion = 3;
}
Episodio::Episodio(string _titulo, int _temporada, int _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

// Metodos Modificadores
void Episodio::setTitulo(string _titulo){
    titulo = _titulo;
}
void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}
void Episodio::setCalificacion(int _calificacion){
    calificacion = _calificacion;
}

// Metodos de Acceso
string Episodio::getTitulo(){
    return titulo;
}
int Episodio::getTemporada(){
    return temporada;
}
int Episodio::getCalificacion(){
    return calificacion;
}

// Otros Metodos
string Episodio::str(){
    return titulo + ' ' + to_string(temporada) + ' ' + to_string(calificacion);
}