1173 static void check_preempt_curr_rt(struct rq *rq, struct task_struct *p, int flags)
1174 {
1175         if (p->prio < rq->curr->prio) {
1176                 resched_task(rq->curr);
1177                 return;
1178         }
1179		..... 
1196 }
