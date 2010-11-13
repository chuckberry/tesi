2497 #ifdef CONFIG_SMP
2498         if (p->sched_class->task_woken)
2499                 p->sched_class->task_woken(rq, p);
2500 
		....
2511 #endif
2512 out:
2513         task_rq_unlock(rq, &flags);
2514         put_cpu(); /* enable kernel preemption */
2515 
2516         return success;
2517 }
