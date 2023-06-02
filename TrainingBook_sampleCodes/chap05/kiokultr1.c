/* �P���L���g���[�j���O�i�p���L���E���̂P�j*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAGE	10				/* �X�e�[�W�� */
#define LEVEL_MIN	 3				/* �ŏ����x���i�������j*/
#define LEVEL_MAX	20				/* �ő僌�x���i�������j*/

/*--- x�~���b�o�߂���̂�҂� ---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	/* �G���[ */
			return (0);
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x); 
	return (1);
}

int main(void)
{
	int 	i, stage;
	int 	level;						/* ���x���i���l�̌����j*/
	int 	success = 0;				/* ���� */
	clock_t	start, end;					/* �J�n�����E�I������ */
	char	ltr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";	/* �p�啶�� */

	srand(time(NULL));					/* �����̎�������� */

	printf("�p���L���g���[�j���O\n");

	do {
		printf("���킷�郌�x���i%d�`%d�j�F", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	printf("%d�̉p�����L�����܂��傤�B\n", level);

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		char mstr[LEVEL_MAX + 1];			/* �L�����ׂ��p���̕��� */
		char x[LEVEL_MAX * 2];				/* �ǂݍ��񂾉p���̕��� */

		for (i = 0; i < level; i++)			/* ���̕�������쐬 */
			mstr[i] = ltr[rand() % strlen(ltr)];
		mstr[level] = '\0';

		printf("%s", mstr);
		fflush(stdout);
		sleep(125 * level);					/* ���񎦂�125�~level�~���b */

		printf("\r%*s\r���͂���F", level, "");
		scanf("%s", x);

		if (strcmp(x, mstr) != 0)
			printf("\a�ԈႢ�ł��B\n");
		else {
			printf("�����ł��B\n");
			success++;
		}
	}
	end = clock();

	printf("%d��%d�񐬌����܂����B\n", MAX_STAGE, success);
	printf("%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);

	return (0);
}