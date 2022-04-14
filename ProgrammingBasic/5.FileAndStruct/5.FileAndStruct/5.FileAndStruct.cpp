#include <stdio.h>
#include <string.h>
//구조체: 변수를 모아서 새로운 타입을 정의함.
struct Status //12
{
	int nHP;
	int nStr;
	int nDef;
};
//구조체의 메모리를 할당할때 크기가 4씩 할당되므로 크기를 잡을때 4의 배수를 이용해야한다.
//더 작은 메모리를 잡더라도 메모리에 빈공간이 생겨 사용량은 같다. EX) 9,10,11,12 -> 32
struct RPGPlayer //18
{
	char strName[12]; //12
	Status sStatus; //12
	int nExp; //4
	int nLv; //4
};
//지역변수를 초기화하고 리턴하여 변수에 값을 복사함.
RPGPlayer InitRPGPlayer(const char* name, int hp, int str, int def, int exp)
{
	RPGPlayer player;
	strcpy(player.strName, name);
	player.sStatus.nHP = hp;
	player.sStatus.nStr = str;
	player.sStatus.nDef = def;
	player.nLv = 1;
	player.nExp = exp;
	return player;
}
//원본에 접근하여 멤버를 직접 수정한다.
void InitRPGPlayerRef(RPGPlayer& player, const char* name, int hp, int str, int def, int exp)
{
	strcpy(player.strName, name);
	player.sStatus.nHP = hp;
	player.sStatus.nStr = str;
	player.sStatus.nDef = def;
	player.nLv = 1;
	player.nExp = exp;
}
void InitRPGPlayerPtr(RPGPlayer* pPlayer, const char* name, int hp, int str, int def, int exp)
{
	strcpy(pPlayer->strName, name);
	pPlayer->sStatus.nHP = hp;
	pPlayer->sStatus.nStr = str;
	pPlayer->sStatus.nDef = def;
	pPlayer->nLv = 1;
	pPlayer->nExp = exp;
}
void PrintRPGPlayer(RPGPlayer& player)
{
	printf("########### %s ##########\n", player.strName);
	printf("HP:%d\n", player.sStatus.nHP);
	printf("STR:%d\n", player.sStatus.nStr);
	printf("DEF:%d\n", player.sStatus.nDef);
	printf("Lv/Exp:%d/%d\n", player.nLv, player.nExp);
}
void RPGPlayerDataSaveText(RPGPlayer& player)
{
	FILE* pFile;
	char strFileName[1024];
	sprintf(strFileName, "%s.txt", player.strName);
	pFile = fopen(strFileName, "w+");

	if (pFile)
	{
		fprintf(pFile,"%s\n", player.strName);
		fprintf(pFile,"%d\n", player.sStatus.nHP);
		fprintf(pFile,"%d\n", player.sStatus.nStr);
		fprintf(pFile,"%d\n", player.sStatus.nDef);
		fprintf(pFile,"%d/%d\n", player.nLv, player.nExp);
		fclose(pFile);
	}
}
void RPGPlayerDataLoadText(RPGPlayer& player)
{
	FILE* pFile;
	char strFileName[1024];
	sprintf(strFileName, "%s.txt", player.strName);
	pFile = fopen(strFileName, "r+");

	if (pFile)
	{
		fscanf(pFile, "%s\n", player.strName);
		fscanf(pFile, "%d\n", &player.sStatus.nHP);
		fscanf(pFile, "%d\n", &player.sStatus.nStr);
		fscanf(pFile, "%d\n", &player.sStatus.nDef);
		fscanf(pFile, "%d/%d\n", &player.nLv, &player.nExp);
		fclose(pFile);
	}
}
void RPGPlayerDataSaveBinary(RPGPlayer& player)
{
	FILE* pFIle;
	char strFileName[1024];
	sprintf(strFileName, "%s.dat", player.strName);
	pFIle = fopen(strFileName, "wb");

	if (pFIle)
	{
		fwrite((void*)&player, sizeof(player), 1, pFIle);
		fclose(pFIle);
	}
}
void RPGPlayerDataLoadBinary(RPGPlayer& player)
{
	FILE* pFIle;
	char strFileName[1024];
	sprintf(strFileName, "%s.dat", player.strName);
	pFIle = fopen(strFileName, "rb");

	if (pFIle)
	{
		fread((void*)&player, sizeof(player), 1, pFIle);
		fclose(pFIle);
	}
}
void RPGDataSaveLoadTestMain()
{
	RPGPlayer sPlayer;
	//InitRPGPlayer(sPlayer, "Player", 100, 10, 5, 0);
	sPlayer = InitRPGPlayer("Player", 100, 10, 5, 0);
	InitRPGPlayerPtr(&sPlayer, "Player", 100, 10, 5, 0);
	printf("### Init ####\n");
	PrintRPGPlayer(sPlayer);
	printf("### Save ####\n");
	RPGPlayerDataSaveText(sPlayer);
	//RPGPlayerDataSaveBinary(sPlayer);
	printf("### Inc Def ####\n");
	sPlayer.sStatus.nDef += 10;
	PrintRPGPlayer(sPlayer);
	printf("### Load ####\n");
	//RPGPlayerDataLoadBinary(sPlayer);
	RPGPlayerDataLoadText(sPlayer);
	PrintRPGPlayer(sPlayer);
}
//텍스트파일: 사용자가 텍스트를 저장해 내용을 확인할수있는 파일.
void TextFileWriteMain()
{
	FILE* pOpenFile;
	pOpenFile = fopen("test.txt", "w+"); //파일열기 쓰기모드
	if (pOpenFile)
	{
		fprintf(pOpenFile, "Gamp14WriteFile");
		fprintf(pOpenFile, "Test");
		fclose(pOpenFile);
	}
}
void TextFileReadMain()
{
	FILE* pOpenFile;
	pOpenFile = fopen("test.txt", "r+"); //파일열기 읽기모드
	char filestream[1024];
	if (pOpenFile)
	{
		fscanf(pOpenFile, "%s", filestream);
		printf("file stream:%s\n", filestream);
		fclose(pOpenFile);
	}
}
void BinaryFileWriteMain()
{
	char strBuffer[1024] = "Gamp14TestBinaryFile";
	FILE* pOpenFile = fopen("test.dat", "wb");

	if (pOpenFile)
	{
		fwrite(strBuffer, sizeof(char), 1024, pOpenFile);
		fclose(pOpenFile);
	}
}
void BinaryFileReadMain()
{
	FILE* pOpenFile;
	pOpenFile = fopen("test.dat", "rb"); //파일열기 바이너리
	char filestream[1024];
	if (pOpenFile)
	{
		fread(filestream, sizeof(char), 1024, pOpenFile);
		printf("file stream:%s\n", filestream);
		fclose(pOpenFile);
	}
}
void StructSizeTestMain()
{
	printf("StatusSize:%d\n",sizeof(Status));
	printf("RPGPlayerSize:%d\n", sizeof(RPGPlayer));
}
void main()
{
	StructSizeTestMain();
	//TextFileWriteMain();
	//TextFileReadMain();
	//BinaryFileWriteMain();
	//BinaryFileReadMain();
	//RPGDataSaveLoadTestMain();
}