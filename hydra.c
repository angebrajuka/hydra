#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char self[256];

void create_proc() {
    STARTUPINFO struct_startup_info;
    GetStartupInfo(&struct_startup_info);
    PROCESS_INFORMATION struct_proc_info;
    CreateProcess(NULL, self, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &struct_startup_info, &struct_proc_info);
    CreateProcess(NULL, self, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &struct_startup_info, &struct_proc_info);
}

int main(int argc, char **argv) {
    sprintf(self, "%s head", argv[0]);
    printf("hydra, cut off one head and two more shall take it's place...");
    atexit(create_proc);
    while(1) {}
    return 0;
}