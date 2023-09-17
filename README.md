
# Custom Printf Function in C

## Table of Contents
- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## Overview
This repository contains a custom implementation of the standard C library's `printf` function, following the guidelines and requirements of a specific project. This custom `printf` function aims to replicate the core functionalities of the original function, providing a means for formatted output.

## Installation
To clone this repository, run the following command in your terminal:
```bash
git clone https://github.com/your_username/printf.git
```

## Usage
Include `main.h` in your C file and call the `_printf` function as you would with the standard `printf`:
```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!", "world");
    return (0);
}
```

## Features
This custom `printf` supports the following format specifiers:
- `%c`: Character
- `%s`: String
- `%d`: Decimal
- `%i`: Integer
- More to come...

## Requirements
- Ubuntu 20.04 LTS
- gcc compiler with options `-Wall -Werror -Wextra -pedantic -std=gnu89`

## Compilation
Compile your files using:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

## Testing
We encourage you to collaborate on a set of tests to validate the functionality of this custom `printf`.

## Contributing
If you would like to contribute to this project, please fork the repository, create a new branch for your work, and submit a pull request.

## License
This project is licensed under the MIT License.

## Authors
- Ahmed Mahmoud - [GitHub: gwaez](https://github.com/gwaez)
- Aya Abdelaziz - [GitHub: Ayaalasd1](https://github.com/Ayaalasd1)

## Acknowledgments
This project was created as part of the ALX Cohort 18 curriculum.

