#
# Regular cron jobs for the englishnum package
#
0 4	* * *	root	[ -x /usr/bin/englishnum_maintenance ] && /usr/bin/englishnum_maintenance
