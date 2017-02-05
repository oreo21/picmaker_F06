compile: picmaker.c
	gcc picmaker.c -o picmaker -lm

run: picmaker
	./picmaker

display: image.ppm
	display image.ppm

clean:
	rm picmaker image.ppm *~ *#
