2344 static inline
2345 int select_task_rq(struct task_struct *p, int sd_flags, int wake_flags)
2346 {
2347         int cpu = p->sched_class->select_task_rq(p, sd_flags, wake_flags);
2348 
		.....
2359         if (unlikely(!cpumask_test_cpu(cpu, &p->cpus_allowed) ||
2360                      !cpu_online(cpu)))
2361                 cpu = select_fallback_rq(task_cpu(p), p);
2362 
2363         return cpu;
2364 }
