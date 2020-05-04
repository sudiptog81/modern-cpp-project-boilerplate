all:
	cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=C:/VCPKG/scripts/buildsystems/vcpkg.cmake
	cmake --build build
clean:
	rmdir /q /s build
run:
	./build/Debug/example