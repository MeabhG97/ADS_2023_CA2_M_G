# Algorithms and Datastructures CA

[Link to Repository](https://github.com/MeabhG97/ADS_2023_CA2_M_G)

## Requirements
- Cmake version 3.22+
- C++ 11 compiler or higher

## How to Run
- Get the app
```zsh
git clone git@github.com:MeabhG97/ADS_2023_CA2_M_G.git
cd ADS_2023_CA2_M_G
```

- To run the app
```bash
cmake -S . -B build
cmake --build build
cd build/app
./app
```

- To run the tests
```bash
cmake -S . -B build
cmake --build build -t test
```

- Tests can also be accessed at
```bash
cd build/test
./tests
```