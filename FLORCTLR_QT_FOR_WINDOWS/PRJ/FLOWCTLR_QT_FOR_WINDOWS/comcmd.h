#ifndef COMCMD
#define COMCMD



// 输入系列命令以0开始
#define						CMD_CYC_CURRSPEED							0x01
#define						CMD_CYC_CODE								0x02
#define						CMD_CYC_RUNTIME							0x03
#define						CMD_CYC_WORKFLAG							0x04
#define						CMD_CYC_CYCNUM								0x05
#define						CMD_CYC_HASINJECTVALUE					0x1C


#define						CMD_SIN_CURRSPEED							0x06
#define						CMD_SIN_CODE								0x07
#define						CMD_SIN_RUNTIME							0x08
#define						CMD_SIN_WORKFLAG							0x09
#define						CMD_SIN_STATE								0x0a
#define						CMD_SIN_HASINJECTVALUE					0x0b


// 输出系列命令以1开始
#define						CMD_CYC_INSIZE								0x10
#define						CMD_CYC_SPEED_ON							0x11
#define						CMD_CYC_SPEED_OFF							0x12
#define						CMD_CYC_CYCNUMX							0x13
#define						CMD_CYC_RUNTIMEX							0x14
#define						CMD_CYC_CODEX								0x15

#define						CMD_SIN_INSIZE								0x1B
#define						CMD_SIN_SPEED_ON							0x16
#define						CMD_SIN_SPEED_OFF							0x17
#define						CMD_SIN_CTRLMODE							0x18
#define						CMD_SIN_RUNTIMEX							0x19
#define						CMD_SIN_CODEX								0x1A

// 按钮命令
#define						CMD_CYC_RUN								0x20
#define						CMD_CYC_STOP								0x21
#define						CMD_CYC_HALT								0x22

#define						CMD_SIN_RUN								0x23
#define						CMD_SIN_STOP								0x24
#define						CMD_SIN_HALT								0x25

#define						CMD_SIN_STARTEXTRACT						0x26


// 全局命令
#define						CMD_ALL_SETLINK							0xf0
#define						CMD_ALL_DISLINK							0xf1
#define						CMD_ALL_GETTEMP							0xf2
#define						CMD_ALL_SETTEMP							0xf3
#define						CMD_ALL_ADDTEMP							0xf4
#define						CMD_ALL_DECTEMP							0xf5
#define						CMD_ALL_TVALUE								0xF6


// 注射器标识
#define						FLAG_DEVICE_1								0x30
#define						FLAG_DEVICE_2								0x31
#define						FLAG_DEVICE_3								0x32
#define						FLAG_DEVICE_4								0x33

// 子命令
#define						SCMD_SIN_CTRLMODE_PIDMODE				0x40
#define						SCMD_SIN_CTRLMODE_AVRMODE				0x41
#define						SCMD_SIN_INSIZE_10ML						0x42
#define						SCMD_SIN_INSIZE_20ML						0x43
#define						SCMD_SIN_INSIZE_30ML						0x44

#define						SCMD_SIN_WORKSTATE_EXTRACT				0x45
#define						SCMD_SIN_WORKSTATE_REALSE				0x46
#define						SCMD_SIN_WORKSTATE_PAUSE					0x47
#define						SCMD_SIN_WORKSTATE_STOP					0x48
#define						SCMD_SIN_WORKSTATE_OFFLINE				0x49
#define						SCMD_SIN_WORKSTATE_STANDBY				0x4A

#define						SCMD_CYC_WORKSTATE_WORDING				0x4B
#define						SCMD_CYC_WORKSTATE_PAUSE					0x4C
#define						SCMD_CYC_WORKSTATE_STOP					0x4D
#define						SCMD_CYC_WORKSTATE_OFFLINE				0x4E

#define						UNIT_MLPH									0
#define						UNIT_LPH									1
#define						UNIT_MLPM									2
#define						UNIT_LPM									3


#define    					CMD_DATA_HEAD_0     						0xAA
#define     				CMD_DATA_HEAD_1    						0xBB

#define						DEVICE_ANDROID								0x0001
#define						DEVICE_WINDOWS								0x0002

#endif // COMCMD

