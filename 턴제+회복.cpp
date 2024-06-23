#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerHealth = 100;
    int enemyHealth = 100;
    int choice, damage, heal;
    srand(time(NULL)); // ���� �õ� ����

    printf("�λ� �ѹ� ����\n");
    printf("   0 |      | 0    \n");
    printf("  /|\\+      +/|\\   \n");
    printf("  / \\        / \\   \n");

    while (playerHealth > 0 && enemyHealth > 0) {
        printf("\n����� ���Դϴ�.\n");
        printf("1. ������ ���� (1d100 ������)\n");
        printf("2. ȸ�� (1d200 ȸ��)\n");
        printf("���� �Ǵ� ȸ���� �����ϼ���: ");
        scanf("%d", &choice);

        if (choice == 1) {
            damage = (rand() % 100) + 1; // 1~100 ������ ���� ������
            enemyHealth -= damage;
            printf("����� ������ %d�� �������� �������ϴ�. (���� ü��: %d)\n", damage, enemyHealth);
        } else if (choice == 2) {
            heal = (rand() % 200) + 1; // 1~200 ������ ���� ȸ��
            playerHealth += heal;
            printf("����� %d��ŭ ȸ���߽��ϴ�. (����� ü��: %d)\n", heal, playerHealth);
        } else {
            printf("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n");
            continue;
        }

        if (enemyHealth <= 0) {
            printf("���� �����ñ���! ���� �����ƽ��ϴ�!\n");
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
            heal = (rand() % 200) + 1; // 1~200 ������ ���� ȸ��
            enemyHealth += heal;
            printf("���� %d��ŭ ȸ���߽��ϴ�. (���� ü��: %d)\n", heal, enemyHealth);
        }

        if (playerHealth <= 0) {
            printf("SKILL ISSUE. ����� �й��߽��ϴ�.\n");
            break;
        }
    }

    return 0;
}

