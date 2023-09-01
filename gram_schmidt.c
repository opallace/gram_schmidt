#include <stdio.h>
#include <math.h>

void print_base(double **base, int n){
    printf("[");
    for (int i = 0; i < n; i++){
        printf("[");
        for (int j = 0; j < n; j++){
            if(j < n-1){
                printf("%.1lf,", base[i][j]);
            }else {
                printf("%.1lf", base[i][j]);
            }
        }
        if(i < n-1){
            printf("],");
        }else {
            printf("]");
        }
    }
    printf("]");
}

double tamanho_vetor(double *vetor, int n){
    double somatorio = 0;

    for (int i = 0; i < n; i++){
        somatorio += pow(vetor[i], 2); 
    }
    
    return sqrt(somatorio);
}

double* divide_vetor(double *vetor, int n, double value){
    for (int i = 0; i < n; i++){
        vetor[i] /= value;
    }

    return vetor;
}

void gram_schmidt(double **base_original, double **base_de_gram_schmidt, int n){
    base_de_gram_schmidt[0] = divide_vetor(base_original[0], n, tamanho_vetor(base_original[0], n));

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            
        }

        base_de_gram_schmidt[i] = divide_vetor(base_original[i], n, tamanho_vetor(base_original[i], n));
    }
    
}

int main(){
    double base_original[3][3] = {{1,0,0}, {0,1,0}, {0,0,1}};
    double base_de_gram_schmidt[3][3];

    print_base(base_original, 3);

    gram_schmidt(base_original, base_de_gram_schmidt, 3);

    print_base(base_de_gram_schmidt, 3);

    return 0;
}