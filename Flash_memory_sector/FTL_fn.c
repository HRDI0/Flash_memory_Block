 #include "Flash_Block_memory.h"

void f_read(int num) {											//ftl_read
	loot = num % S_SIZE;										//LSN - PSN 위치 연산 변수
	read(*(table + loot));
	printf("PSN : %d\n", *(table + loot));
}
void f_write(int num, char data[]) {							//ftl_write
	loot = num % S_SIZE;
	write(*(table + loot), data);
	printf("PSN : %d\n", *(table + loot));
}
void printf_table(int num) {								
	for (int i = 0; i < num * B_OF_MB; i++) {							//테이블 출력
		printf("LSN : %d  PSN : %d\n", i,*(table + i));
	}
}
void set_table(int num) {										//테이블 생성
	FILE* fp;
	fopen_s(&fp, "table.txt", "r");								//기존 테이블 파일 확인
	table = (int*)malloc(sizeof(int) * B_OF_MB * num);			//총 블록수만큼 테이블을 생성한다.
	if (table == NULL) {
		printf("메모리 할당 실패!");							//메모리 할당 확인
		return;
	}
	if(fp != NULL) {											//기존 테이블 데이터 불러오기
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
		for (int i = 0; i < (B_OF_MB * num); i++) {	//초기 테이블 초기화
			*(table + i) = i;
		}
	}
}