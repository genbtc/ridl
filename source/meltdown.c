#include <vuln/meltdown.h>
#include <stdio.h>

void show_meltdown_tab(struct meltdown_info *info)
{
    printf("Meltdown Status:\n");
    printf("--------------------------------------:\n");
    printf("Affected?: %s\n", (info->affected ? "Vulnerable" : "Not Affected"));
    printf("KPTI Present?: %s\n", (info->kpti_present ? "Yes" : "No"));
    printf("KPTI Enabled?: %s\n", (info->kpti_enabled ? "Yes" : "No"));
    printf("PCID Accelerated?: %s\n", (info->has_pcid ? "Yes" : "No"));
    printf("PCID Invalidation?: %s\n", (info->has_invpcid ? "Yes" : "No"));
    printf("\n");
}
