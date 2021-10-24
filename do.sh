if [ "$1" != "" ]; then
    cd edsger_lib
    ./libs.sh
    cd ..
    make
    ./parser < $1 > a.ll || exit 1
    llc a.ll -o a.s
    gcc -o a.out a.s ./edsger_lib/lib.a -no-pie -g
fi