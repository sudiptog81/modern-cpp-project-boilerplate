# Modern C++ Project Boilerplate

Boilerplate code for a [cmake](https://gitlab.kitware.com/cmake/cmake) project using [vcpkg](https://github.com/microsoft/vcpkg) as the package manager. Demonstrates simple [boost](https://github.com/boostorg/boost) and [GNU Scientific Library](https://www.gnu.org/software/gsl/) functions.

## Quick Start

Set up [vcpkg](https://github.com/microsoft/vcpkg) at `C:\VCPKG` by following instructions given on [this page](https://github.com/microsoft/vcpkg).

Install dependencies using [vcpkg](https://github.com/microsoft/vcpkg) by executing `vcpkg install boost:x64-windows gsl:x64-windows` in PowerShell or CMD.

Run [cmake](https://gitlab.kitware.com/cmake/cmake) build routine using [MinGW-w64 make](https://sourceforge.net/p/mingw-w64/wiki2/Make/) by running `make all` . Executable shall be found in `.\build\Debug` folder if using the MSVC Compiler. 

## Output of Boilerplate
```bash
PS> .\build\Debug\example.exe
0 3 6 9 12 15 18 21 24 27
Product 98745636214564698 * 7459874565236544789 = 736630060025131838840151335215258722
x =
0.864758
0.945630
0.799511
0.862723
```

## Author

[Sudipto Ghosh](https://sudipto.ghosh.pro) sudipto[at]ghosh[dot]pro