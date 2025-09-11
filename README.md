# <font size=3>一、工程介绍</font>




# <font size=3>二、nRF24L01使用规划</font>
<font size=2>在此次项目设计中，整板作为模拟人的遥控器，用于发送一些操作指令，诸如"开始"、"复位"、"竞赛模式"等，因此需要设置nRF24L01无线模块为发送模式，同时，在仪器开始指定项工作后，需要接收来自"模拟人"的设备数据，用于查看使用者的"按压力度"、"按压次数"等数据。因此，在不进行指令控制时，切换为接收模式，用于接收来自模拟人的数据。

在nRF24L01里，"多机通信≠以太网那种任意节点互发"，芯片硬件规则只有6条接收管道(pipe0 ~ pipe5)，且每条管道必须唯一匹配对方的发送地址。
因为，

</font>

<font size=3>详细关系图见下图：</font>
![流程图](./applications/macDoc/nRF24L01.svg)



## <font size=3>1. nRF24L01硬件连接说明</font>
<font size=2>nRF24L01采用SPI通讯方式进行控制，本项目基于RT-Thread SPI构架进行nRF24L01模组的参数配置，进而实现多设备的无线模组通信。

| MCU引脚  | nRF24L01引脚  | 配置说明 |
| ------------ | ------------ | ------------|
| PB3  | SCK   | 通过CubeMX配置挂载|
| PB4  | MISO  | 通过CubeMX配置挂载|
| PB5  | MOSI  | 通过CubeMX配置挂载|
| PA15 | CSN   | 配置为软件NSS，并使用```rt_hw_spi_device_attach```挂载到总线|
| PB10 | IRQ   | 配置为外部中断，上拉输入，下降沿触发中断|
| PB11 | CE    | 配置为普通GPIO模式|

</font>

## <font size=3>2. nRF24L01参数配置说明</font>

<font size=2>

| 寄存器 / 逻辑组 | 字段名（代码） | 本次取值 | 说明（作用与影响） |
|---|---|---|---|
| **CONFIG** | `prim_rx` | `ROLE_PTX` | 上电后默认为 **主发送模式** |
| | `pwr_up` | 1 | 直接进 Normal 模式 |
| | `crco`   | `CRC_2_BYTE` | CRC 长度 = 2 字节 |
| | `en_crc` | 1 | 硬件 CRC 校验使能 |
| | `mask_max_rt` | 0 | 重发超时不屏蔽 IRQ |
| | `mask_tx_ds` | 0 | 发送完成不屏蔽 IRQ |
| | `mask_rx_dr` | 0 | 接收完成不屏蔽 IRQ |
| **EN_AA** | `ENAA_P0` | 1 | pipe0 开启自动应答 |
| | `ENAA_P1` | 1 | pipe1 开启自动应答 |
| | `ENAA_P2` | 1 | pipe2 开启自动应答 |
| | `ENAA_P3` | 0 | pipe3 关闭自动应答 |
| | `ENAA_P4` | 0 | pipe4 关闭自动应答 |
| | `ENAA_P5` | 0 | pipe5 关闭自动应答 |
| **EN_RXADDR** | `EN_RXADDR_P0` | 1 | pipe0 使能接收 |
| | `EN_RXADDR_P1` | 1 | pipe1 使能接收 |
| | `EN_RXADDR_P2` | 1 | pipe2 使能接收 |
| | `EN_RXADDR_P3` | 0 | pipe3 失能接收 |
| | `EN_RXADDR_P4` | 0 | pipe4 失能接收 |
| | `EN_RXADDR_P5` | 0 | pipe5 失能接收 |
| **SETUP_AW** | `aw` | 3 | 地址宽度 = 5 字节 |
| **SETUP_RETR** | `arc` | 15 | 自动重发次数 = 15 次 |
| | `ard` | `ADR_2Mbps` | 重发间隔 250 µs |
| **RF_CH** | `rf_ch` | 100 | 载波频率 = 2400 + 100 = 2500 MHz |
| **RF_SETUP** | `rf_pwr` | `RF_POWER_0dBm` | 发射功率 0 dBm |
| | `rf_dr_low / high` | 0 / 0 | 数据率 = 1 Mbps |
| | `cont_wave` | 0 | 关闭连续载波测试 |
| **DYNPD** | `DYNPD_P0` | 1 | pipe0 开启动态载荷 |
| | `DYNPD_P1` | 1 | pipe1 开启动态载荷 |
| | `DYNPD_P2` | 1 | pipe2 开启动态载荷 |
| | `DYNPD_P3` | 0 | pipe3 关闭动态载荷 |
| | `DYNPD_P4` | 0 | pipe4 关闭动态载荷 |
| | `DYNPD_P5` | 0 | pipe5 关闭动态载荷 |
| **FEATURE** | `en_dpl` | 1 | 动态载荷总开关 |
| | `en_ack_pay` | 1 | 允许 ACK 带数据包 |
| | `en_dyn_ack` | 1 | 支持无 ACK 的数据发送 |
| **TX_ADDR** | `txaddr[5]` | `{0x55,0x0A,0x01,0x89,0x03}` | 本节点 **发送地址** |
| **RX_ADDR_P0** | `rx_addr_p0[5]` | `{0x55,0x0A,0x01,0x89,0x01}` | 与 TX_ADDR 配对，用于收 ACK |
| **RX_ADDR_P1** | `rx_addr_p1[5]` | `{0x55,0x0A,0x01,0x89,0x02}` | 多机通信时第 1 路接收地址 |
| **RX_ADDR_P2…P5** | 单字节 | 6,7,8,9 | 仅低字节可变，高 4 字节与 P1 相同 |

</font>


