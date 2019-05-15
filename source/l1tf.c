#include <vuln/l1tf.h>
#include <stdio.h>

void show_l1tf_tab(struct l1tf_info *info)
{
    printf("L1 Terminal Fault Status:\n");
    printf("--------------------------------------:\n");
    printf("Affected?: %s\n", (info->affected ? "Vulnerable" : "Not Affected"));
    printf("L1TF Present?: %s\n", (info->l1tf_present ? "Yes" : "No"));
    printf("PTE Inversion?: %s\n", (info->pte_inv ? "Yes" : "No"));
    printf("SMT?: %s\n", (info->smt_vuln ? "Vulnerable" : "Unaffected"));
    printf("L1d Flush Present?: ");
    switch (info->l1d_flush) {
    case L1D_FLUSH_ALWAYS: printf("%s", "Always"); break; //, style->green
    case L1D_FLUSH_COND: printf("%s", "Conditional"); break; //, style->green
    case L1D_FLUSH_AVAIL: printf("%s", "Available"); break; //, style->yellow
    default: printf("%s", "Never"); break; //, info->affected ? style->red : style->black
    }
    printf("\n");
    printf("\n");
}
