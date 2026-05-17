#include <linux/types.h>
#include <linux/list.h>
#include <linux/spinlock.h>
#include <linux/ktime.h>
#include <linux/rcupdate.h>

#define RT_MAX_MSG_SIZE 256
#define RT_POOL_SIZE 128


struct rt_port_message 
{
    struct list_head    list;
    struct rcu_head     rcu;
    ktime_t             timestamp;
    size_t              length;
    char                payload[RT_MAX_MSG_SIZE];
};

struct rt_mem_pool 
{
    struct list_head        free_list;
    spinlock_t              lock;
    size_t                  free_count;
    struct rt_port_message* blocks;
};


int rt_mem_pool_init(struct rt_mem_pool* pool, size_t pool_size);
void rt_mem_pool_destroy(struct rt_mem_pool* pool);
struct rt_port_message* rt_mem_pool_get(struct rt_mem_pool* pool);
void rt_mem_pool_put(struct rt_mem_pool* pool, struct rt_port_message* msg);
