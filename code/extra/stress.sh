## Stress
for (( I=0; I < 5; I++ )); do
  ./gen $I > a.in
  ./brute < a.in > expected.txt
  ./a.out < a.in > output.txt
  if diff -u expected.txt output.txt; then : ; else
    echo "--> input:"; cat a.in
    echo "--> expected output:"; cat expected.txt
    echo "--> received output:"; cat output.txt
    break
  fi
  echo -n .
done
