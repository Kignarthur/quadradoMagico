#include <iostream>
using namespace std;

const int N = 15;
int quadrado [N][N];

void quadradoMagico()
{
    // INPUT
    int n; cin >> n;

    for ( int linha = 0; linha < n; ++linha )
    {
        for ( int coluna = 0; coluna < n; ++coluna)
        {
            cin >> quadrado[linha][coluna];
        }
    }
    
    // PROCESSAMENTO
    int soma = 0, somaDiagonal = 0, somaDiagonalReversa = 0;
    bool quadradoMagico = true;

    for ( int i = 0; i < n; ++ i )
    {
        soma += quadrado[i][0];
        somaDiagonal += quadrado[i][i];
        somaDiagonalReversa += quadrado[n-1-i][i];
    }

    if ( somaDiagonal != soma || somaDiagonalReversa != soma )
    { quadradoMagico = false; }

    else
    {
        for ( int linha = 0; linha < n; ++linha )
        {
            int somaLinha = quadrado[linha][0];
            int somaColuna = quadrado[0][linha];

            for ( int coluna = 1; coluna < n; ++coluna)
            {
                somaLinha += quadrado[linha][coluna];
                somaColuna += quadrado[coluna][linha];
            }

            if ( somaLinha != soma || somaColuna != soma )
            {
                quadradoMagico = false;
                break;
            }
        
        }
    }
    
    // OUTPUT
    if ( quadradoMagico == true ){ cout << soma; }        
    else { cout << -1; }
}

int main()
{
    quadradoMagico();

    return 0;
}