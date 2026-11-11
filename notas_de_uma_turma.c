
//Lúcia Januário dos Santos - Matrícula: 202608152969  
//Questão nº 1 da lista de trabalhos

#include <stdio.h>
int main()
{
    //Declaração de variáveis
    int num_alunos, i, j, k = 0, aprovado,recuperacao, reprovado, continuar;
    float soma, maior_media = 0, menor_media = 0, soma_media_turma;

    //'do-while' para cumprir o desafio de ler várias turmas
    do
    {
        printf("\n\t============== LENDO TURMA %d ==============", k + 1);

        k++; //Contador para informar a turma atual

        // Solicitando a quantidade de alunos da turma
        printf("\nInforme o total de alunos na turma: ");
        scanf("%d", &num_alunos);

        // Declarando matrizes que dependem da quantidade de alunos da turma
        // Duas matrizes para armazenar os nomes dos alunos e as notas; Um vetor para armazenar as médias
        float notas[num_alunos][3], media[num_alunos];
        char nome_alunos[num_alunos][50];
        
        //Inicializando as 3 variáveis no inicio do 'do-while' para zera-lás a cada turma lida
        soma_media_turma=0; 
        aprovado=0;
        recuperacao=0;
        reprovado=0;

        // LEITURA DE DADOS
        for (i = 0; i < num_alunos; i++)
        {
            getchar(); // Limpa o buffer para ler uma string
            printf("\n\t-------------------------------------------\n[ALUNO %d]", i + 1);
            printf("\n\nInforme o nome do aluno %d: \n", i + 1);
            fgets(nome_alunos[i], 50, stdin); // armazenando cada nome em uma linha da matriz
            // Recebe nomes com limitação de 49 caracteres

            soma = 0; // Variável para acumular as notas lidas

            // Leitura das notas AV1 , AV2 e AV3
            for (j = 0; j < 3; j++)
            {
                printf("\nInforme a nota %d do aluno: ", j + 1);
                scanf("%f", &notas[i][j]);
                
                //Trava para ler somente notas de 0 a 10
                while ((notas[i][j]<0)||(notas[i][j]>10))
                {
                      printf("\n NOTA INVÁLIDA! Por favor, informe uma nota positiva entre 0 e 10\n");
                      printf("\nInforme a nota %d do aluno: ", j + 1);
                      scanf("%f", &notas[i][j]);           
                }

                //Var. que soma as notas (AV1, AV2 e AV3)
                soma += notas[i][j];
            }
            media[i] = (soma / 3.0);      // média individual do aluno
            
            soma_media_turma += media[i]; // Acumulando as médias da turma
        }

        // SAIDA
        printf("\n\n\t\t\t=====INFORMAÇÕES DA TURMA %d====", k);

        // var's que receberão a maior e a menor média da turma
        //Inicialização inicial p/ fazer a comparação com a outras médias depois
        maior_media = media[0];
        menor_media = media[0];

        //saída de dados
        for (i = 0; i < num_alunos; i++)
        {
            // Saída dos dados individuais dos alunos
            printf("\n\nAluno %d - %s", i + 1, nome_alunos[i]);
            printf("Av1: %.2f \t Av2: %.2f \t Av3: %.2f\tMedia: %.2f\n", notas[i][0], notas[i][1], notas[i][2], media[i]);

            // Verificação da aprovação do aluno
            // 0 a 5: reprovado ; 5 a 7: recuperação ; 7 a 10 aprovado;
            if (media[i] >= 7){
                printf("APROVADO!");
                aprovado+=1;
            }
            else if (media[i] >= 5){
                printf("RECUPERAÇÃO!");
                recuperacao+=1;
            }
            else{
                printf("REPROVADO!");
                reprovado+=1;
            }

            // Atribuindo a maior e a menor média as variáveis
            if (maior_media < media[i])
                maior_media = media[i];

            if (menor_media > media[i])
                menor_media = media[i];
        }

        // Impressão da maior média, menor média e média da turma
        printf("\n\nMédia da turma: %.2f\tMaior média: %.2f\tMenor média: %.2f", (soma_media_turma / num_alunos), maior_media, menor_media);
        printf("\nAprovados: %d\t\tRecuperação: %d\t\tReprovação: %d", aprovado, recuperacao, reprovado);
       
        //Dando ao usuario a opção de ler as notas de mais uma turma
        printf("\n\n\n\t=============================================================\n");
        printf("\nVocê deseja continuar e informar uma nova turma?\nDigite 1 para continuar\nDigite 0 para encerrar\n");
        scanf("%d", &continuar);

    }
    while (continuar == 1);

    printf("\nPROGRAMA ENCERRADO\n");

    return 0;
}