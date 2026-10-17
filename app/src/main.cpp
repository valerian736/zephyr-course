#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);
// static const struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET(DT_ALIAS(led0),
// gpios);

int main(void) {
    if (!gpio_is_ready_dt(&led)) return 0;
    gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    while (1) {
        gpio_pin_toggle_dt(&led);
        k_msleep(CONFIG_APP_HEARTBEAT_PERIOD_MS);
    }
}