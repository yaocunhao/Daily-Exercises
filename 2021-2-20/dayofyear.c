//给你一个按 YYYY - MM - DD 格式表示日期的字符串 date，请你计算并返回该日期是当年的第几天。



//注意闰年

int year_flag(int year){
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		return 1;
	}
	else{
		return 0;
	}
}

int dayOfYear(char * date){
	int year = ((int)date[0] - 48) * 1000 + ((int)date[1] - 48) * 100 + ((int)date[2] - 48) * 10 + ((int)date[3] - 48);
	int mon = ((int)date[5] - 48) * 10 + ((int)date[6] - 48);
	int day = ((int)date[8] - 48) * 10 + ((int)date[9] - 48);
	int num_day = 0;
	int mon_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	mon_day[1] = year_flag(year) ? 29 : 28;
	int i = 0;
	for (i; i<mon - 1; i++){
		num_day += mon_day[i];
	}
	return num_day + day;
}
