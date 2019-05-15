#include <stdio.h>

#include <vuln/l1tf.h>
#include <vuln/meltdown.h>
#include <vuln/ridl.h>
#include <vuln/spectre.h>

#include "system.h"

void show_meltdown_tab(struct meltdown_info *info);
void show_l1tf_tab(struct l1tf_info *info);
void show_spectre_v1_tab(struct spectre_info *info);
void show_spectre_v2_tab(struct spectre_info *info);
void show_ridl_tab(struct ridl_info *info);

int main(void)
{
    //Console version:
	struct sys_info sys_info;
	struct spectre_info spectre_info;
	struct meltdown_info meltdown_info;
	struct l1tf_info l1tf_info;
	struct ridl_info ridl_info;

	query_sys_info(&sys_info);
	query_spectre_info(&spectre_info);
	query_meltdown_info(&meltdown_info);
	query_l1tf_info(&l1tf_info);
	query_ridl_info(&ridl_info);

    show_system_tab(&sys_info);
    show_spectre_v1_tab(&spectre_info);
    show_spectre_v2_tab(&spectre_info);
    show_ssb_tab(&spectre_info); //this passes spectre_info to something expecting ssb_info, which I don't understand. BUG?
    show_meltdown_tab(&meltdown_info);
    show_l1tf_tab(&l1tf_info);
    show_ridl_tab(&ridl_info);
    
    #if defined(_WIN32)
        getch(); //dont insta-close (hit any key to close)
    #endif

	return 0;
}
