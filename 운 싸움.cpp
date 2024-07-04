#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerHealth = 200;// �ڽ��� �ʱ� ü�� ����
	 
    int enemyHealth;
    int ch, damage, heal;
    int enemiesDefeated;
    srand(time(NULL)); // ���� �õ� ����

    printf("�λ� �ѹ� ����\n");
    printf("   0 |      | 0    \n");
    printf("  /|\\+      +/|\\   \n");
    printf("  / \\        / \\   \n");

    while (playerHealth > 0) {
        enemyHealth = 200; // ���� �ʱ� ü�� ����

        while (enemyHealth > 0) {
            printf("\n����� ���Դϴ�.\n");
            printf("1. ������ ���� (1d100 ������)\n");
            printf("2. ȸ�� (1d200 ȸ��)\n");
            printf("�����̳� ȸ���� �Ұ�: ");
            scanf("%d", &ch);

            if (ch == 1) {
                damage = (rand() % 100) + 1; // 1~100 ������ ���� ������
                enemyHealth -= damage;
                printf("����� ������ %d�� �������� �������ϴ�. (���� ü��: %d)\n", damage, enemyHealth);
            } else if (ch == 2) {
                heal = (rand() % 150) + 1; // 1~150 ������ ���� ȸ��
                playerHealth += heal;
                if (playerHealth > 500) {
                    playerHealth = 500; // �ִ� ü�� 500���� ����
                }
                printf("����� %d��ŭ ȸ���߽��ϴ�. (����� ü��: %d)\n", heal, playerHealth);
            } else {
                printf("�߸��� �����̴�\n");
                continue;
            }

            if (enemyHealth <= 0) {
                printf("���� �׿���\n");
                enemiesDefeated++;
                break;
            }

            printf("\n���� ���Դϴ�.\n");
            if (rand() % 2 == 0) {
                // ���� ����
                damage = (rand() % 100) + 1; // 1~100 ������ ���� ������
                playerHealth -= damage;
                printf("���� ��ſ��� %d�� �������� �������ϴ�. (����� ü��: %d)\n", damage, playerHealth);
            } else {
                // ���� ȸ��
                heal = (rand() % 100) + 1; // 1~100 ȸ�� 
                enemyHealth += heal;
                if (enemyHealth > 500) {
                    enemyHealth = 500; // ���� ü���� 500���� ����
                }
                printf("���� %d��ŭ ȸ���߽��ϴ�. (���� ü��: %d)\n", heal, enemyHealth);
            }

            if (playerHealth <= 0) {
                printf("�й�\n");
                printf("����� ���� ���� ��: %d\n", enemiesDefeated);
                break;
            }
        }
    }

    return 0;
}

