
int main()
{
	double alc;
	printf("혈중 알코올 농도를 입력하시오(%%): ");
	scanf("%lf", &alc);
	if (0 <= alc && alc <= 0.049)
	{
		printf("훈방조치\n");
	}
	else if (0.05 <= alc && alc <= 0.099)
	{
		printf("면허 정지, 벌금 100만원\n");
	}
	else if (0.1 <= alc && alc <= 0.19)
	{
		printf("면허 취소, 벌금 300만원\n");
	}
	else if (0.2 <= alc)
	{
		printf("면허 취소, 구속\n");
	}
	else
	{
		printf("잘못된 값을 입력하였습니다.\n");
	}

	return 0;
}
