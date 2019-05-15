#include <vuln/spectre.h>
#include <stdio.h>

void show_spectre_v1_tab(struct spectre_info *info)
{
    printf("Direct Branch Speculation:\n");
    printf("--------------------------------------:\n");
    printf("Status: %s\n", (info->v1_affected ? "Vulnerable" : "Not Affected"));
    printf("__user pointer sanitization?: %s\n", (info->uptr_san ? "Enabled" : "Disabled"));
    printf("\n");
}

void show_spectre_v2_tab(struct spectre_info *info)
{
    printf("Indirect Branch Speculation:\n");
    printf("--------------------------------------:\n");
    printf("Status: %s\n", (info->v2_affected ? "Vulnerable" : "Not Affected"));
    printf("Retpoline: ");
    switch (info->retpol) {
    case RETPOL_ASM: printf("Assembly"); break; //style->green
    case RETPOL_FULL: printf("Full"); break; //style->green
    default: printf("Disabled"); break; //, info->v2_affected ? style->red : style->black); break;
    }
    printf("\n");
    printf("IBPB: ");
    switch (info->ibpb) {
    case IBPB_ALWAYS: printf("Always"); break; //style->green
    case IBPB_COND: printf("Conditional"); break; //style->green
    case IBPB_PRESENT: printf("Disabled"); break; //, info->v2_affected ? style->red : style->black); break;
    default: printf("Not Available"); break; //style->black
    }
    printf("\n");
    printf("IBRS: ");
    switch (info->ibrs) {
    case IBRS_ENABLED: printf("Enabled"); break; //style->green
    case IBRS_PRESENT: printf("Disabled"); break; //, info->v2_affected ? style->red : style->black); break;
    default: printf("Not Available"); break; //style->black
    }
    printf("\n");
    printf("STIBP: ");
    // TODO: only useful if SMT is actually present. 
    switch (info->stibp) {
    case STIBP_ENABLED: printf("Enabled"); break; //style->green
    case STIBP_PRESENT: printf("Disabled"); break; //, info->v2_affected ? style->red : style->black); break;
    default: printf("Not Available"); break; //style->black
    }
    printf("\n");
    printf("SMEP: ");
    switch (info->smep) {
    case SMEP_ENABLED: printf("Enabled"); break; //style->green
    case SMEP_PRESENT: printf("Disabled"); break; //, info->v2_affected ? style->red : style->black); break;
    default: printf("Not Available"); break; //style->black
    }
    printf("\n");
    printf("\n");
}
