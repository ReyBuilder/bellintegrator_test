# Hacking guide

### Requirements

- g++
- make
- libpoco-dev (poco-devel)
- gdb (for debug purposes)

### Build project

```
make
```

### Clean project

```
make clean
```

### App usage

```
./telnet 28888
```

### Testing

You can use a simple python script to interact with server

```
python3 test.py
```

### VSCode debug

There are VSCode debug configuration which launches telnet app on 28888 port.  
It requires debug symbols enabled (e.g. `CPPFLAGS += -g` in Makefile)