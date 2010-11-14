 902 static void
 903 enqueue_task_rt(struct rq *rq, struct task_struct *p,
 904					 int wakeup, bool head)
 904 {
 		....
 912         if (!task_current(rq, p) && p->rt.nr_cpus_allowed > 1)
 913                 enqueue_pushable_task(rq, p);   
 914 }
