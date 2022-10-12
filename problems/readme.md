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
[Como Treinar Seu Dragão](https://www.beecrowd.com.br/judge/pt/problems/view/1851) | upsolve | treino zatesko 17.08
[Decoration](https://codeforces.com/gym/103081/problem/G) | upsolve | SWERC 2020-2021, treino time
[Safe Distance](https://codeforces.com/gym/103081/problem/C) | upsolve | SWERC 2020-21, treino time
[Consulta e Alteração](https://www.beecrowd.com.br/judge/pt/problems/view/3306?) | upsolve | lazy segtree com gcd
[Delivering Pizza](https://codeforces.com/gym/103274/problem/D) | upsolve | treino time
[Sticker Album](https://codeforces.com/gym/102861/problem/A) | upsolve | ideia importante
[Componentes Conexas Atacam Novamente](https://codeforces.com/gym/102020/problem/C) | upsolve | segtree de dsu
[Chimambu](https://www.beecrowd.com.br/judge/pt/challenges/view/685/3) | upsolve | maratona fase zero 2022

# To-do Contests
**Focusing on atcoder beginner contests, codeforces educational rounds and (most of all) ICPC [sub]regionals**

contest | notes
---|---
[2022-2023 ICPC Brazil Subregional Programming Contest](https://codeforces.com/gym/103960) | já fiz alguns mas nem todos, meio upsolve meio to solve
[FASE ZERO DA MARATONA DE PROGRAMAÇÃO DA SBC](https://www.beecrowd.com.br/judge/pt/contests/view/685) | já fiz alguns mas nem todos, meio upsolve meio to solve

# To-do Notebook
This is here because all the other to-do lists are here. Content to study/add to notebook/record an explanation

topic | resources | notes
---|---|--
Euler Path | [cp-algorithms](https://cp-algorithms.com/graph/euler_path.html) | provar + explicar + caderno (complexidade melhor que o algoritmo do caderno)
