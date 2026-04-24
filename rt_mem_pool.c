#include <linux/types.h>
#include <linux/slab.h>    /* kmalloc_array */
#include <linux/vmalloc.h> /* vzalloc       */
#include <rt_mem_pool.h>
#include <common.h>


int rt_mem_pool_init(struct rt_mem_pool* pool, size_t pool_size)
{
    size_t i;
    return_code_t return_code = ERR_NOT_INITIALIZED;

    pool->blocks = kmalloc_array(pool_size,
                                 sizeof(struct rt_port_message),
                                 GFP_KERNEL);

    if (!pool->blocks)
    {
        return -ENOMEM;
    }

    INIT_LIST_HEAD(&pool->free_list);
    spin_lock_init(&pool->lock);

    /* mesjların şuan içi garbage olsa da rt_port_message içindeki list_head structlarını birbirlerine zincirlemek için bunu yapıyoruz */
    for (i = 0; i < pool_size; i++)
    {
        list_add(&pool->blocks[i].list, &pool->free_list);
    }

    pool->free_count = pool_size;

    return_code = ERR_NO_ERROR;

    return return_code;
}


void rt_mem_pool_destroy(struct rt_mem_pool* pool)
{
    kfree(pool->blocks);

    pool->blocks     = NULL;
    pool->free_count = 0;
}


struct rt_port_message* rt_mem_pool_get(struct rt_mem_pool* pool)
{

}


void rt_mem_pool_put(struct rt_mem_pool* pool, struct rt_port_message* msg)
{

}
