~~~
开机 / USB插入
  -> BQ25896 恢复充电路径
     resetDefault
     -> exitHizMode
     -> disableOTG
     -> enableBatterPowerPath
     -> 配置 IINLIM / VREG / IPRECHG / ITERM / ICHG
     -> enableCharge
  -> BQ27220 初始化
     读ID
     -> unseal
     -> 检查 INITCOMP / CFGUPDATE / profile / DataMemory
     -> 必要时 reset + 重写模型
     -> seal

运行中
  -> USB未插入
     BQ25896: No input
     BQ27220: Discharge / Relaxation
  -> USB已插入但电流未真正进电池
     BQ25896: Not Charging
     BQ27220: Relaxation 或仍是负电流
  -> 预充阶段
     BQ25896: Pre-charge
     BQ27220: AverageCurrent 转正
  -> 快充阶段
     BQ25896: Fast Charging
     BQ27220: Charging
  -> 充满
     BQ25896: Charge Termination Done
     BQ27220: FC / TCA / Finish
  -> 低电压保护
     UI倒计时
     -> PPM.shutdown()
     -> BATFET关闭
     -> 之后必须走一次“恢复充电路径”
~~~


