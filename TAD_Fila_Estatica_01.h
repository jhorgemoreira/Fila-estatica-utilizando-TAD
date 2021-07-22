#define MAX 3

typedef struct {

    int tamanho_fila;
    ALUNO_FILA aluno_f[MAX];

}FILA;

typedef FILA fila;

void Inicializar_Fila(fila *f);
int Lista_Cheia(fila *f);
int Inserir_Fila(fila *f, int i, aluno_fila e);
int Remover_Fila(fila *f, int i);
int Imprimir_Fila(fila *f, int i, aluno_fila *e);
int Primeiro_Fila(fila *f, aluno_fila *e);
int Tamanho_Fila(fila *f);
int Gravar_Arquivo(fila *f, int i, aluno_fila *e);
void Excluir_Todos(fila *f);

void Inicializar_Fila(fila *f) {

    f->tamanho_fila = 0;

}

int Lista_Cheia(fila *f) {

    return (f->tamanho_fila == MAX);

}

int Inserir_Fila(fila *f, int i, aluno_fila e) {

    if(i == MAX) {

        return 0;

    }

    else {

        f->aluno_f[f->tamanho_fila] = e;
        f->tamanho_fila++;

        return 1;

    }

}

int Remover_Fila(fila *f, int i) {

    if(f->tamanho_fila == 0) {

        return 0;

    }

    else {

        if(i == 0) {

            for(i = 0; i < f->tamanho_fila; i++) {

                f->aluno_f[i] = f->aluno_f[i + 1];

            }

            f->tamanho_fila--;

        }

        return 1;

    }

}

int Imprime_Fila(fila *f, int i, aluno_fila *e) {

    if(i < f->tamanho_fila) {

        *e = f->aluno_f[i];

        return 1;

    }

}

int Primeiro_Fila(fila *f, aluno_fila *e) {

    if(f->tamanho_fila == 0) {

        return 0;

    }

    else {

        *e = f->aluno_f[0];

        return 1;

    }

}

int Tamanho_Fila(fila *f) {

    return f->tamanho_fila;

}

int Gravar_Arquivo(fila *f, int i, aluno_fila *e) {

    if(f->tamanho_fila == MAX) {

        *e = f->aluno_f[i];

        return 1;

    }

    else {

        return 0;

    }

}

void Excluir_Todos(fila *f) {

    f->tamanho_fila = 0;

}
