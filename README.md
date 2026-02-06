# syslat - System Call Tracer

A simple eBPF-based system call tracer for Linux.

## What it does
Traces all system calls (or filter by PID) and prints them to the kernel trace pipe.

## Requirements
- Linux kernel with eBPF support (5.x+)
- clang
- libbpf-dev
- bpftool

## Build
```bash
make
```

## Run
```bash
sudo ./loader
```

Then in another terminal:
```bash
sudo cat /sys/kernel/debug/tracing/trace_pipe
```

## Filter by PID
Edit `src/syslat.bpf.c` and change:
```c
const pid_t pid_filter = 0;  // Set to specific PID to filter
```

## How it works
Uses eBPF to attach to the `raw_syscalls/sys_enter` tracepoint and logs every syscall with PID and syscall number.

## License
Dual BSD/GPL
