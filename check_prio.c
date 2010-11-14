1173 static void check_preempt_curr_rt(struct rq *rq, 
1174			struct task_struct *p, int flags)
1175 {
1176         if (p->prio < rq->curr->prio) {
1177                 resched_task(rq->curr);
1178                 return;
1179         }
		..... 
1196 }
