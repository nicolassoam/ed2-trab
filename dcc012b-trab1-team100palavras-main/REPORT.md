# REPORT: Team 100 palavras  
Lucas Marins Ramalho de Lima  
Maria Luísa Riolino Guimarães  
Nicolas Soares Martins  

20 de junho de 2022

---

- [Resumo da abordagem final](https://github.com/ufjf-dcc-josecamata/dcc012b-trab1-team100palavras/blob/main/REPORT.md#resumo-da-abordagem-final)  
- [Descrição das sprints e divisão de tarefas](https://github.com/ufjf-dcc-josecamata/dcc012b-trab1-team100palavras/blob/main/REPORT.md#descri%C3%A7%C3%A3o-das-sprints-e-divis%C3%A3o-de-tarefas)  
- [Principais desafios e mudanças de planos](https://github.com/ufjf-dcc-josecamata/dcc012b-trab1-team100palavras/blob/main/REPORT.md#principais-desafios-e-mudan%C3%A7as-de-planos)  
- [Resultados dos testes de desempenho](https://github.com/ufjf-dcc-josecamata/dcc012b-trab1-team100palavras/blob/main/REPORT.md#resultados-dos-testes-de-desempenho)

## Resumo da abordagem final

Para desenvolver um programa que lê e processa arquivos ASCII para encontrar as palavras mais usadas na língua portuguesa, criamos uma tabela hash como um ponteiro duplo do tipo lista encadeada. Cada nó da lista encadeada é uma struct (denominada hashvec) que armazena o par (palavra,contador). 

O contador é incrementado cada vez que uma palavra já registrada é encontrada no texto, e uma colisão ocorre quando existem palavras diferentes com uma mesma chave. Nesse caso, o programa segue para o próximo nó da lista ou, caso seja uma palavra inédita, um novo nó é criado.

Para ignorar palavras específicas na leitura dos textos foi criado um arquivo chamado ignore.csv, no qual todas as palavras que forem anexadas naquela lista não serão colocadas na hashtable. Para adicionar qualquer palavra basta seguir a formatação do texto desse ficheiro, separando as palavras com ;. 

Optamos por criar a chave a partir da soma das letras da palavra, apesar de não ser a abordagem mais otimizada, pois isso facilitou a implementação dos testes. Ao final da extração, as 50 palavras mais usadas são classificadas ao passarmos os dados das hashtable para um vetor, que é ordenado com um dos métodos de ordenação disponíveis. Por fim, registramos estas palavras e seus respectivos contadores em um arquivo de output.

Ao longo deste documento, descreveremos como o grupo se organizou, quais foram nossas principais dificuldades e quais foram os resultados obtidos.

## Descrição das sprints e divisão de tarefas

Durante todo o período de elaboração deste trabalho, o grupo se organizou dividindo tarefas individuais e, posteriormente, se reunindo para discutir estratégias, corrigir erros encontrados e desenvolver partes do código em conjunto. Para isso, utilizamos o Live Share do VS Code enquanto estávamos em chamadas em grupo.  

De forma simplificada, inicialmente a divisão das tarefas foi a seguinte: 

- Marins: configuração do CMAKE, leitura dos arquivos, métodos de ordenação
- Maria: TAD lista encadeada, testes, organização das funções
- Nicolas: TAD hash, métricas, funcionamento da hashtable

Ao final do processo, entretanto, percebemos que todos os membros influenciaram em praticamente todas as partes do código, corrigindo bugs, sugerindo implementações alternativas, auxiliando na parte lógica, etc., o que dificulta uma descrição precisa da divisão das tarefas.

---

### Sprint #1
Na primeira etapa de desenvolvimento do projeto configuramos o CMAKE, separamos algumas das palavras que devem ser ignoradas e nos reunimos para discutir abordagens iniciais para a implementação do algoritmo. 

A ideia do grupo foi, inicialmente, implementar uma rotina para organizar o nome dos arquivos em um arquivo de texto. Decidimos nos concentrar na funcionalidade do programa para, posteriormente, otimizá-lo.

### Sprint #2
Fizemos a implementação de diversas funções hash (hash1, hash2, hash3, hash4 e hash5), além de implementarmos as funções de busca, inserção e remoção no hash (arquivo hash.cpp). Algumas funções foram criadas no TAD da lista encadeada para auxiliar nesse processo.

Criamos uma função somaPalavras, que recebe a palavra e a transforma em um inteiro, para podermos realizar as operações que geram as chaves da hash table. A ideia é, futuramente, otimizar esta função para reduzir o número de colisões.

Discutimos abordagens lógicas para o trabalho, como a melhor forma de percorrer o hashmap e passar as 50 palavras para o vetor, e os métodos de ordenação escolhidos. Optamos por utilizar QuickSort, InsertSort, MergeSort e TIMSort.

O grupo encontrou alguma dificuldade em transitar por todos os arquivos e métodos utilizados, especialmente devido aos atributos privados e diversos ponteiros e endereços de memória. Ao longo da sprint, entretanto, começamos a nos localizar melhor no código e conseguimos evoluir bastante no desenvolvimento do mesmo. 

### Sprint #3
No início da terceira sprint, o grupo se concentrou em corrigir erros encontrados no código que impediam a compilação do mesmo. Decidimos, observando as funções implementadas, que a utilização de templates não era necessária na maior parte dos casos. Prosseguimos, então, alterando returns, lógicas de execução e parâmetros. A conferência do código em grupo foi muito útil, pois pudemos entender melhor o que foi desenvolvido por cada membro, alinhando a lógica aplicada. 

Após corrigirmos todos os erros de compilação, tentamos começar a implementar os testes e as métricas.

### Sprint #4 
Dando continuidade à criação de testes e comparação de métricas dos métodos de ordenação implementados, tivemos dificuldades com alguns problemas em funções que não haviam sido testadas previamente. Seguimos, então, corrigindo cada uma dessas funções, já visando os testes que gostaríamos de aplicar.

Esse processo foi muito produtivo, pois incentivou uma nova análise, ainda mais profunda, de todo o nosso código. Implementamos a busca binária dentro da função que ignora preposições, artigos e pronomes para melhorar a performace dessa - visto que ela é chamada dezenas de milhares de vezes durante a execução do código de leitura.

Criamos os testes unitários para testar todas as funções da tabela hash. Passamos para os arquivos do teste todas as funções hash que anteriormente estavam na hash.cpp para que pudéssemos comparar diferentes distribuições de dados pela tabela e número de colisões.

Nessa sprint nos dedicamos, especialmente, a automatizar os testes utilizando o CTest. Também implementamos as últimas funcionalidades descritas no README que ainda não haviam sido consideradas, como a escrita das 50 palavras mais repetidas em cada texto em arquivos de output.

Por fim, revisamos todo o código e verificamos os testes.

## Principais desafios e mudanças de planos

### Implementação do searchFiles
1. Tentamos uma primeira abordagem utilizando dirent.h para escrever no listaArquivos o nome de todos os arquivos do diretório. Encontramos alguma dificuldade em ignorar o file_name e os pontos que indicam o caminho do diretório nessa leitura, especialmente por não entendermos a ordem de execução da mesma. Seguimos, então, pesquisando outras formas de implementar a função.

2. Pesquisando outras opções de implementação, resolvemos tentar utilizar a filesystem, biblioteca do C++17. Ela resolveu o problema dos pontos, mas ainda incluía o file_name na escrita do arquivo, assim como os endereços completos entre aspas. Resolvemos estes problemas utilizando .string() para retirar as aspas da path e trocando o diretório do arquivo que contém os nomes dos outros arquivos.

3. Percebemos que a implementação escolhida para o searchFiles compilou corretamente em apenas alguns compiladores (devido à utilização da filesystem, que é relativamente nova). Entretanto, optamos por mantê-la. Para isso, foi necessária a alteração do arquivo CMakeList, adicionando o set(CMAKE_CXX_STANDARD 17).

4. Ao final, resumimos esta e outras funções na classe manager.

### Implementação do readingFile
1. Dentro da função readingFile() o programa armazena, num vetor, todos os diretórios dos arquivos que utilizamos na pesquisa das palavras e que em seguida serão abertos um por um. A leitura desses arquivos também é feita na função.

2. O grande problema enfrentado na implementação dessa leitura foi a comparação das palavras do arquivo com a lista de palavras a serem ignoradas na nossa indexação (que engloba preposições, artigos e alguns pronomes). Para resolver esse problema, alteramos a forma com a qual a lista de palavras a serem ignoradas estava organizada e separamos cada elemento dessa lista com um ';', facilitando a leitura e a separação correta dessas palavras em strings.

### Utilização de templates
1. Inicialmente, optamos por utilizar templates na construção dos métodos para as classes Hash e LinkedList. Contudo, tal implementação restringiu o fluxo de desenvolvimento do código, tornando necessário a declaração inline (dentro do header de cada classe) dos métodos dos TADs LinkedList e Hash. Posteriormente, tentamos utilizar templates somente na struct hashVec, recebendo um inteiro c e um tipo template T palavra, que serviria de par (contador,palavra) em nossa implementação.

2. Após muitas considerações, removemos a utilização de templates nos TADs e na struct, sendo o uso destes restringido aos códigos de ordenação.

### Escolha da construção da hashtable
Ao longo do desenvolvimento do TAD Hash, foram utilizadas diferentes versões da hashtable.

1. A primeira versão utilizava um vector do tipo LinkedList<hashVec> (vector<LinkedList<hashVec>>), enquanto ainda existiam templates nos TADs Hash e LinkedList. 

2. Com a remoção dos templates, esta implementação da hashtable foi modificada para se adaptar ao novo código, recebendo um vector do tipo LinkedList (vector<LinkedList>). 

3. No decorrer da implementação dos métodos e dos testes, encontramos dificuldades na utilização de um vector para armazenar a tabela hash com as listas encadeadas. Modificamos novamente a hashtable, para sua versão final, sendo esta um ponteiro duplo do tipo LinkedList (LinkedList ** hashm).

## Resultados dos testes 

O livro utilizado para ambos os testes aqui descritos foi "Triste Fim de Polycarpo Quaresma", que está no diretório de inputs. Estes testes podem ser executados, respectivamente, em tests/test5 e tests/test6. Para o teste das funções hash, utilizamos o QUICKSORT como método de ordenação, e para o teste dos métodos de ordenação, utilizamos a HASH1. 

Observação: o texto receita_de_bolo.txt, incluído no diretório de inputs, está sendo utilizado no test1, que testa a importação das palavras por meio de um contador. Optamos por utilizar um texto curto neste teste tendo em vista seu objetivo, uma vez que textos muito grandes dificultariam sua verificação.

### Teste das funções Hash
> HASH 1  
>
> Quick Sort:  
> Tempo de execução: 0.0046701 segundos  
> Comparacoes: 226337  
> Movimentacoes: 215601  
> Numero de palavras: 42657  
> Numero de colisoes: 334435

> HASH 2  
>
> Quick Sort:  
> Tempo de execução: 0.008623 segundos  
> Comparacoes: 224552  
> Movimentacoes: 215037  
> Numero de palavras: 42657  
> Numero de colisoes: 242185867

> HASH 3  
>
> Quick Sort:  
> Tempo de execução: 0.0110843 segundos  
> Comparacoes: 223473  
> Movimentacoes: 213843  
> Numero de palavras: 42657  
> Numero de colisoes: 549769

> HASH 4  
>
> Quick Sort:  
> Tempo de execução: 0.0129839 segundos  
> Comparacoes: 217233  
> Movimentacoes: 209667  
> Numero de palavras: 42657  
> Numero de colisoes: 1257788

### Teste dos Métodos de Ordenação

> Insertion Sort  
> Tempo de execução: 0.700649 segundos  
> Comparacoes: 15662186  
> Movimentacoes: 15674198

> Quick Sort  
> Tempo de execução: 0.0043605 segundos  
> Comparacoes: 226337  
> Movimentacoes: 215601

> Merge Sort  
> Tempo de execução: 0.0292857 segundos  
> Comparacoes: 163796  
> Movimentacoes: 327592

> TIM Sort  
> Tempo de execução: 0.0087789 segundos  
> Comparacoes: 201113  
> Movimentacoes: 304977