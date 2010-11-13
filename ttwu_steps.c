2391         this_cpu = get_cpu();
2392 
2393         smp_wmb();
2394         rq = task_rq_lock(p, &flags);
2395         update_rq_clock(rq);
2396         if (!(p->state & state))
2397                 goto out;
2398 
2399         if (p->se.on_rq)
2400                 goto out_running;
2401 
2402         cpu = task_cpu(p);
2403         orig_cpu = cpu;
2404 
2405 #ifdef CONFIG_SMP
2406         if (unlikely(task_running(rq, p)))
2407                 goto out_activate;
2408 
2415         if (task_contributes_to_load(p))
2416                 rq->nr_uninterruptible--;
2417         p->state = TASK_WAKING;
2418 
2419         if (p->sched_class->task_waking)
2420                 p->sched_class->task_waking(rq, p);
2421 
2422         __task_rq_unlock(rq);
2423 
2424         cpu = select_task_rq(p, SD_BALANCE_WAKE, wake_flags);

