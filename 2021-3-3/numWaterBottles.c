//С�����������ڴ������� numExchange ���վ�ƿ���Զһ�һƿ�¾ơ��㹺���� numBottles ƿ�ơ�
//
//����ȵ��˾�ƿ�еľƣ���ô��ƿ�ͻ��ɿյġ�
//
//������� ��� �ܺȵ�����ƿ�ơ�


int numWaterBottles(int numBottles, int numExchange){
	int ret = numBottles;
	int empty = numBottles;//��ƿ����

	while (empty >= numExchange)//��ƿ�Ӵ��ڿ��Զһ��Ϳ��Լ�����
	{
		ret += 1;
		empty = empty - numExchange + 1;
	}
	return ret;

}

