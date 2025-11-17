# Como fazer esse troço

Niveis de memória, onde o último é equivalente a memória principal e todos os outros são cache.

Processador que simula loads e stores.

Cada memória deve ter
- nome 
- latência (em ciclos)
- associatividade 
- tamanho de cada conjunto associativo
- tamanho da linha 
- política de escrita.
- as linhas

A memória principal só tem nome e latência.

O processador manda um sinal para a hierarquia, seja load ou write, com um endereço de procura. esse endereço é procurado na cache, se não for achado é uma 'cache miss', se for encontrado é uma 'cache hit'.

from wikipedia:
´´´
## To place a block in the cache

    - The set is determined by the index bits derived from the address of the memory block.
    - The memory block is placed in an available cache line in the set identified, and the tag is stored in the tag field associated with the line. If all the cache lines in the set are occupied, then the new data replaces the block identified through the replacement policy.

## To locate a word in the cache

    - The set is determined by the index bits derived from the address of the memory block.
    - The tag bits are compared with the tags of all cache lines present in selected set. If the tag matches any of the cache lines, it is a cache hit and the appropriate line is returned. If the tag does not match any of the lines, then it is a cache miss and the data is requested from next level in the memory hierarchy.
´´´

- [x] Permitir configurar um número arbitrário de níveis de memória cache.
- [x] O último nível da hierarquia de memória deverá ser a memória principal, que deverá ser configurável seu nome e sua latência (em ciclos).
- [x] O primeiro nível da hierarquia de memória, bem como todos os níveis intermediários, deverá ser de memória cache.
- [+-] Todas as memórias cache deverão ser conjunto-associativas.
- [x] Para cada cache, deverá ser permitido configurar um nome, latência (em ciclos), associatividade, número de conjuntos associativos, tamanho da linha e política de escrita. O tamanho final da cache se dará por:
TamanhoCache = Associatividade * NúmeroConjuntos * TamanhoLinha
- [x] O tamanho da linha deve ser o mesmo em todas as caches.
- [] As políticas de escrita a serem suportadas são: Write-through e Write-back.
- [x] Quando uma cache não encontra o dado requisitado, deverá buscar no próximo nível da hierarquia de memória.
- [] Usar uma política LRU para substituição de linhas de cache.
- [x] Deverá somar as latências de cada nível até encontrar o dado para calcular a latência total.
- [x] Deverá ter um objeto que representa o processador, que gera o padrão de acessos à memória segundo um determinado padrão e encaminha ao primeiro nível da hierarquia de memória.
- [+-] O processador deverá suportar a geração de 2 padrões de acesso à memória: sequencial e aleatório.
- [x]Cada acesso à memória gerado pode ser de leitura ou escrita.
- [x] No padrão sequencial deverá ser configurável o stride (a distância entre dois acessos consecutivos).
- [x] Para ambos padrões de acessos, deverá ser configurável o tamanho do buffer, de forma que todos os endereços de memória gerados estejam dentro do buffer.
- [x] Para ambos padrões de acessos, deverá ser configurável a quantidade de acessos à memória a serem gerados. Para o padrão sequencial, quando o endereço de memória atingir o tamanho do buffer, o acesso seguinte deverá ser zero (ou início do buffer).
- [+-] Após realizados todos os acessos à memória, deverá imprimir o tempo total de execução (em ciclos) e estatísticas de cada nível da hierarquia de memória.
- [] Para a memória principal, deverá imprimir a quantidade de acessos de leitura e de escrita.
- [+-] Para cada cache, deverá imprimir seu tamanho (em KBytes), a quantidade de acessos de leitura e de escrita, quantidade de hits e misses, taxa de misses.
