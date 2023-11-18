debug:
	g++ -g -Og src/main.cpp -o bin/rwhich -lmagic

release:
	g++ -O2 src/main.cpp -o bin/rwhich -lmagic
	strip -s bin/rwhich

test:
	@echo testing with 'java.*'
	@./bin/rwhich 'java.*'
