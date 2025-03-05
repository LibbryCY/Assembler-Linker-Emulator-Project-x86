# Assembler, Linker, and Emulator Project (x86)

This project is a custom implementation of an **Assembler**, **Linker**, and **Emulator** for a simplified x86-like architecture. It allows you to write assembly code, assemble it into machine code, link multiple object files, and emulate the execution of the resulting program.

The project is designed to help users understand the inner workings of low-level programming, including how assembly code is translated into machine code and how programs are executed at the hardware level.

---

## Features

- **Assembler**: Converts assembly code (written in a custom x86-like syntax) into machine code.
- **Linker**: Combines multiple object files into a single executable.
- **Emulator**: Simulates the execution of the compiled program, providing insights into CPU behavior, memory management, and instruction execution.
- **Custom Instruction Set**: Supports a simplified subset of x86 instructions.
- **Debugging Support**: The emulator provides debugging features, such as step-by-step execution and register/memory inspection.

---

## Technologies Used

- **Programming Language**: C
- **Tools**: GCC (GNU Compiler Collection), Makefile for build automation
- **Platform**: Linux/Unix-based systems (compatible with Windows via WSL or similar tools)

---

## How to Build and Run the Project

### Prerequisites

- **GCC** installed on your system.
- **Make** installed for build automation.
- A Linux/Unix-based terminal (or Windows with WSL).

### Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/LibbryCY/Assembler-Linker-Emulator-Project-x86.git
   cd Assembler-Linker-Emulator-Project-x86
   ```

2. **Build the project**:
   Use the provided `run.sh` to compile the assembler, linker, and emulator:
   ```bash
   ./run.sh
   ```

3. **Run the tools**:
   - To assemble an assembly file:
     ```bash
     ./tests/start.sh
     ```
      (There are examples of using assembler, linker and emulator in start.sh)
---

## Project Structure

- **`src/`**: Contains the source code for the assembler, the linker, the emulator and all secondary files.
- **`inc/`**: Contains the header files for the assembler, the linker, the emulator and all secondary files.
- **`misc/`**: Contains the source code for the flex lexer and bison parser.
- **`tests/`**: Includes sample assembly files and test cases to validate the functionality of the assembler, linker, and emulator.
- **`run.sh`**: Automates the build process for the project.

---

## Example Workflow

1. Write an assembly program (e.g., `example.s`):
   ```asm
   .section math
   mathAdd:
    push %r2
    ld [%sp + 0x08], %r1
    ld [%sp + 0x0C], %r2
    add %r2, %r1 # r1 used for the result
    pop %r2
    ret
   .end
   ```

2. Assemble the program:
   ```bash
   ./asembler -o math.o ./tests/math.s
   ```

3. Link the object file (if multiple files are used):
   ```bash
   ./linker -hex -place=my_code@0x40000000 -place=math@0xf0000000 -o program.hex handler.o math.o main.o isr_terminal.o isr_timer.o isr_software.o
   ```

4. Emulate the executable:
   ```bash
   ./emulator program.hex
   ```

5. Observe the output and debug if necessary.

---

## Supported Instructions

The assembler and emulator support a simplified subset of x86 instructions, including:
- `MOV` (move data)
- `ADD` (addition)
- `SUB` (subtraction)
- `JMP` (jump)
- `CMP` (compare)
- `LD` (load)
- `ST` (store)
- `HLT` (halt)
- And more (check the documentation in the repository for a full list).

---

## Debugging with the Emulator

The emulator provides the following debugging features:
- **Step-by-step execution**: Execute one instruction at a time.
- **Register inspection**: View the contents of CPU registers.
- **Memory inspection**: View the contents of memory locations.
- **Breakpoints**: Pause execution at specific instructions.

To use debugging features, run the emulator with the `-d` flag:
```bash
./emulator -d output_executable
```

---

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Submit a pull request with a detailed description of your changes.

---

## Author

- **LibbryCY** - [GitHub Profile](https://github.com/LibbryCY)

---

## License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more details.
