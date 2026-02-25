#include "../include/emprestimo.hpp"

Emprestimo::Emprestimo(Livro* livro, Usuario* usuario, bool ativo, const std::string& data)
    : refLivro(livro), refUsuario(usuario), ativo(ativo), dataEmprestimo(data)
{
    refLivro->emprestar();
}

void Emprestimo::finalizar(const std::string& data) {
    if (ativo) {
        ativo = false;
        dataDevolucao = data;
        refLivro->devolver();
    }
}

bool Emprestimo::isAtivo() const {
    return ativo;
}

Livro* Emprestimo::getLivro() const {
    return refLivro;
}

Usuario* Emprestimo::getUsuario() const {
    return refUsuario;
}