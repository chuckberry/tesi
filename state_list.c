 183 #define TASK_RUNNING            0
 184 #define TASK_INTERRUPTIBLE      1
 185 #define TASK_UNINTERRUPTIBLE    2
 186 #define __TASK_STOPPED          4
 187 #define __TASK_TRACED           8
 188 /* in tsk->exit_state */
 189 #define EXIT_ZOMBIE             16
 190 #define EXIT_DEAD               32
 191 /* in tsk->state again */
 192 #define TASK_DEAD               64
 193 #define TASK_WAKEKILL           128
 194 #define TASK_WAKING             256
 195 #define TASK_STATE_MAX          512
