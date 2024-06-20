g++ D_GCD_sequence.cpp -o code
g++ brute.cpp -o brute
g++ gen.cpp -o gen

for((i = 1; ; ++i)); do
    ./gen $i > randomInput
    ./code <randomInput > myOutput
    ./brute <randomInput > bruteOutput
    diff -w myOutput bruteOutput || break
    echo "Passed test: "  $i
done

echo -e "\nWA on the following test:"
cat randomInput
echo "Your answer is:"
cat myOutput
echo "Correct answer is:"
cat bruteOutput
