/*
 * The 80-20 rule
 * 
 * Studies show that 80% of the bottlneck / memory / computation etc of a program is spent in 20% of that programs codebase
 * 
 * Therefore: Premature optimization of a program in any area other than that 20% is futile!
 *
 *
 * Summary:
 *      - Don't optimize any part of a program without first using a profiler to locate the 20% of your code where the performance is slow
 *      - Only then should you optimize that part only
 *
 */