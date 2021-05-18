for BENCH in ./1000-llamas/*; do
    echo $BENCH
	./parser < $BENCH
done