# Library-Management

A **C++20** repository showcasing **Object-Oriented Programming (OOP)** and an **MVC (Model–View–Controller)** architecture applied to a library management system.

## Overview

**Library-Management** implements (or serves as a base to implement) common library workflows: managing books and typical operations such as creating/removing records, searching, listing, and/or handling loans—while keeping responsibilities separated using an MVC design.

## Tech Stack

- **C++20** (main)
- **CMake** (build configuration)

## Architecture (MVC)

- **Model**: domain logic and entities (e.g., `Book`, `Member/User`, `Loan`, etc.), and persistence if applicable.
- **View**: user interaction layer (e.g., console/CLI), responsible for menus, lists, and messages.
- **Controller**: coordinates actions between view and model (validates input, executes use cases, calls model services).

> Note: Folder/file names may differ depending on how the repository is organized.

## Requirements

- A compiler with **C++20** support:
  - GCC 10+ / Clang 12+ / MSVC with C++20 enabled
- **CMake** 3.16+ (recommended)

## Build (CMake)

From the project root:

```bash
cmake -S . -B build
cmake --build build
```

## Run

The produced executable name may vary. Example:

```bash
./build/Library-Management
```

On Windows (depending on generator/config):

```powershell
.\build\Debug\Library-Management.exe
```

## Usage

If the project provides a console interface, you’ll typically find options such as:

- Add / remove / edit books
- Search books (by title/author/ISBN)
- List the catalog
- Manage members/users
- Register loans and returns

## Suggested Structure (reference)

A common MVC-oriented layout might look like:

- `src/`
  - `model/`
  - `view/`
  - `controller/`
- `include/`
- `tests/` (if applicable)
- `CMakeLists.txt`

## Contributing

1. Fork the repository
2. Create a branch: `git checkout -b feature/my-change`
3. Commit: `git commit -m "Describe your change"`
4. Push: `git push origin feature/my-change`
5. Open a Pull Request

## License

Add your preferred license (e.g., MIT, Apache-2.0, GPL-3.0).  
If not defined yet, include a `LICENSE` file at the repository root.
