#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>

class Livro
{
private:
    int id;
    const std::string titulo;
    std::string autor;
    int ano;
    bool disponivel;
public:
    Livro(int id, std::string titulo, std::string autor, int ano);
    bool isDiponivel() const;
    void emprestar();
    void devolver();
    std::string getTitulo() const;
    int getId() const;
    int getAno() const;
    std::string getAutor() const;
};

#endif