#include <vuln/spectre.h>
#include <vuln/ssb.h>
#include <stdio.h>

void show_ssb_tab(struct ssb_info *info)
{

    printf("Speculative Store Bypass:\n");
    printf("--------------------------------------:\n");
    printf("Speculative Store Bypass: %s\n", (info->affected ? "Vulnerable" : "Not Affected"));
	printf("Speculative Store Bypass Disable: ");
	
	if (info->affected) {
		switch (info->ssbd) {
        case SSBD_OS_SUPPORT: printf("OS Support"); break; //, style->green); break;
        case SSBD_PRESENT: printf("Available"); break; //, style->yellow); break;
        default: printf("Not Available"); break; //, style->red);
		}
	} else {
        printf("Not Required"); // , style->green);
	}
    printf("\n");
    printf("\n");
}
