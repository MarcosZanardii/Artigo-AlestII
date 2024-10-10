#include <iostream>
using namespace std;

void postOrder(string **TM, int i, int j, string atual, string sentido, int val, int *maior) {
    int ramo = val;
    bool percorrido = false;

    //processo para percorrer o ramo
    while (!percorrido) {
        if (isdigit(atual[0])) {
            ramo += stoi(atual);// soma val encontrado a nota do ramo
        }
        //alterar conforme caminho
        if(sentido == "e"){
            i--; j--;//diagonal esquerda
        }
        else if(sentido == "d")
            i--, j++;//diagonal  direita
        else{
            i--;//cima
        }
        atual = TM[i][j];  //atualiza o valor de "atual" para proxima cordenada
        if (atual == "V" || atual == "W" || atual == "#") percorrido = true;;//conforme valor, chega ao fim do ramo
    }

    //se valor do maior for menor que o valor gerado, altera
    if(ramo > *maior)
        *maior = ramo;

    //se chega em folha retorna
    if (atual == "#") return;

    postOrder(TM, i, j, atual, "e", ramo, maior);//realiza diagonal esquerda a partir do fim do ramo
    if(atual == "W")//se a ramificação for um "W", tambem se movimetna para cima     
        postOrder(TM, i, j, atual, "c", ramo, maior);//realiza diagonal esquerda a partir do fim do ramo
    postOrder(TM, i, j, atual, "d", ramo, maior);//realiza diagonal direita a partir do fim do ramo    
}

void TreeMatriz(string **tree, int linha, int coluna) {//armazena arvore em matriz
    for (int i = 0; i < linha; ++i) {
        tree[i] = new string[coluna];//pra cada linha, um numero de coluna
    }
    for (int i = 0; i < linha; i++) {
        string line;//var para ler a linha
        getline(cin, line);//le linha pelo temrinal e atribui a var
        for (int j = 0; j < coluna; j++) {
            if (j < line.length()) {//enquanto ainda estiver char na linha lida
                char c = line[j];
                if (isprint(c)) {//se imprimivel, nao vazio, armazena char a matriz
                    tree[i][j] = c;
                } else {
                    tree[i][j] = " ";//se nao mantem vazio
                }
            } else {
                tree[i][j] = " ";//apos acabar char na linha, preenche com vazio ate o fim da coluna
            }
        }
    }
}

int encontraRaiz(string **tree, int linha, int coluna) {//retorna posicao do primeiro elemento diferente de vazio da 1ª linha
    for (int i = 0; i < coluna; i++)
        if (tree[linha][i] != " ")
            return i;
    return -1;
}

void deleteTreeMatriz(string **tree, int linha) {//deleta matriz gerada
    for (int i = 0; i < linha; ++i)
        delete[] tree[i];
    delete[] tree;
}

int main() {
    int linha, coluna, maior = 0;//maior inicia com 0

    cin >> linha;//le n de linhas da arvore
    cin >> coluna;//le n de colunas da arvore
    cin.ignore(); //ignora o '\n' a leitura

    string **tree = new string*[linha];//cria matriz no qual vai ser armazenadad a arvore

    TreeMatriz(tree, linha, coluna);//chama função que preenche a matriz

    int raiz = encontraRaiz(tree, linha - 1, coluna);//encontra a raiz da matriz

    string atual = tree[linha - 1][raiz];//inicia um "atual" com origem na arvore

    postOrder(tree, linha, raiz, atual, "c", 0, &maior);//chama caminhamento postOrder

    cout << maior << endl;
    
    deleteTreeMatriz(tree, linha);//deleta matriz gerada

    return 0;
}