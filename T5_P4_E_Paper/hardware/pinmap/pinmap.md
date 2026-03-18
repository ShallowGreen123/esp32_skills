# 引脚映射表

## 1. 核心控制与交互

| 功能 | 模块引脚/定义 | ESP32 GPIO | 方向 | 默认电平 | 备注 |
|------|---------------|------------|------|----------|------|
| 用户按键 | BOARD_USER_KEY | 6 | 输入 | 待确认 | 具体有效电平待回原理图确认 |
| 电源使能 | BOARD_PWR_EN | 15 | 输出 | 待确认 | 有效电平未确认，先不要写死 |
| 旋钮 A | ENCODER_INA | 4 | 输入 | 待确认 | 旋钮信号 |
| 旋钮 B | ENCODER_INB | 5 | 输入 | 待确认 | 旋钮信号 |
| 旋钮按键 / BOOT | ENCODER_KEY | 0 | 输入 | 待确认 | 启动相关脚，需谨慎使用 |

## 2. SPI 总线与 CC1101

| 功能 | 模块引脚/定义 | ESP32 GPIO | 方向 | 默认电平 | 备注 |
|------|---------------|------------|------|----------|------|
| SPI SCK | BOARD_SPI_SCK | 11 | 输出 | - | SPI 共享时钟 |
| SPI MOSI | BOARD_SPI_MOSI | 9 | 输出 | - | SPI 共享数据输出 |
| SPI MISO | BOARD_SPI_MISO | 10 | 输入 | - | SPI 共享数据输入 |
| CC1101 CS | BOARD_LORA_CS | 12 | 输出 | 高电平推定未选中 | 与显示、TF 卡共享 SPI 总线 |
| CC1101 GDO0 | BOARD_LORA_IO0 | 3 | 输入/中断 | 待确认 | 建议用于 IRQ 事件 |
| CC1101 GDO2 | BOARD_LORA_IO2 | 38 | 输入/中断 | 待确认 | 可用于状态或就绪信号 |
| CC1101 SW0 | BOARD_LORA_SW0 | 48 | 输出 | 待确认 | 射频开关控制，语义待结合原理图确认 |
| CC1101 SW1 | BOARD_LORA_SW1 | 47 | 输出 | 待确认 | 射频开关控制，语义待结合原理图确认 |

## 3. 显示

| 功能 | 模块引脚/定义 | ESP32 GPIO | 方向 | 默认电平 | 备注 |
|------|---------------|------------|------|----------|------|
| LCD 背光 | DISPLAY_BL | 21 | 输出 | 待确认 | 建议独立开关控制 |
| LCD CS | DISPLAY_CS | 41 | 输出 | 高电平推定未选中 | 与 SPI 总线复用 |
| LCD MOSI | DISPLAY_MOSI | 9 | 输出 | - | 与 SPI 总线复用 |
| LCD SCLK | DISPLAY_SCLK | 11 | 输出 | - | 与 SPI 总线复用 |
| LCD DC | DISPLAY_DC | 16 | 输出 | 待确认 | 数据/命令切换 |
| LCD RST | DISPLAY_RST | 40 | 输出 | 待确认 | 与语音接口存在文档层面的 GPIO 冲突，需二次确认 |

## 4. I2C 与 PN532 / 电源管理

| 功能 | 模块引脚/定义 | ESP32 GPIO | 方向 | 默认电平 | 备注 |
|------|---------------|------------|------|----------|------|
| I2C SDA | BOARD_I2C_SDA | 8 | 双向 | 上拉推定 | I2C 共享数据 |
| I2C SCL | BOARD_I2C_SCL | 18 | 输出 | 上拉推定 | I2C 共享时钟 |
| PN532 IRQ | BOARD_PN532_IRQ | 17 | 输入/中断 | 待确认 | NFC 中断 |
| PN532 RF_REST | BOARD_PN532_RF_REST | 45 | 输出 | 待确认 | NFC 复位 |
| PN532 地址 | BOARD_I2C_ADDR_1 | 0x24 | - | - | I2C 设备地址 |
| BQ27220 地址 | BOARD_I2C_ADDR_2 | 0x55 | - | - | 电量计 |
| BQ25896 地址 | BOARD_I2C_ADDR_3 | 0x6B | - | - | 充电管理 |

## 5. 其他外设

| 功能 | 模块引脚/定义 | ESP32 GPIO | 方向 | 默认电平 | 备注 |
|------|---------------|------------|------|----------|------|
| TF 卡 CS | BOARD_SD_CS | 13 | 输出 | 高电平推定未选中 | 与 SPI 总线复用 |
| WS2812 数据 | WS2812_DATA_PIN | 14 | 输出 | 低电平常见 | 8 颗 RGB LED |
| 红外使能 | BOARD_IR_EN | 2 | 输出 | 待确认 | 有效电平待确认 |
| 红外接收 | BOARD_IR_RX | 1 | 输入 | 待确认 | IR 接收输入 |
| 麦克风数据 | BOARD_MIC_DATA | 42 | 输入 | - | 音频输入 |
| 麦克风时钟 | BOARD_MIC_CLK | 39 | 输出 | - | 音频输入时钟 |
| 扬声器 BCLK | BOARD_VOICE_BCLK | 46 | 输出 | - | 音频输出 |
| 扬声器 LRCLK | BOARD_VOICE_LRCLK | 40 | 输出 | - | 与 DISPLAY_RST 同为 GPIO40，需重点核对 |
| 扬声器 DIN | BOARD_VOICE_DIN | 7 | 输出 | - | 音频数据输出 |

## 6. 当前结论

- 已确认：CC1101、显示、PN532、TF 卡共用或部分共用主板资源的整体关系已经清楚
- 待确认：
  - `PWR_EN`、`IR_EN`、`PN532_RF_REST` 的有效电平
  - `CC1101 SW0/SW1` 的具体射频通道语义
  - `GPIO40` 是否确实同时连到 `DISPLAY_RST` 和 `VOICE_LRCLK`
- 建议下一步：
  - 优先读本地原理图中与 `GPIO40 / GPIO47 / GPIO48 / GPIO15` 相关的页面
  - 再决定 `cc1101_recv_irq` 和 `cc1101_send_irq` 的初始化顺序
