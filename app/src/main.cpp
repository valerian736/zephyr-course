#include <stdio.h>
#include <zephyr/init.h>
#include <zephyr/kernel.h>

static int board_init_msg(void) {
    printf("Board Initialized\n");
    return 0;
}

SYS_INIT(board_init_msg, APPLICATION, 0);

int main(void) {
    printf("Hello World! %s\n", CONFIG_BOARD_TARGET);
    return 0;
}