# RegexWhich
 `which` to accept regex

A fine replacement for `which`

```bash
alias which=/path/to/rwhich  # to .bashrc/.zshrc
```

## Usage
```bash
$ rwhich <name>
```

Examples:
```bash
$ rwhich 'python.*'
"/usr/bin/python" symlink to "python3" [application/x-pie-executable]
"/usr/bin/python-config" symlink to "python3-config" [text/x-shellscript]
"/usr/bin/python3" symlink to "python3.11" [application/x-pie-executable]
"/usr/bin/python3-config" symlink to "python3.11-config" [text/x-shellscript]
"/usr/bin/python3.11" [application/x-pie-executable]
"/usr/bin/python3.11-config" [text/x-shellscript]
```

```bash
$ ./bin/rwhich '.*java.*'
"/usr/bin/java2html" [text/x-shellscript]
"/usr/bin/archlinux-java" [text/x-shellscript]
"/usr/bin/java" symlink to "/usr/lib/jvm/default-runtime/bin/java" [application/x-pie-executable]
"/usr/bin/javac" symlink to "/usr/lib/jvm/default/bin/javac" [application/x-pie-executable]
"/usr/bin/javadoc" symlink to "/usr/lib/jvm/default/bin/javadoc" [application/x-pie-executable]
"/usr/bin/javap" symlink to "/usr/lib/jvm/default/bin/javap" [application/x-pie-executable]
"/usr/lib/jvm/default/bin/java" [application/x-pie-executable]
"/usr/lib/jvm/default/bin/javac" [application/x-pie-executable]
"/usr/lib/jvm/default/bin/javadoc" [application/x-pie-executable]
"/usr/lib/jvm/default/bin/javap" [application/x-pie-executable]
```

## Building

You need `libmagic`, `g++` and `make`

Ubuntu
```bash
$ apt-get update
$ apt-get install file build-essential
```

Arch linux
```bash
$ pacman -Sy file base-devel
```

After installation

```bash
$ mkdir bin
$ make debug # -Og build
$ make release # -O2 build
```