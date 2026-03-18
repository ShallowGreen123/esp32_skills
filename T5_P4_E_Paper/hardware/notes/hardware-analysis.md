# 硬件分析记录

## 1. 基本信息
- 模块名称：T-Embed-CC1101
- 本地原理图文件：[T-Embed-CC1101 V1.0 24-07-29.pdf](d:\dgx\code\esp32_skills_test\t-embed-cc1101\hardware\schematic\T-Embed-CC1101%20V1.0%2024-07-29.pdf)
- 本地原理图版本：V1.0，文件日期为 2024-07-29
- 官方仓库最新硬件版本：v1.0-241103
- 主控信息：
  - 官方 README：`ESP32-S3-WROOM-1`
  - 官方 Wiki：`ESP32-S3FN16R8`
  - 当前判断：大概率是基于 `ESP32-S3FN16R8` 的 `ESP32-S3-WROOM-1` 16MB Flash / 8MB PSRAM 版本
- 显示屏：ST7789，320x170
- Sub-GHz：CC1101
- NFC：PN532
- 电池：3.7V 1300mAh
- 电源相关芯片：BQ25896 / BQ27220

## 2. 本次分析目标
- 先建立可用于 PlatformIO + Arduino 演示开发的第一版板卡认识
- 先确认 CC1101、SPI、I2C、显示、NFC 的关键引脚
- 暂不把未从资料中确认的极性和时序写死到代码

## 3. 供电与电平
- 电池供电：3.7V 锂聚合物电池
- USB：Type-C
- MCU 逻辑电平：推定为 3.3V
- Flash / PSRAM：16MB / 8MB
- 上电时序：当前资料中未直接提取到完整时序，后续应结合原理图页和官方示例确认

## 4. 引脚映射
见 [pinmap.md](d:\dgx\code\esp32_skills_test\t-embed-cc1101\hardware\pinmap\pinmap.md)

## 5. 已确认的关键接口
- 共享 SPI 总线：
  - SCK = GPIO11
  - MOSI = GPIO9
  - MISO = GPIO10
- CC1101：
  - CS = GPIO12
  - GDO0 / IO0 = GPIO3
  - GDO2 / IO2 = GPIO38
  - SW0 = GPIO48
  - SW1 = GPIO47
- 显示：
  - BL = GPIO21
  - CS = GPIO41
  - DC = GPIO16
  - RST = GPIO40
- I2C：
  - SDA = GPIO8
  - SCL = GPIO18
- PN532：
  - IRQ = GPIO17
  - RF_REST = GPIO45
- 其他：
  - USER_KEY = GPIO6
  - ENCODER_A = GPIO4
  - ENCODER_B = GPIO5
  - ENCODER_KEY = GPIO0
  - WS2812 = GPIO14
  - SD_CS = GPIO13
  - IR_EN = GPIO2
  - IR_RX = GPIO1

## 6. 初始化要求
- USB 串口打印建议按官方 Arduino 设置开启 `USB CDC On Boot`
- 上传和调试建议按官方 Arduino 设置使用 `CDC and JTAG`
- CC1101、TF 卡、显示屏共享 SPI 资源，初始化顺序和片选管理必须严格分开
- 显示背光建议独立控制 `GPIO21`
- PN532 走 I2C，总线上同时存在：
  - `0x24` PN532
  - `0x55` BQ27220
  - `0x6B` BQ25896
- `PWR_EN`、`PN532_RF_REST`、`IR_EN` 的有效电平当前未从本地原理图文本层可靠提取，代码里先不要假定高低电平语义

## 7. 风险与限制
- 版本差异风险：
  - 你的本地原理图文件日期是 2024-07-29
  - 官方仓库当前标注的最新硬件版本是 v1.0-241103
  - 两者之间可能存在细节差异，尤其是引脚复用和外围器件
- 共享总线风险：
  - 显示、CC1101、TF 卡共享 SPI
  - 任何一个设备初始化失败，都要先排查 CS 管理和总线争用
- 引脚复用风险：
  - 官方 README 同时给出 `BOARD_VOICE_LRCLK = 40` 与 `DISPLAY_RST = 40`
  - 这意味着 GPIO40 可能存在复用或文档冲突，实机前必须回 schematic 逐页确认
- 启动脚风险：
  - `ENCODER_KEY = GPIO0`，这是 ESP32 常见启动相关脚位，代码和硬件交互时要避免影响启动模式
- 文档来源风险：
  - 当前第一版结论主要来自官方 README / Wiki 与本地 PDF 文件名
  - 由于本机缺少稳定 PDF 解析/OCR 工具，本地 PDF 正文还没有做到逐页交叉核对

## 8. 对软件实现的影响
- 推荐优先补的 examples：
  - `cc1101_smoke`
  - `cc1101_recv_irq`
  - `cc1101_send_irq`
  - `display_test`
  - `pn532_test`
- 建议沉淀到 `lib/demo_core` 的公共内容：
  - SPI 总线初始化
  - CC1101 引脚定义与中断包装
  - I2C 扫描和设备探测
  - 串口日志与超时等待
  - 背光和电源使能控制
- 代码里必须显式处理的超时：
  - CC1101 初始化超时
  - CC1101 IRQ 等待超时
  - PN532 I2C 响应超时
  - SD 卡挂载超时
  - 显示初始化和背光稳定延时

## 9. 板卡结论
- Arduino 首选板卡设置：`ESP32S3 Dev Module`
- PlatformIO 当前建议：
  - 先保留本地 `platformio.ini` 的 `board` 待确认
  - 如果后续要追求与官方工程一致，优先导入官方仓库 `boards/` 目录中的自定义板卡 JSON
  - 如果只是先做最小 bring-up，可尝试 `esp32-s3-devkitc-1`，但它不等于“完全等价”

## 10. 资料来源
- 本地原理图文件：`hardware/schematic/T-Embed-CC1101 V1.0 24-07-29.pdf`
- 官方 README：https://github.com/Xinyuan-LilyGO/T-Embed-CC1101
- 官方 Wiki：https://wiki.lilygo.cc/get_started/en/Wearable/T-Embed-CC1101/T-Embed-CC1101.html
