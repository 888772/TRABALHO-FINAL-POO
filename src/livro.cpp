#include "../include/livro.hpp"
#include <iostream>
#include <string>

Livro::Livro (int id, std::string titulo, std::string autor, int ano)
: id(id), titulo(titulo), autor(autor), ano(ano){
    this->disponivel = true;
}

bool Livro::isDiponivel() const{
    return disponivel;
}

void Livro::emprestar(){
    if (!disponivel)
    {
        std::cout << "ERRO: O livro não está disponivel!!" << std::endl;
        return;
    }

    disponivel = false;
}

void Livro::devolver(){
    if(!disponivel){
        disponivel = true;
    }
    return;
}

std::string Livro::getTitulo() const{
    return titulo;
}

int Livro::getId() const{
    return id;
}

std::string Livro::getAutor() const{
    return autor;
}

int Livro::getAno() const{
    return ano;
}