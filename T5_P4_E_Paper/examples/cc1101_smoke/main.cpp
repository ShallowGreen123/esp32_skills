#include <Arduino.h>
#include "demo_log.h"
#include "demo_check.h"
#include "demo_config.h"
#include "demo_pins.h"

static const char *TAG = "cc1101_smoke";

static bool run_demo()
{
    DEMO_STEP("TODO: 补充演示步骤");
    DEMO_CHECK_TRUE(true, "placeholder");
    return true;
}

void setup()
{
    Serial.begin(DEMO_BAUDRATE);
    delay(DemoConfig::SERIAL_WAIT_MS);

    DEMO_BEGIN(TAG);
    if (run_demo()) {
        DEMO_PASS(TAG);
    } else {
        DEMO_FAIL(TAG);
    }
    DEMO_END(TAG);
}

void loop() {}
