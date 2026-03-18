#pragma once
#include <Arduino.h>

#ifndef DEMO_BAUDRATE
#define DEMO_BAUDRATE 115200
#endif

#define DEMO_BEGIN(tag)      Serial.printf("[DEMO][BEGIN] %s\r\n", tag)
#define DEMO_END(tag)        Serial.printf("[DEMO][END] %s\r\n", tag)
#define DEMO_STEP(msg)       Serial.printf("[DEMO][STEP] %s\r\n", msg)
#define DEMO_INFO(fmt, ...)  Serial.printf("[DEMO][INFO] " fmt "\r\n", ##__VA_ARGS__)
#define DEMO_WARN(fmt, ...)  Serial.printf("[DEMO][WARN] " fmt "\r\n", ##__VA_ARGS__)
#define DEMO_ERROR(fmt, ...) Serial.printf("[DEMO][ERROR] " fmt "\r\n", ##__VA_ARGS__)
#define DEMO_PASS(tag)       Serial.printf("[DEMO][PASS] %s\r\n", tag)
#define DEMO_FAIL(tag)       Serial.printf("[DEMO][FAIL] %s\r\n", tag)
