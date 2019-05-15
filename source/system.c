#include <stdlib.h>
#include <stdio.h>

#include <info/cpuid.h>
#include <info/memory.h>
#include <info/microcode.h>
#include <info/os.h>

#include "system.h"

int
query_sys_info(struct sys_info *info)
{
	info->cpu_name = cpuid_get_brand_string();
	info->os_name = get_os_name();
	info->microcode = get_microcode();
	info->memory = get_memory_size(0, 2);

	return 0;
}

void show_system_tab(struct sys_info *info)
{
    printf("System:\n");
    printf("--------------------------------------:\n");
    printf("Operating system: %s\n", info->os_name);
    printf("Processor: %s\n", info->cpu_name);
    printf("Microarchitecture: %s\n", cpuid_get_codename());
    printf("Microcode: %s\n", info->microcode);
    printf("Memory: %s\n", info->memory);
    printf("\n");
}
