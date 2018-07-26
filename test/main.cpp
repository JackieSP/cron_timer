// CronTimerTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "cron_timer_mgr.h"

void on_1_second_timer()
{
	printf("1 second timer hit\n");
}

void on_3_second_timer()
{
	printf("3 second timer hit\n");
}

int main()
{
	CronTimer::TimerMgr g_timer_mgr;
	g_timer_mgr.Start();
	g_timer_mgr.AddTimer("* * * * * * *", on_1_second_timer);
	g_timer_mgr.AddTimer("*0/3 * * * * * *", on_3_second_timer);

	while (true)
	{
		g_timer_mgr.Update();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	g_timer_mgr.Stop();
    return 0;
}

