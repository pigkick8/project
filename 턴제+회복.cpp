#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerHealth = 100;
    int enemyHealth = 100;
    int choice, damage, heal;
    srand(time(NULL)); // 랜덤 시드 설정

    printf("인생 한방 전투\n");
    printf("   0 |      | 0    \n");
    printf("  /|\\+      +/|\\   \n");
    printf("  / \\        / \\   \n");

    while (playerHealth > 0 && enemyHealth > 0) {
        printf("\n당신의 턴입니다.\n");
        printf("1. 강력한 공격 (1d100 데미지)\n");
        printf("2. 회복 (1d200 회복)\n");
        printf("공격 또는 회복을 선택하세요: ");
        scanf("%d", &choice);

        if (choice == 1) {
            damage = (rand() % 100) + 1; // 1~100 사이의 랜덤 데미지
            enemyHealth -= damage;
            printf("당신이 적에게 %d의 데미지를 입혔습니다. (적의 체력: %d)\n", damage, enemyHealth);
        } else if (choice == 2) {
            heal = (rand() % 200) + 1; // 1~200 사이의 랜덤 회복
            playerHealth += heal;
            printf("당신이 %d만큼 회복했습니다. (당신의 체력: %d)\n", heal, playerHealth);
        } else {
            printf("잘못된 선택입니다. 다시 선택해주세요.\n");
            continue;
        }

        if (enemyHealth <= 0) {
            printf("운이 좋으시군요! 적을 물리쳤습니다!\n");
            break;
        }

        printf("\n적의 턴입니다.\n");
        if (rand() % 2 == 0) {
            // 적의 공격
            damage = (rand() % 100) + 1; // 1~100 사이의 랜덤 데미지
            playerHealth -= damage;
            printf("적이 당신에게 %d의 데미지를 입혔습니다. (당신의 체력: %d)\n", damage, playerHealth);
        } else {
            // 적의 회복
            heal = (rand() % 200) + 1; // 1~200 사이의 랜덤 회복
            enemyHealth += heal;
            printf("적이 %d만큼 회복했습니다. (적의 체력: %d)\n", heal, enemyHealth);
        }

        if (playerHealth <= 0) {
            printf("SKILL ISSUE. 당신은 패배했습니다.\n");
            break;
        }
    }

    return 0;
}

