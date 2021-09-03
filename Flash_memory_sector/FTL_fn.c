 #include "Flash_Block_memory.h"

void f_read(int num) {											//ftl_read
	loot = num % S_SIZE;										//LSN - PSN ��ġ ���� ����
	read(*(table + loot));
	printf("PSN : %d\n", *(table + loot));
}
void f_write(int num, char data[]) {							//ftl_write
	loot = num % S_SIZE;
	write(*(table + loot), data);
	printf("PSN : %d\n", *(table + loot));
}
void printf_table(int num) {								
	for (int i = 0; i < num * B_OF_MB; i++) {							//���̺� ���
		printf("LSN : %d  PSN : %d\n", i,*(table + i));
	}
}
void set_table(int num) {										//���̺� ����
	FILE* fp;
	fopen_s(&fp, "table.txt", "r");								//���� ���̺� ���� Ȯ��
	table = (int*)malloc(sizeof(int) * B_OF_MB * num);			//�� ��ϼ���ŭ ���̺��� �����Ѵ�.
	if (table == NULL) {
		printf("�޸� �Ҵ� ����!");							//�޸� �Ҵ� Ȯ��
		return;
	}
	if(fp != NULL) {											//���� ���̺� ������ �ҷ�����
		int i = 0;
		while (!feof(fp))
		{
			fgets(num_buffer, sizeof(num_buffer), fp);
			*(table+i) = atoi(num_buffer);
			i++;
		}
		
		fclose(fp);
	}
	else {
		for (int i = 0; i < (B_OF_MB * num); i++) {	//�ʱ� ���̺� �ʱ�ȭ
			*(table + i) = i;
		}
	}
}