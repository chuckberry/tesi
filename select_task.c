2344 static inline
2345 int select_task_rq(struct task_struct *p, int sd_flags, 
2346						int wake_flags)
2347 {
2348         int cpu = p->sched_class->select_task_rq(p, sd_flags, 
2349						wake_flags);
2350 
		.....
2359         if (unlikely(!cpumask_test_cpu(cpu, &p->cpus_allowed) ||
2360                      !cpu_online(cpu)))
2361                 cpu = select_fallback_rq(task_cpu(p), p);
2362 
2363         return cpu;
2364 }
