#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <vector>
#include "livro.hpp"
#include "usuario.hpp"
#include "emprestimo.hpp"

class Biblioteca
{
private:
    Livro* refLivro; //ponteiro para objeto
    Usuario* refUsuario; //ponteiro para objeto
    std::vector<Livro*> livros;
    std::vector<Usuario*> usuarios;
    std::vector<Emprestimo*> emprestimos;
public:
    void adicionarLivro(Livro* livro);
    void adicionarUsuario(Usuario* usuario);
    bool emprestarLivro(Livro* livro, Usuario* usuario, const std::string& data);
    bool devolverLivro(Livro* livro, const std::string& data);
    void listarLivros() const;
    void listarLivrosEmprestados() const;
    void listarUsuarios() const;
    Livro* buscarLivroPorId(int id);
    Usuario* buscarUsuarioPorId(int id);

    ~Biblioteca();
};


#endif