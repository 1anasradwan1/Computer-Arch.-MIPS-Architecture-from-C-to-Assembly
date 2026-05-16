# MIPS Processor Simulation

> A simulation of a basic MIPS CPU showcasing datapath and control logic, written in C.

---

## Overview

This project simulates a simplified **MIPS processor**, implementing the core stages of instruction execution and demonstrating how hardware-level components interact within a real CPU pipeline.

---

## Objectives

- Understand the **structure** of a basic MIPS processor
- Execute MIPS instructions in a simulated software environment
- Practice hardware-level thinking and digital logic design
- Visualize how the **datapath** and **control unit** cooperate

---

## Architecture

### Pipeline Stages

```
Instruction Fetch (IF) → Instruction Decode (ID) → Execute (EX) → Memory (MEM) → Write Back (WB)
```

### Components

| Component       | Description                                          |
|-----------------|------------------------------------------------------|
| **ALU**         | Handles arithmetic (`add`, `sub`) and logic ops (`and`, `or`, `slt`) |
| **Register File** | 32 general-purpose 32-bit registers (`$zero` → `$ra`) |
| **Control Unit** | Decodes opcodes and generates datapath control signals |
| **Data Memory** | Supports `lw` / `sw` load and store instructions     |
| **PC**          | Program Counter , tracks the current instruction address |

---

## Supported Instructions

| Type   | Instructions                          |
|--------|---------------------------------------|
| R-Type | `add`, `sub`, `and`, `or`, `slt`      |
| I-Type | `lw`, `sw`, `beq`, `addi`             |
| J-Type | `j` (jump)                            |

---

## Project Structure

```
mips-project/
├── src/
│   ├── alu.c            # ALU logic
│   ├── control.c        # Control unit signal generation
│   ├── memory.c         # Data and instruction memory
│   ├── registers.c      # Register file (32 x 32-bit)
│   └── main.c           # Top-level simulation loop
├── include/
│   └── mips.h           # Shared types and definitions
├── tests/
│   └── test_alu.c       # Unit tests
└── README.md
```

---

## Getting Started

### Prerequisites

- GCC or any C99-compatible compiler
- `make` (optional but recommended)

### Clone the Repository

```bash
git clone https://github.com/1anasradwan1/mips-project.git

```

### Build

```bash
make
# or manually:
gcc src/*.c -Iinclude -o mips_sim
```


## Example Output

```
PC: 0x00000000 | Instruction: add $t0, $t1, $t2
ALU Result: 0x00000005
Registers updated: $t0 = 5

PC: 0x00000004 | Instruction: sw $t0, 0($sp)
Memory[0xFF] <- 5
```

---

## Control Signals Reference

| Signal      | R-Type | `lw` | `sw` | `beq` |
|-------------|--------|------|------|-------|
| RegDst      | 1      | 0    | X    | X     |
| ALUSrc      | 0      | 1    | 1    | 0     |
| MemToReg    | 0      | 1    | X    | X     |
| RegWrite    | 1      | 1    | 0    | 0     |
| MemRead     | 0      | 1    | 0    | 0     |
| MemWrite    | 0      | 0    | 1    | 0     |
| Branch      | 0      | 0    | 0    | 1     |

---

## Author

**Anas Radwan**
- GitHub: [@1anasradwan1](https://github.com/1anasradwan1)

---

## License

This project is licensed under the MIT License.
