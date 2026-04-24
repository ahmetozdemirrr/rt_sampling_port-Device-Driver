#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Developer");
MODULE_DESCRIPTION("ARINC 653 Deterministic Sampling Port Driver");
MODULE_VERSION("1.0");

/* Modül load Fonksiyonu */
static int __init rt_sample_port_init(void)
{
    pr_info("rt_sample_port: Modül yükleniyor. Bellek havuzu ilklendirilecek.\n");
    return 0; /* Başarılı */
}

/* Modül remove Fonksiyonu */
static void __exit rt_sample_port_exit(void)
{
    pr_info("rt_sample_port: Modül sistemden kaldırılıyor. Kaynaklar iade ediliyor.\n");
}

module_init(rt_sample_port_init);
module_exit(rt_sample_port_exit);