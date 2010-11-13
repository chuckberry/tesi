2434         rq = cpu_rq(cpu);
2435         raw_spin_lock(&rq->lock);
2436         update_rq_clock(rq);
2437 
		....
2447 #ifdef CONFIG_SCHEDSTATS
2448         schedstat_inc(rq, ttwu_count);
2449         if (cpu == this_cpu)
2450                 schedstat_inc(rq, ttwu_local);
		....
2460 #endif /* CONFIG_SCHEDSTATS */
2473         activate_task(rq, p, 1);
2474         success = 1;
		.... 
2491 
2492 out_running:
2493         trace_sched_wakeup(rq, p, success);
2494         check_preempt_curr(rq, p, wake_flags);
2495 
2496         p->state = TASK_RUNNING;
