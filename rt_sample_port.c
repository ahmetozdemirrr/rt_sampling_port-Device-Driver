#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ahmet.ozdemir");
MODULE_DESCRIPTION("ARINC 653 Deterministic Sampling Port Driver");
MODULE_VERSION("1.0");

/* module load function */
static int __init rt_sample_port_init(void)
{
    pr_info("rt_sample_port: module is loading. Memory pool initialization\n");
    return 0; /* Başarılı */
}

/* module remove function */
static void __exit rt_sample_port_exit(void)
{
    pr_info("rt_sample_port: module is removing from system. Resources are being reclaimed.\n");
}

module_init(rt_sample_port_init);
module_exit(rt_sample_port_exit);
