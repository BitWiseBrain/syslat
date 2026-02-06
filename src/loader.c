#include <stdio.h>
#include <unistd.h>
#include <bpf/libbpf.h>

int main() {
    struct bpf_object *obj;
    struct bpf_program *prog;
    struct bpf_link *link;
    
    obj = bpf_object__open_file("syslat.o", NULL);
    if (!obj) {
        fprintf(stderr, "Failed to open BPF object\n");
        return 1;
    }
    
    if (bpf_object__load(obj)) {
        fprintf(stderr, "Failed to load BPF object\n");
        return 1;
    }
    
    prog = bpf_object__find_program_by_name(obj, "handle_sys_enter");
    if (!prog) {
        fprintf(stderr, "Failed to find program\n");
        return 1;
    }
    
    link = bpf_program__attach(prog);
    if (!link) {
        fprintf(stderr, "Failed to attach\n");
        return 1;
    }
    
    printf("BPF program attached! Check trace_pipe now.\n");
    printf("Press Ctrl+C to exit...\n");
    
    while (1) {
        sleep(1);
    }
    
    return 0;
}
