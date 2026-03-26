# 🐚 Minishell

> My own shell — a 42 project.

---

## 📖 About

**Minishell** is a simple implementation of a UNIX command line interpreter written in C.  
Inspired by `bash`, it handles command execution, pipes, redirections, environment variables, and built-in commands — all from scratch.

---

## ⚙️ Installation

```bash
# Clone the repository
git clone https://github.com/AToufik01/minishell_42.git
cd minishell_42

# Build
make
```

---

## 🕹️ Usage

```bash
./minishell
```

Once running, you get an interactive prompt:

```bash
minishell$ ls -l | grep src
minishell$ echo "Hello, $USER"
minishell$ cat << EOF >> outfile | wc -l
minishell$ pwd
minishell$ exit
```

---

## ✅ Features

### Execution
- Display a **prompt** and wait for user input
- Execute commands with their arguments
- Search for commands using the **`PATH`** environment variable
- Handle **relative and absolute paths** (`ls`, `/bin/ls`)

### Quotes
- **Single quotes** `'` — no interpretation, literal string
- **Double quotes** `"` — allow `$` variable expansion inside

### Redirections
| Operator | Description |
|---|---|
| `>` | Redirect stdout to file (overwrite) |
| `>>` | Redirect stdout to file (append) |
| `<` | Redirect stdin from file |
| `<<` | Here-doc — read stdin until delimiter |

### Pipes
- `|` — chain commands, stdout of one becomes stdin of the next
- Multiple pipes supported: `cmd1 \| cmd2 \| cmd3`

### Environment Variables
- `$VAR` — expand environment variables in commands
- `$?` — expand to the exit status of the last command

### Signals
| Signal | Behavior |
|---|---|
| `Ctrl+C` | Display a new prompt |
| `Ctrl+D` | Exit the shell |
| `Ctrl+\` | Do nothing |

---

## 🔧 Built-in Commands

| Command | Description |
|---|---|
| `echo` | Print text to stdout (`-n` flag supported) |
| `cd` | Change current directory |
| `pwd` | Print current working directory |
| `export` | Set or add an environment variable |
| `unset` | Remove an environment variable |
| `env` | Print all environment variables |
| `exit` | Exit the shell with a status code |

---

## 💡 Examples

```bash
# Pipes
minishell$ ls | cat | ls -l > file

# Here-doc with append and pipes
minishell$ cat << aa >> file2 | cat << bb >> file2 | cat << cc >> file2

# Variable expansion
minishell$ export MYVAR=hello
minishell$ echo $MYVAR
hello

# Exit status
minishell$ ls nonexistent
minishell$ echo $?
1

# Quotes
minishell$ echo "Hello $USER"     # expands variable
minishell$ echo 'Hello $USER'     # literal, no expansion
```

---

## 🔑 Key Concepts

- **Parsing** — tokenizing input
- **Heredoc** — reading from stdin until a delimiter with `<<`
- **Pipes** — `pipe()`, `fork()`, `dup2()` to chain processes
- **Redirections** — `open()`, `dup2()` for `<`, `>`, `>>`, `<<`
- **Env management** — custom environment list with `export` / `unset`
- **Signal handling** — `sigaction()` for `SIGINT`, `SIGQUIT`, `SIGEOF`
- **Readline** — interactive prompt with command history

---

## 🧪 Testing

```bash
# Basic execution
minishell$ /bin/ls
minishell$ ls -la

# Pipe chain
minishell$ ls | grep .c | wc -l

# Redirections
minishell$ echo hello > out.txt
minishell$ cat < out.txt
minishell$ echo world >> out.txt

# Edge cases
minishell$ ""
minishell$ echo ''
minishell$ export =value      # should error
minishell$ cd                 # go to HOME
```

---

## 📋 Norme

This project follows the **42 Norm**:
- Max 25 lines per function
- Max 5 functions per file
- No `for`, `do...while`, `switch`
- No more than 5 variables per function

---

## 👤 Author

**AToufik01** — ataoufik@student.1337.ma && **hassanmagueri** — emagueri@student.1337.ma

---

*1337 School (42 NETWORK) — Minishell project*
