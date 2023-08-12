# RegexWhich
 `which` to accept regex

A file replacement for `which`

## Usage
```bash
$ rwhich 'python.*'
"/usr/bin/python" symlink to "python3" [application/x-pie-executable]
"/usr/bin/python-config" symlink to "python3-config" [text/x-shellscript]
"/usr/bin/python3" symlink to "python3.11" [application/x-pie-executable]
"/usr/bin/python3-config" symlink to "python3.11-config" [text/x-shellscript]
"/usr/bin/python3.11" [application/x-pie-executable]
"/usr/bin/python3.11-config" [text/x-shellscript]
```

## Building

You need `libmagic`, `gcc`, `make`
Ubuntu
```bash
apt-get update
apt-get install file build-essential
```

Arch linux
```bash
pacman -Sy file base-devel
```

After installations

```bash
$ mkdir bin
$ make debug # -Og build
$ make release # -O2 build
```