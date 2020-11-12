set -e
g++ code.cpp -o code
g++ gen.cpp -o gen
g++ brute.cpp -o brute
for((i = 1; ; ++i)); do
    echo $i "passed"
    ./gen $i > int
    ./code < int > out1
    ./brute < int > out2
    diff -w <(./code < int) <(./brute < int) || break
done
echo "WA on the following test:"
cat int
echo "Your answer is:"
cat out1
echo "Correct answer is:"
cat out2