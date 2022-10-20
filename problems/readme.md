This is in both Portuguese and English

# Life Editorial
All problems that I solve after october 8, 2022.

Leave two spaces before and after each problem to make this more readable.


**[Weird Algorithm](cses/weird_algorithm.cpp)** - [CSES](https://cses.fi/problemset/task/1068/) (09/10/22) [ad hoc]

This is an implementation of the [Collatz conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture).
n gets pretty big so you need a `long long`

---

**[Números Virados](icpc/subbr2022/n.cpp)** - [ICPC BR Subregional 2022](https://codeforces.com/gym/103960) (11/10/22) [sliding window, implementation]

Mantém uma sliding window que vai dos k últimos até o k-ésimo (i.e., começa na direita e vai até a esquerda), aí mantém uma estrutura pra pegar o cara com maior B que não tá virado e tá na sliding window e o cara com menor B que tá virado. Cuidado com a implementação, ficar atualizando resposta etc é bem complicadinho (o jeito mais fácil é virar os primeiros L da primeira sliding window, depois ir adicionando mais gente)

---

**[Nine Is Greater Than Ten](gymcf/shanghaicpc2022/n.cpp)** - [2022 Shanghai Collegiate Programming Contest](https://codeforces.com/gym/103931) (12/10/22) [string]

Faz comparação lexicográfica dos dois números (i.e., lê como string)

---

**[My University Is Better Than Yours](gymcf/shanghaicpc2022/m.cpp)** - [2022 Shanghai Collegiate Programming Contest](https://codeforces.com/gym/103931) (12/10/22) [graph, scc]

Faz um grafo direcionado a partir de todos os rankings, onde existe aresta `(v, u)` se `v` aparece log antes de `u` em algum ranking (i.e., adjacentes).

Roda kosaraju pra pegar os SCCs. Pra cada SCC, guarda quantos vértices tem nele. Depois, recursivamente, um SCC atualiza essa quantidade somando o número guardado pelos seus SCCs filhos (i.e., ele guarda a soma da subarvore dele).

Pra cada vértice, a resposta vai ser o número guardado pelo seu SCC - 1 (pq ele tá sendo contado).

Tem que usar SCC porque podem existir ciclos.

---

**[Missing Number](cses/missing_number.cpp)** - [CSES](https://cses.fi/problemset/task/1083/) (13/10/22) [ad hoc]

Just keep a `vector<bool>` to know which numbers are printed

---

**[Repetitions](cses/repetitions.cpp)** - [CSES](https://cses.fi/problemset/task/1069/) (13/10/22) [ad hoc]

For each char in `ACGT`, for each char in the input string: keep a counter that increases when you see the selected character, else it drops to zero (and save its maximum)

---

**[Álbum de Figurinhas](icpc/subbr2020/a.cpp)** - [ICPC BR Subregional 2020](https://codeforces.com/gym/102861) (13/10/22) [probability, expected value, sliding window]

Seja `E(x)` o número de pacotes necessários pra obter `x` figurinhas. `E(0) = 0`; `E(i < A) = 1`.

Já que um pacote tem chance igual de ter qualquer número no intervalo `[A, B]`, seja `L = B-A+1` (tamanho do intervalo). Então para todo `x >= A`:

```
E(x) = 1 (precisa abrir pelo menos um pacote) + (1/L)*Somatorio(E(x-A)..E(x-B))
```

Você pode calcular essa soma com uma janela deslizante para caber em O(N).

Se `A = 0`, o `E(x)` aparece dos dois lados da equação, mas vc ainda consegue isolar ele e obter
```
E(x) = (L/(L-1))*(1 + (1/L)*Somatorio(E(x-A)..E(x-B)))
```

---

**[Increasing Array](cses/increasing_array.cpp)** - [CSES](https://cses.fi/problemset/task/1094/) (17/10/22) [ad hoc]

O problema pede que `v[i] >= v[i-1]` para todo `0 < i < n`. O único caso em que você precisa mudar algo é quando `v[i] < v[i-1]`, e nesse caso o menor número de operações é o necessário para chegar em `v[i] == v[i-1]` (`v[i-1] - v[i]`).

---

**[Permutations](cses/permutations.cpp)** - [CSES](https://cses.fi/problemset/task/1070/) (17/10/22) [ad hoc, permutations]

Se `n == 1`, basta imprimir `1`.

Se `n < 4`, não existe solução.

Caso contrário, separe a sequência `1..n` em duas metades: `1..(n/2)` e `(n/2+1)..n`. Sejam essas metades `A` e `B`. A resposta será `B[1] A[1] B[2] A[2] ...`. No caso em que `n` é ímpar, basta imprimir também B[n/2 + 1].

---

**[Password](codeforces/cf1743/a.cpp)** - [Codeforces](https://codeforces.com/contest/1743) (19/10/22) [permutations, combinations, counting]

Se você escolhe dois dígitos, tem 6 possibilidades de senha. Digamos que sejam os dígitos X e Y.

O início pode ser XX ou YY, e aí os últimos 2 dígitos são o outro (XX ou YY, respectivamente). Então são 2 possibilidades: XXYY e YYXX.

Se o início for XY ou YX (2 possibilidades), os próximos dois podem ser tanto XY quanto YX (2 possibilidades). Então são 2x2 = 4 possibilidades (XYXY, XYYX, YXXY, YXYX).

Então são 6 possibilidades.

Se ele sabe que **não** foram usados `n` dígitos, você pode escolher qualquer par de dígitos entre `10-n`. Então a resposta é `6*(n!)/(2*(n-2)!)` (6 * n escolhe 2).

---

**[Permutation Value](codeforces/cf1743/b.cpp)** - [Codeforces](https://codeforces.com/contest/1743) (19/10/22) [permutations, subsegments]

Pra que um subsegmento seja permutação, ele precisa ter todos os números de `1` até algum `n`, então dois subsegmentos sempre são inclusos: a permutação inteira e o subsegmento `[1]`.

Se você começa uma permutação com `1`, pra um outro subsegmento ser permutação ele precisa começar na primeira posição (porque precisa incluir o número `1`).

Se você termina uma permutação com `2`, pra um outro subsegmento ser permutação ele precisa terminar na última posição (porque precisa incluir o número `2`).

Então, uma solução sempre é `1 [n..3] 2`.

---

**[Save the Magazines](codeforces/cf1743/c.cpp)** - [Codeforces](https://codeforces.com/contest/1743) (19/10/22) [subsegments, greedy]

Note que em qualquer subsegmento (em relação às tampas) no estilo `01+` (`01`, `011`, `011`...), você pode salvar todas as caixas menos uma, e a que você não salva é arbitrária (pode escolher qualquer uma).

Então a solução gananciosa é, para toda sequência no estilo `01+`, somar à resposta os números de todas as caixas, e depois subtrair o mínimo.

---

**[A Recursive Function](atcoder/abc273/a.cpp)** - [AtCoder](https://atcoder.jp/contests/abc273) (20/10/22) [factorial]

Só computar fatorial <= 10

---

**[Broken Rounding](atcoder/abc273/b.cpp)** - [AtCoder](https://atcoder.jp/contests/abc273) (20/10/22) [ceil, floor]

Pra cada potência P de 10, escolhe entre teto(X/P) e chão(X/P) (pega o mais próximo e, se forem iguais, pega o teto).

---

**[(K+1)-th Largest Number](atcoder/abc273/c.cpp)** - [AtCoder](https://atcoder.jp/contests/abc273) (20/10/22) [coordinate compression]

Faz compressão de coordenadas e vê quantas coordenadas tem que são maiores que a coordenada de cada elemento, aí guarda num vetor de respostas

---

**[Problem name](readme.md)** - [link to problem - judge name](readme.md) (dd/mm/yy) [topics, separated, by, commas]

Solution + Takeaways/Comments/Analysis/Resources

Preferably with hints first, e.g.,
- **Hint 1:** (hint)
- **Hint 2:** (hint)
(and then the full solution)


# To-do Problems
**Focusing on CSES**
problem | type | Comments/idea/what I've tried
---|---|---
[Decoration](https://codeforces.com/gym/103081/problem/G) | upsolve | SWERC 2020-2021, treino time
[Safe Distance](https://codeforces.com/gym/103081/problem/C) | upsolve | SWERC 2020-21, treino time
[Consulta e Alteração](https://www.beecrowd.com.br/judge/pt/problems/view/3306?) | upsolve | lazy segtree com gcd
~[Delivering Pizza](https://codeforces.com/gym/103274/problem/D)~ | ~upsolve~ | ~treino time~
[Componentes Conexas Atacam Novamente](https://codeforces.com/gym/102020/problem/C) | upsolve | segtree de dsu
[Chimambu](https://www.beecrowd.com.br/judge/pt/challenges/view/685/3) | upsolve | maratona fase zero 2022
[LRUD Instructions](https://atcoder.jp/contests/abc273/tasks/abc273_d) | upsolve | abc 273

# To-do Contests
**Focusing on atcoder beginner contests, codeforces educational rounds and (most of all) ICPC [sub]regionals**

contest | notes
---|---
[2022-2023 ICPC Brazil Subregional Programming Contest](https://codeforces.com/gym/103960) | já fiz alguns mas nem todos, meio upsolve meio to solve
[FASE ZERO DA MARATONA DE PROGRAMAÇÃO DA SBC](https://www.beecrowd.com.br/judge/pt/contests/view/685) | já fiz alguns mas nem todos, meio upsolve meio to solve
[2020-2021 ACM-ICPC Brazil Subregional Programming Contest](https://codeforces.com/gym/102861) | já fiz algumas

# To-do Notebook
This is here because all the other to-do lists are here. Content to study/add to notebook/record an explanation

topic | resources | notes
---|---|--
Euler Path | [cp-algorithms](https://cp-algorithms.com/graph/euler_path.html) | provar + explicar + caderno (complexidade melhor que o algoritmo do caderno)
