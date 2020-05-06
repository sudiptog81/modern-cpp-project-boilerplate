all:
	cmake -S . -B build
	cmake --build build --config Release -- -nologo -v:m
conan:
	conan install -if build -b missing .
clean:
	rmdir /q /s build
run:
	./build/bin/main