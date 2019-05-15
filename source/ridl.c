#include <vuln/ridl.h>
#include <stdio.h>

void show_ridl_tab(struct ridl_info *info)
{
    printf("Micro-architectural Data Sampling:\n");
    printf("--------------------------------------:\n");
    printf("Line Fill Buffers (MFBDS): %s\n", (info->mfbds ? "Vulnerable" : "Not Affected"));
    printf("Store Buffers (MSBDS): %s\n", (info->msbds ? "Vulnerable" : "Not Affected"));
    printf("Load Ports (MLPDS): %s\n", (info->mlpds ? "Vulnerable" : "Not Affected"));
    printf("Uncached Memory (MDSUM): %s\n", (info->mdsum ? "Vulnerable" : "Not Affected"));
    printf("SMT: ");
    if ((info->mfbds || info->msbds || info->mlpds) && info->smt_vuln) {
        printf("Vulnerable"); // , style->red);
    }
    else {
        printf("Unaffected"); // (info->mfbds || info->msbds || info->mlpds) ? style->green : style->black);
    }
    printf("\n");
    printf("MD_CLEAR: ");
    if (info->mfbds || info->msbds || info->mlpds) {
        if (info->md_clear) {
            printf("Available"); // , style->green);
        }
        else {
            printf("Not Available"); // , style->red);
        }
    }
    else {
        printf("Not Required"); // , style->green);
    }
    printf("\n");
    printf("\n");
}
